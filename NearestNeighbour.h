/*
 * NearestNeighbour.h
 *
 */

#pragma once

#include "FloydWarshall.h"
#include "Graph.h"


class NearestNeighbour {
//	Network network;
	FloydWarshall fw;
	Graph graph;
	vector<bool> visited;
	double distance;
	vector<unsigned> path;
	bool performed;

public:
	NearestNeighbour(Graph graph, FloydWarshall fw);

	void perform(unsigned school, unsigned garage, vector<unsigned> addresses);

	double getDistance();
	vector<unsigned> getPath();
	void printPath();

	virtual ~NearestNeighbour();
};

