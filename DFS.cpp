/*
 * DFS.cpp
 *
 */

#include "DFS.h"

DFS::DFS(Graph &graph) {
	this->graph = graph;
}

VertexHashTable DFS::perform(const unsigned &originId) {
	visitedVertices.clear();

	visitVertex(originId);

	return visitedVertices;
}

void DFS::visitVertex(const unsigned &vertexId) {

	Vertex current = graph.getVertex(vertexId);

	if(visitedVertices.find(current) == visitedVertices.end())
		visitedVertices.insert( graph.getVertex(vertexId) );

	for(Edge edge : current.getEdges()) {
		unsigned destinyId = edge.getDestinyId();
		if(!wasVisited(destinyId)) {
			visitVertex(destinyId);
		}
	}
}

bool DFS::isPossible(const unsigned &originId, const unsigned &destinyId) {

	VertexHashTable reachable = perform(originId);

	Vertex destiny = graph.getVertex(destinyId);

	if(reachable.find(destiny) != reachable.end())
		return true;

	return false;
}

vector<int> DFS::isPossible(const unsigned &originId, const vector<int> &destinyIds) {

	VertexHashTable reachable = perform(originId);

	vector<int> unreachable;

	for(int destinyId : destinyIds) {
		Vertex destiny = graph.getVertex(destinyId);

		if(reachable.find(destiny) == reachable.end())
			unreachable.push_back(destinyId);
	}

	return unreachable;
}

bool DFS::wasVisited(unsigned id) {
	return visitedVertices.find(graph.getVertex(id)) != visitedVertices.end();
}



