/*
 * DFS.cpp
 *
 *  Created on: 22/05/2019
 *      Author: Nuno Cardoso
 */

#include "DFS.h"

DFS::DFS(Graph &graph) {
	this->graph = graph;
}

void DFS::perform(const unsigned &originId) {
	visitedVertexes.clear();

	visitedVertexes.insert( graph.getVertex(originId) );
	visitVertex(originId);
}

void DFS::visitVertex(const unsigned &vertexId) {

}

void DFS::isPossible(const unsigned &originId, const unsigned &vertexId) {

}



