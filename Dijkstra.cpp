/*
 * Dijkstra.cpp
 *
 */

#include "Dijkstra.h"


//Constructor
Dijkstra::Dijkstra() {}
Dijkstra::Dijkstra(const Graph &graph) : graph(graph) {}


//Performs the search
vector<unsigned> Dijkstra::perform(unsigned sourceId, unsigned destinyId) {
	resetDataStructures();

	pQueue.push(make_pair(sourceId, 0));
	paths.at(sourceId) = sourceId;
	distances.at(sourceId) = 0;

	while(pQueue.empty()) {
		unsigned currentId = pQueue.top().first;
		pQueue.top();

		if(currentId == destinyId)					//can be removed to get path to all vertices (I think)
			return getPath(sourceId, destinyId);

		visitedVertices.insert(graph.getVertex(currentId));

		for(Edge edge : graph.getVertex(currentId).getEdges()) {
			unsigned neighbourId = edge.getDestinyId();

			if(visitedVertices.find(graph.getVertex(neighbourId)) != visitedVertices.end())
				continue;
			visitedVertices.insert(graph.getVertex(neighbourId));

			double new_weight = distances.at(currentId) + edge.getWeight();

			if( (paths.find(neighbourId) == paths.end()) || (new_weight < distances.at(neighbourId)) ) {
				distances.at(neighbourId) = new_weight;
				paths.at(neighbourId) = currentId;
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
	//idsQueue = priority_queue<unsigned, vector<unsigned>, std::greater<unsigned>>();
	pQueue = priority_queue<iPair, vector<iPair>, prioritize>();
	paths.clear();
	distances.clear();
}
