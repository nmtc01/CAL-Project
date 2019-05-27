/*
 * Graph.h
 *
 */

#pragma once

#include <stdlib.h>
#include <iostream>
#include <limits>
#include <algorithm>
#include <map>
#include <fstream>
#include <math.h>

#include "Vertex.h"

#define INF std::numeric_limits<double>::max()
#define NOT_FOUND std::numeric_limits<unsigned>::max()


class Graph {
	vector<Vertex> vertexSet;
	unsigned numEdges;

public:
	//Constructors
	Graph();
	Graph(string nodes_filename, string edges_filename, string tags_filename);

	//Useful methods
	void addVertex(double x, double y);
	bool addEdge(unsigned first_id, unsigned sec_id, const double &weight);
	unsigned getVertexIndex(unsigned id) const;
	unsigned getNumVertex() const;
	unsigned getNumEdges() const;
	Vertex getVertex(unsigned id) const;

	//Get methods
	vector<Vertex> getVertexSet();
};

