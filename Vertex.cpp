/*
 * Vertex.cpp
 *
 */

#include "Vertex.h"

//Constructor
Vertex::Vertex() {
	id = -1;
	x = 0;
	y = 0;
	amenity = "";
}

Vertex::Vertex(unsigned id, double x, double y) : id(id), x(x), y(y) {
	amenity = "";
}


//Helpful methods
void Vertex::addEdge(unsigned destinyId, double weight) {
	Edge edge(id, destinyId, weight);
	edges.push_back(edge);
}

//Get methods
unsigned Vertex::getId() const {
	return id;
}

double Vertex::getX() const {
	return x;
}

double Vertex::getY() const {
	return y;
}

string Vertex::getAmenity() const {
	return amenity;
}

vector<Edge> Vertex::getEdges() const {
	return edges;
}


//Set methods
void Vertex::setAmenity(string amenity) {
	this->amenity = amenity;
}


//Class functions
bool Vertex::operator<(Vertex &v2) const {
	return this->dist < v2.dist;
}

unsigned Vertex::getPath() const {
	return path;
}

double Vertex::getDist() const {
	return dist;
}








