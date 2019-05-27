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
		weightMatrix.at(nodes.at(i).getId()) = weights;
	}
}

double BranchAndBound::findMinLine(matrix weights, int line) {
	double min = weights[line][0];
	for (unsigned i = 0; i < weights[line].size(); i++) {
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

double BranchAndBound::reduceMatrixLine(matrix &weights, int line) {
	double min = findMinLine(weights, line);
	for (unsigned i = 0; i < weights[line].size(); i++) {
		if (weights[line][i] != INF)
			weights[line][i] -= min;
	}

	return min;
}

double BranchAndBound::reduceMatrixCol(matrix &weights, int col) {
	double min = findMinCol(weights, col);
	for (unsigned i = 0; i < weights.size(); i++) {
		if (weights[i][col] != INF)
			weights[i][col] -= min;
	}
	return min;
}

double BranchAndBound::reduceMatrix(matrix &weights) {
	double reduction;
	for (unsigned i = 0; i < weights.size(); i++) {
		reduction += reduceMatrixLine(weights, i);
	}
	for (unsigned i = 0; i < weights[0].size(); i++) {
		reduction += reduceMatrixCol(weights, i);
	}

	return reduction;
}

pair<double,matrix> BranchAndBound::calculateCostAndMatrix(Edge edge, matrix weights, double originCost) {
	double cost = originCost + weights[edge.getSourceId()][edge.getDestinyId()];

	for (unsigned i = 0; i < weights[edge.getSourceId()].size(); i++) {
		weights[edge.getSourceId()][i] = INF;
		weights[i][edge.getDestinyId()] = INF;
	}

	weights[edge.getDestinyId()][edge.getSourceId()] = INF;

	cost += reduceMatrix(weights);

	return make_pair(cost, weights);
}

bool BranchAndBound::existsSmaller(double &min) {
	for (unsigned i = 0; i < costs.size(); i++)
		if (costs[i] < min)
			return true;
	return false;
}

VertexHashTable BranchAndBound::visitVertex(const unsigned &originId, matrix weights, double originCost, VertexHashTable path) {
	Vertex origin = graph.getVertex(originId);

	bool getOut = true;
	for (unsigned i = 0; i < origin.getEdges().size(); i++) {
		if (path.find(graph.getVertex(origin.getEdges()[i].getDestinyId())) == path.end())
			getOut = false;
	}
	if (getOut) {
		visitedVertices = path;
		return path;
	}

	vector<pair<double,matrix>> pathsCostAndMatrix;
	double minCost = INF;
	unsigned minIndex = 0;

	for (unsigned i = 0; i < origin.getEdges().size(); i++){
		if (path.find(graph.getVertex(origin.getEdges()[i].getDestinyId())) != path.end())
			continue;
		pathsCostAndMatrix.push_back(calculateCostAndMatrix(origin.getEdges()[i], weights, originCost));
		if (pathsCostAndMatrix[i].first < minCost) {
			minCost = pathsCostAndMatrix[i].first;
			minIndex = i;
		}
	}
	costs.push_back(minCost);

	if (!existsSmaller(minCost)) {
		path.insert(graph.getVertex(origin.getEdges()[minIndex].getDestinyId()));
		visitVertex(origin.getEdges()[minIndex].getDestinyId(), pathsCostAndMatrix[minIndex].second, minCost, path);
	}
	else return path;

	minCost = INF;
	for (unsigned int i = 0; i < origin.getEdges().size(); i++) {
		if (i == minIndex || path.find(graph.getVertex(origin.getEdges()[i].getDestinyId())) != path.end())
			continue;
		if (pathsCostAndMatrix[i].first < minCost) {
			minCost = pathsCostAndMatrix[i].first;
			minIndex = i;
		}
	}
	costs.push_back(minCost);
	visitVertex(origin.getEdges()[minIndex].getDestinyId(), pathsCostAndMatrix[minIndex].second, minCost, path);

	return path;
}

VertexHashTable BranchAndBound::perform(const unsigned &originId) {
	visitedVertices.clear();

	initializeMatrix();

	lowerBound = reduceMatrix(weightMatrix);

	VertexHashTable path;
	path.clear();
	visitVertex(originId, weightMatrix, lowerBound, path);

	return visitedVertices;
}




