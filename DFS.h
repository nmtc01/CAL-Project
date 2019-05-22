/*
 * DFS.h
 *
 *  Created on: 22/05/2019
 *      Author: Nuno Cardoso
 */

#pragma once

#include <unordered_set>
#include "Graph.h"

using namespace std;

class DFS {
	VertexHashTable visitedVertexes;
	Graph graph;

public:
	DFS(Graph &graph);
	void perform(const unsigned &originId);
	void visitVertex(const unsigned &vertexId);
	void isPossible(const unsigned &originId, const unsigned &destinyId);

};
