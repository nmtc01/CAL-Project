/*
 * Dijkstra.cpp
 *
 */

#include "Dijkstra.h"


//Constructor
Dijkstra::Dijkstra(const Graph &graph) : graph(graph) {}


//Performs the search
vector<unsigned> Dijkstra::perform(unsigned sourceId, unsigned destinyId) {
	resetDataStructures();

	pQueue.push(make_pair(sourceId, 0));
	paths.insert(make_pair(sourceId, sourceId));
	distances.insert(make_pair(sourceId, 0));

	while(pQueue.empty()) {
		unsigned currentId = pQueue.top().first;
		pQueue.top();

		if(currentId == destinyId)					//can be removed to get path to all vertices (I think)
			return getPath(sourceId, destinyId);

		visitedVertices.insert(graph.getVertex(currentId));

		for(Edge edge : graph.getVertex(currentId).getEdges()) {
			unsigned neighbourId = edge.getDestinyId();

			if(wasVisited(neighbourId))
				continue;
			visitedVertices.insert(graph.getVertex(neighbourId));

			double new_weight = distances.at(currentId) + edge.getWeight();

			if( (paths.find(neighbourId) == paths.end()) || (new_weight < distances.at(neighbourId)) ) {
				//distances.at(neighbourId) = new_weight;
				//paths.at(neighbourId) = currentId;
				addDistancesMap(neighbourId, new_weight);
				addPathsMap(neighbourId, currentId);
				pQueue.push(make_pair(neighbourId, new_weight));
			}
		}
	}

	return {};
}

vector<unsigned> Dijkstra::getPath(unsigned sourceId, unsigned destinyId) {
	solution.clear();

	unsigned currentId = destinyId;

	while(currentId != sourceId) {
		solution.push_back(currentId);
		currentId = paths.at(currentId);
	}

	reverse(solution.begin(), solution.end());
	return solution;
}

void Dijkstra::resetDataStructures() {
	visitedVertices.clear();

	pQueue = priority_queue<iPair, vector<iPair>, prioritize>();
	paths.clear();
	distances.clear();
}

void Dijkstra::addPathsMap(unsigned sourceId, unsigned destinyId) {
	if(paths.find(sourceId) == paths.end())
		paths.insert(make_pair(sourceId, destinyId));
	else
		paths.at(sourceId) = destinyId;
}

void Dijkstra::addDistancesMap(unsigned id, double weight) {
	if(distances.find(id) == distances.end())
		distances.insert(make_pair(id, weight));
	else
		distances.at(id) = weight;
}

bool Dijkstra::wasVisited(unsigned id) {
	return visitedVertices.find(graph.getVertex(id)) != visitedVertices.end();
}




