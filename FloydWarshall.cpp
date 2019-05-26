/*
 * FloydWarshall.cpp
 *
 */

#include "FloydWarshall.h"

FloydWarshall::FloydWarshall() {
	performed = false;
}

FloydWarshall::FloydWarshall(const Graph &graph) : graph(graph) {
	performed = false;
}


void FloydWarshall::perform() {
	unsigned size = graph.getNumVertex();

	//resets the matrixes
	deleteMatrix(distances, size);
	deleteMatrix(paths, size);

	distances = new double *[size];
	paths = new unsigned *[size];

	for(unsigned i = 0; i < size; i++) {
		distances[i] = new double[size];
		paths[i] = new unsigned[size];

		for(unsigned j = 0; j < size; j++) {
			distances[i][j] = i == j? 0 : INF;
			paths[i][j] = -1;
		}
		for(Edge edge : graph.getVertex(i).getEdges()) {
			unsigned j = edge.getDestinyId();
			distances[i][j] = edge.getWeight();
			paths[i][j] = i;
		}
	}

	for(unsigned k = 0; k < size; k++) {
		for(unsigned i = 0; i < size; i++) {
			for(unsigned j = 0; j < size; j++) {

				if(distances[i][k] == INF || distances[k][j] == INF)
					continue;

				double value = distances[i][k] + distances[k][j];
				if(value < distances[i][j]) {
					distances[i][j] = value;
					paths[i][j] = paths[k][j];
				}
			}
		}
	}

	performed = true;
}


//Only called after perform!
vector<unsigned> FloydWarshall::getPath(unsigned sourceId, unsigned destinyId) const {
	vector<unsigned> path;
	unsigned i = sourceId;
	unsigned j = destinyId;

	if(i == -1 || j == -1 || distances[i][j] == INF || !performed)
		return path;

	for( ; j != -1 ; j = paths[i][j])
		path.push_back(j);

	reverse(path.begin(), path.end());

	return path;
}

double FloydWarshall::getDistance(unsigned sourceId, unsigned destinyId) const {
	unsigned i = sourceId;
	unsigned j = destinyId;

	if(i == -1 || j == -1 || distances[i][j] == INF || !performed)
		return INF;
	else return distances[i][j];

}
bool FloydWarshall::alreadyPerformed() {
	return performed;
}


