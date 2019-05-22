/*
 * Graph.h
 *
 */

#pragma once

#include <stdlib.h>
#include <iostream>
#include <limits>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <fstream>
#include <math.h>

#include "Vertex.h"

#define INF std::numeric_limits<double>::max()


class Graph {
	vector<Vertex> vertexSet;

public:
	//Constructors
	Graph();
	Graph(string nodes_filename, string edges_filename, string tags_filename);

	//Useful methods
	void addVertex(double x, double y);
	bool addEdge(unsigned first_id, unsigned sec_id, const double &weight);
	unsigned getVertexIndex(unsigned id);
	int getNumVertex() const;

	//Get methods
	vector<Vertex> getVertexSet();
};
