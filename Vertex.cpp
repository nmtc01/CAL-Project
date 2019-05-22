/*
 * Vertex.cpp
 *
 *  Created on: 22 de mai de 2019
 *      Author: Estudio
 */

#include "Vertex.h"

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





