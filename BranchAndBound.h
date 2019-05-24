/*
 * BranchAndBound.h
 *
 *  Created on: 24 de mai de 2019
 *      Author: Estudio
 */

#pragma once
#include "Graph.h"
#include "FloydWarshall.h"

class BranchAndBound {

	Graph graph;
	FloydWarshall fw;
	VertexHashTable visitedVertices;
	double distance;
	vector<unsigned> path;
	bool performed;
	//vector<unsigned> recursion(unsigned currentIndex, vector<bool> visited, double distanceUntilNow);
	// adicionar private function para minimum spanning tree
public:

	BranchAndBound(Graph graph, vector<unsigned> initialPath, double initialDistance);
	virtual ~BranchAndBound();
	void perform();
};
