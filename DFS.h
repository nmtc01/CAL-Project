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
	VertexHashTable possibleVertexes;
	Graph graph;

public:
	DFS(Graph &graph);
	void perform(Vertex origin);
	void visitNodes(Vertex origin);

};
