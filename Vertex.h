/*
 * Vertex.h
 *
 *  Created on: 20/05/2019
 *      Author: Nuno Cardoso
 */

#ifndef SRC_VERTEX_H_
#define SRC_VERTEX_H_

#include <vector>
#include <string>
#include <queue>
#include "MutablePriorityQueue.h"
#include <limits>
#include "Edge.h"

#define INF std::numeric_limits<double>::max()

class Graph;

/************************* Vertex  **************************/

class Vertex {
	//unsigned info;                // contents
	vector<Edge> adj;  // outgoing edges
	bool visited;          // auxiliary field
	double dist = 0;
	Vertex *path = nullptr;
	int queueIndex = 0; 		// required by MutablePriorityQueue

	double X;
	double Y;
	unsigned id;
	string amenity;

	void addEdge(Vertex *dest, double w);


public:
	Vertex(unsigned id, double x, double y);

	int getId() const;

	double getX() const;
	double getY() const;

	string getAmenity() const;
	void setAmenity(string amenity);

	vector<Edge> getOutEdges() const;


	/*** Class functions ***/

	Vertex(unsigned id);

	bool operator<(Vertex & vertex) const; // // required by MutablePriorityQueue
	unsigned getInfo() const;
	double getDist() const;
	Vertex *getPath() const;

	//Vertex nearestVertexNotVisited();

	friend class Graph;
	friend class MutablePriorityQueue<Vertex>;
};


#endif /* SRC_VERTEX_H_ */
