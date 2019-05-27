/*
 * NearestNeighbour.h
 *
 */

#pragma once

#include "FloydWarshall.h"
#include "Graph.h"


class NearestNeighbour {
//	Network network;
	AbstractPathCalculator *APC;
	Graph graph;
	vector<bool> visited;
	double distance;
	vector<unsigned> path;
	bool performed;

public:
	NearestNeighbour(Graph graph, AbstractPathCalculator *apc);

	void perform(unsigned school, unsigned garage, vector<unsigned> addresses, AbstractPathCalculator *apc);

	double getDistance();
	vector<unsigned> getPath();
	void printPath();

	virtual ~NearestNeighbour();
};

