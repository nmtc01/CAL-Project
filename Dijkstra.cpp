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

	idsQueue.push(sourceId);
	paths.at(sourceId) = sourceId;
	distances.at(sourceId) = 0;

	while(!idsQueue.empty()) {
		unsigned currentId = idsQueue.top();
		idsQueue.pop();

		if(currentId == destinyId)
			return getPath(sourceId, destinyId);

		visitedVertices.insert(graph.getVertex(currentId));

		for(Edge edge : graph.getVertex(currentId).getEdges()) {
			unsigned neighbourId = edge.getDestinyId();

			if(visitedVertices.find(graph.getVertex(neighbourId)) != visitedVertices.end())
				continue;

			double new_weight = distances.at(currentId) + edge.getWeight();

			if( (paths.find(neighbourId) == paths.end()) || (new_weight < distances.at(neighbourId)) ) {
				distances.at(neighbourId) = new_weight;
				paths.at(neighbourId) = currentId;
				//idsQueue.push(neighbourId, new_weight);
				idsQueue.push(neighbourId);		// ----> provavelmente errado (talvez tenha de mudar a priority queue)
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
	idsQueue = priority_queue<unsigned, vector<unsigned>, std::greater<unsigned>>();
	paths.clear();
	distances.clear();
}
