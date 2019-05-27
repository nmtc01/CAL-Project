/*
 * Vertex.h
 *
 */

#pragma once

#include <unordered_set>
#include <vector>
#include <queue>
#include <string>

#include "Edge.h"

using namespace std;

class Vertex {
	unsigned id;
	double x;
	double y;
	string amenity;
	vector<Edge> edges;

	void addEdge(unsigned destinyId, double weight);

	double dist = 0;
	unsigned path = -1;
	int queue_index = 0;	//required for MutablePriorityQueue

public:
	//Constructors
	Vertex();
	Vertex(unsigned id, double x, double y);

	//Get methods
	unsigned getId() const;
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


//Auxiliary structs for the vertex hash table
struct VertexHash {
	int operator() (const Vertex & v) const {
		return v.getId();
	}

	bool operator() (const Vertex & v1, const Vertex & v2) const {
		return v1.getId() == v2.getId();
	}
};

//Vertex hash table
typedef unordered_set<Vertex, VertexHash, VertexHash> VertexHashTable;




