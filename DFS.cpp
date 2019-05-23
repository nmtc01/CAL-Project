/*
 * DFS.cpp
 *
 */

#include "DFS.h"

DFS::DFS(Graph &graph) {
	this->graph = graph;
}

VertexHashTable DFS::perform(const unsigned &originId) {
	visitedVertexes.clear();

	visitVertex(originId);

	return visitedVertexes;
}

void DFS::visitVertex(const unsigned &vertexId) {

	Vertex current = graph.getVertex(vertexId);

	if(visitedVertexes.find(current) == visitedVertexes.end())
		visitedVertexes.insert( graph.getVertex(vertexId) );

	for(Edge edge : current.getEdges())
		visitVertex(edge.getDestinyId());
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




