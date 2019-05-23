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
	//Constructor
	DFS(Graph &graph);

	//Explores all reachable vertexes from origin
	VertexHashTable perform(const unsigned &originId);

	//Helpful function for perform
	void visitVertex(const unsigned &vertexId);

	//Checks if a path between two vertexes is possible
	bool isPossible(const unsigned &originId, const unsigned &destinyId);

	//Checks if a path multiple vertexes, starting from an origin vertex is possible (returns the unreachable vertexes' ids)
	vector<int> isPossible(const unsigned &originId, const vector<int> &destinyIds);
};
