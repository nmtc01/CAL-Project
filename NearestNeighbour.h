/*
 * NearestNeighbour.h
 *
 */

#pragma once

#include "MultipleDijkstra.h"
#include "FloydWarshall.h"
#include "Graph.h"


class NearestNeighbour {
	FloydWarshall fw;
	MultipleDijkstra dij;
	Graph graph;
	vector<bool> visited;
	double distance;
	vector<double> distances;
	vector<unsigned> path;
	vector<unsigned> complete_path;
	vector<vector<unsigned>> paths;
	bool performed;
	bool withFW;
	void performWithFW(unsigned school, unsigned garage, vector<unsigned> addresses, unsigned capacity = NOT_FOUND);
	void performWithDij(unsigned school, unsigned garage, vector<unsigned> addresses);

public:
	NearestNeighbour();
	NearestNeighbour(Graph graph, FloydWarshall fw);
	NearestNeighbour(Graph graph, MultipleDijkstra dij);

	void perform(unsigned school, unsigned garage, vector<unsigned> addresses, unsigned capacity = NOT_FOUND);
	double getDistance();
	vector<unsigned> getPath();
	vector<unsigned> getCompletePath();
	void printPath();
	void printPaths();

	virtual ~NearestNeighbour();
};

