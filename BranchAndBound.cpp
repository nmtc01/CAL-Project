/*
 * BranchAndBound.c
 *
 *  Created on: 26/05/2019
 *      Author: Nuno Cardoso
 */

#include "BranchAndBound.h"

BranchAndBound::BranchAndBound(Graph graph, double upperBound, double lowerBound) {
	this->graph = graph;
	this->upperBound = upperBound;
	this->lowerBound = lowerBound;
}

void BranchAndBound::initializeMatrix() {
	vector<Vertex> nodes = graph.getVertexSet();
	vector<double> weights;

	for (unsigned i = 0; i < nodes.size(); i++) {
		weights.push_back(INF);
	}

	for (unsigned i = 0; i < nodes.size(); i++) {
		weightMatrix.push_back(weights);
	}

	for (unsigned i = 0; i < nodes.size(); i++) {
		vector<Edge> edges = nodes.at(i).getEdges();
		for (unsigned j = 0; j < edges.size(); j++) {
			weights.at(edges.at(j).getDestinyId()) = edges.at(j).getWeight();
		}
		weightMatrix.at(nodes.at(i).getId()) = (weights);
	}
}

double BranchAndBound::findMinLine(matrix weights, int line) {
	double min = weights[line][0];
	for (int i = 0; i < weights[line].size(); i++) {
		if (weights[line][i] < min)
			min = weights[line][i];
	}

	return min;
}

double BranchAndBound::findMinCol(matrix weights, int col) {
	double min = weights[0][col];
	for (unsigned i = 0; i < weights.size(); i++) {
		if (weights[i][col] < min)
			min = weights[i][col];
	}

	return min;
}

void BranchAndBound::reduceMatrixLine(matrix &weights, int line) {
	double min = findMinLine(weights, line);
	for (unsigned i = 0; i < weights[line].size(); i++) {
		if (weights[line][i] != INF)
			weights[line][i] -= min;
	}
	lowerBound += min;
}

void BranchAndBound::reduceMatrixCol(matrix &weights, int col) {
	double min = findMinCol(weights, col);
	for (unsigned i = 0; i < weights.size(); i++) {
		if (weights[i][col] != INF)
			weights[i][col] -= min;
	}
	lowerBound += min;
}

void BranchAndBound::reduceMatrix(matrix &weights) {
	for (unsigned i = 0; i < weights.size(); i++) {
		reduceMatrixLine(weights, i);
	}
	for (unsigned i = 0; i < weights[0].size(); i++) {
		reduceMatrixCol(weights, i);
	}
}

void BranchAndBound::visitVertex() {

}

VertexHashTable BranchAndBound::perform(const unsigned &originId) {
	visitedVertices.clear();

	Vertex origin = graph.getVertex(originId);

	initializeMatrix();

	reduceMatrix(weightMatrix);

	visitVertex();
}




