/*
 * NearestNeighbour.h
 *
 */

#pragma once

#include "Network.h"

class NearestNeighbour {
	Network network;
	vector<bool> visited;
	double distance;
	vector<unsigned> path;
	bool performed;

public:
	NearestNeighbour(Network nw);

	void perform();

	vector<unsigned> getPath();
	void printPath();

	virtual ~NearestNeighbour();
};

