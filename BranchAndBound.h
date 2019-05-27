/*
 * BranchAndBound.h
 *
 *  Created on: 26/05/2019
 *      Author: Nuno Cardoso
 */

#pragma once

#include "Graph.h"
#include <utility>

typedef vector<vector<double>> matrix;

class BranchAndBound {
private:
	Graph graph;
	VertexHashTable visitedVertices;
	matrix weightMatrix;
	vector<double> costs;
	double upperBound = INF;
	double lowerBound = 0;

public:
	BranchAndBound(Graph graph, double upperBound, double lowerBound);
	void initializeMatrix();
	double findMinLine(matrix weights, int line);
	double findMinCol(matrix weights, int col);
	double reduceMatrixLine(matrix &weights, int line);
	double reduceMatrixCol(matrix &weights, int col);
	double reduceMatrix(matrix &weights);
	void visitVertex(const unsigned &originId, matrix weights, double originCost);
	VertexHashTable perform(const unsigned &originId);
	pair<double,matrix> calculateCostAndMatrix(Edge edge, matrix weights, double originCost);
	bool existsSmaller(double &min);
};






