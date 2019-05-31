/*
 * BranchAndBound.h
 *
 *  Created on: 26/05/2019
 *      Author: Nuno Cardoso
 */

#pragma once
#include <ctime>
#include "Graph.h"
#include "FloydWarshall.h"
#include "NearestNeighbour.h"

#define TIME_LIMIT 30

class BranchAndBound {
	clock_t initial_time;
	Graph graph;
	FloydWarshall fw;
	VertexHashTable visitedVertices;
	double bound;
	vector<unsigned> path;
	bool performed;
	void recursion(unsigned start, unsigned garage, vector<unsigned> addresses, double distanceUntilNow, vector<unsigned> pathUntilNow);
	double Prim(vector<unsigned> addresses);
public:

	BranchAndBound(Graph graph, FloydWarshall fw);
	~BranchAndBound();
	void perform(unsigned school, unsigned garage, vector<unsigned> addresses);
	void printPath();
	vector<unsigned> getPath();
	double getDistance();

};





