/*
 * BFS.cpp
 *
 *  Created on: 23/05/2019
 *      Author: Nuno Cardoso
 */

#include "BFS.h"

BFS::BFS(Graph &graph) {
	this->graph = graph;
}

VertexHashTable BFS::perform(const unsigned &originId) {
	visitedVertices.clear();

	visitVertex(originId);

	return visitedVertices;
}

void BFS::visitVertex(const unsigned &vertexId) {
	queue<Vertex> Q;
	Vertex s = graph.getVertex(vertexId);

	Q.push(s);

	if(visitedVertices.find(s) == visitedVertices.end())
		visitedVertices.insert(graph.getVertex(vertexId));

	while(!Q.empty()) {
		Vertex v = Q.front();
		Q.pop();
		for(unsigned int i = 0; i < v.getEdges().size(); i++) {
			Vertex w = graph.getVertex(v.getEdges()[i].getDestinyId());
			if (visitedVertices.find(w) == visitedVertices.end()) {
				Q.push(w);
				visitedVertices.insert(w);
			}
		}
	}
}



