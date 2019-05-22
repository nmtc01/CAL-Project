/*
 * Vertex.h
 *
 */

#pragma once

#include <vector>
#include <queue>
#include <string>

#include "Edge.h"
//#include "MutablePriorityQueue.h"

using namespace std;

class Vertex {
	unsigned id;
	double x;
	double y;
	string amenity;
	vector<Edge> edges;

	void addEdge(unsigned destinyId, double weight);

	//?
	bool visited;			//auxiliary field
	double dist = 0;
	unsigned path = -1;
	int queue_index = 0;	//required for MutablePriorityQueue

public:
	//Constructors
	Vertex();
	Vertex(unsigned id, double x, double y);

	//Get methods
	int getId() const;
	double getX() const;
	double getY() const;
	string getAmenity() const;
	vector<Edge> getEdges() const;

	//Set methods
	void setAmenity(string amenity);

	//Class functions
	bool operator<(Vertex &v2) const;
	unsigned getPath() const;
	double getDist() const;

	//Friend classes
	friend class Graph;
		//friend class MutablePriotiyQueue<Vertex>;
};
