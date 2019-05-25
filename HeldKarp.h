/*
 * HeldKarp.h
 *
 *  Created on: 25 de mai de 2019
 *      Author: Estudio
 */

#pragma once

#include "FloydWarshall.h"
#include "Graph.h"

typedef struct {
	vector<unsigned> path;
	double distance;
} PathDistance;

class HeldKarp {
	Graph graph;
	FloydWarshall fw;
	vector<unsigned> path;
	double distance;
	bool performed;
	PathDistance recursion(vector<unsigned> addresses, unsigned end);
public:
	HeldKarp(Graph graph, FloydWarshall fw);
	void perform(unsigned school, unsigned garage, vector<unsigned> addresses);

	vector<unsigned> getPath();
	double getDistance();
	void printPath();

	virtual ~HeldKarp();
};
