/*
 * BranchAndBound.h
 *
 *  Created on: 26/05/2019
 *      Author: Nuno Cardoso
 */

#pragma once

#include "Graph.h"

typedef vector<vector<double>> matrix;

class BranchAndBound {

	Graph graph;
	VertexHashTable visitedVertices;
	matrix weightMatrix;
	double upperBound;

public:
	BranchAndBound(Graph graph, double upperBound);
	void initializeMatrix();
	double findMinLine();
	double findMinCol();
	void reduceMatrixLine();
	void reduceMatrixCol();
	VertexHashTable perform(const unsigned &originId);

};






