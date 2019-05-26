/*
 * FloydWarshall.h
 *
 */

#pragma once

#include "Graph.h"

typedef vector<vector<double>> Matrix;

class FloydWarshall {
	Graph graph;
	double **distances = nullptr;	//matrix array for distances
	unsigned **paths = nullptr;		//matrix array for the path
	bool performed;

public:
	//Constructor
	FloydWarshall();
	FloydWarshall(const Graph &graph);

	//Calcules distances between all points
	void perform();
	bool alreadyPerformed();

	//Show the path between two points
	vector<unsigned> getPath(unsigned sourceId, unsigned destinyId) const;
	double getDistance(unsigned sourceId, unsigned destinyId) const;
};


//auxiliary function for matrix deletion
template <class T>
void deleteMatrix(T **m, int n) {
	if (m != nullptr) {
		for (int i = 0; i < n; i++)
			if (m[i] != nullptr)
				delete [] m[i];
		delete [] m;
	}
}
