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
	visitedVertexes.clear();

	visitVertex(originId);

	return visitedVertexes;
}

void BFS::visitVertex(const unsigned &vertexId) {
	queue<Vertex> Q;
	Vertex s = graph.getVertex(vertexId);

	Q.push(s);

	if(visitedVertexes.find(s) == visitedVertexes.end())
		visitedVertexes.insert(graph.getVertex(vertexId));

	while(!Q.empty()) {
		Vertex v = Q.front();
		Q.pop();
		for(unsigned int i = 0; i < v.getEdges().size(); i++) {
			Vertex w = graph.getVertex(v.getEdges()[i].getDestinyId());
			if (visitedVertexes.find(w) == visitedVertexes.end()) {
				Q.push(w);
				visitedVertexes.insert(w);
			}
		}
	}
}



