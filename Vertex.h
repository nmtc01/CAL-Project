/*
 * Vertex.h
 *
 *  Created on: 20/05/2019
 *      Author: Nuno Cardoso
 */

#ifndef SRC_VERTEX_H_
#define SRC_VERTEX_H_

#include <vector>
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

Vertex::Vertex(unsigned id, double x, double y): id(id), X(x), Y(x) {
	amenity = "";
	visited = false;
}

int Vertex::getId() const {
	return id;
}

double Vertex::getX() const {
	return X;
}

double Vertex::getY() const {
	return Y;
}

string Vertex::getAmenity() const {
	return amenity;
}

vector<Edge> Vertex::getOutEdges() const {
	return adj;
}

void Vertex::setAmenity(string amenity) {
	this->amenity = amenity;
}


/*** class functions ***/

Vertex::Vertex(unsigned id): id(id) {
	X=0;
	Y=0;
	amenity = "";
	visited=false;

}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
void Vertex::addEdge(Vertex *d, double w) {
	adj.push_back(Edge(this, d, w));
}

bool Vertex::operator<(Vertex & vertex) const {
	return this->dist < vertex.dist;
}

double Vertex::getDist() const {
	return this->dist;
}

Vertex *Vertex::getPath() const {
	return this->path;
}
/*
Vertex Vertex::nearestVertexNotVisited(){
	double d = INF;
	for (size_t i = 0; i < adj.size(); i++) {
		if (adj[i].weight < d && !adj[i].dest.visited) d = adj[i].weight;
	}

}*/

#endif /* SRC_VERTEX_H_ */
