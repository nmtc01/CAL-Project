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
private:
	Graph graph;
	VertexHashTable visitedVertices;
	matrix weightMatrix;
	double upperBound = INF;
	double lowerBound = 0;

public:
	BranchAndBound(Graph graph, double upperBound, double lowerBound);
	void initializeMatrix();
	double findMinLine(matrix weights, int line);
	double findMinCol(matrix weights, int col);
	void reduceMatrixLine(matrix &weights, int line);
	void reduceMatrixCol(matrix &weights, int col);
	void reduceMatrix(matrix &weights);
	void visitVertex();
	VertexHashTable perform(const unsigned &originId);
};






