/*
 * BFS.h
 *
 *  Created on: 23/05/2019
 *      Author: Nuno Cardoso
 */

#pragma once

#include <unordered_set>
#include "Graph.h"

using namespace std;

class BFS {
	VertexHashTable visitedVertices;
	Graph graph;

public:
	//Constructor
	BFS(Graph &graph);

	//Explores all reachable vertexes from origin
	VertexHashTable perform(const unsigned &originId);

	//Helpful function for perform
	void visitVertex(const unsigned &vertexId);
};




