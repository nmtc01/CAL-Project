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

template <class T> class Edge;
template <class T> class Vertex;
template <class T> class Graph;

/************************* Vertex  **************************/

template <class T>
class Vertex {
	T info;                // contents
	vector<Edge<T> > adj;  // outgoing edges
	bool visited;          // auxiliary field
	double dist = 0;
	Vertex<T> *path = nullptr;
	int queueIndex = 0; 		// required by MutablePriorityQueue

	double X;
	double Y;
	unsigned id;
	string amenity;

	void addEdge(Vertex<T> *dest, double w);


public:
	Vertex(unsigned id, double x, double y, T in);
	Vertex(unsigned id, double x, double y);			// ----> probably temporary

	int getId() const;

	double getX() const;
	double getY() const;

	string getAmenity() const;
	void setAmenity(string amenity);

	vector<Edge<T> > getOutEdges() const;


	/*** Class functions ***/

	Vertex(T in);

	bool operator<(Vertex<T> & vertex) const; // // required by MutablePriorityQueue
	T getInfo() const;
	double getDist() const;
	Vertex *getPath() const;
	friend class Graph<T>;
	friend class MutablePriorityQueue<Vertex<T>>;
};

template <class T>
Vertex<T>::Vertex(unsigned id, double x, double y, T in): id(id), X(x), Y(x), info(in) {
	amenity = "";
}

template <class T>
Vertex<T>::Vertex(unsigned id, double x, double y): id(id), X(x), Y(x) {
	amenity = "";
}

template <class T>
int Vertex<T>::getId() const {
	return id;
}

template <class T>
double Vertex<T>::getX() const {
	return X;
}

template <class T>
double Vertex<T>::getY() const {
	return Y;
}

template <class T>
string Vertex<T>::getAmenity() const {
	return amenity;
}

template<class T>
vector<Edge<T> > Vertex<T>::getOutEdges() const {
	return adj;
}

template <class T>
void Vertex<T>::setAmenity(string amenity) {
	this->amenity = amenity;
}


/*** class functions ***/

template <class T>
Vertex<T>::Vertex(T in): info(in) {}

/*
 * Auxiliary function to add an outgoing edge to a vertex (this),
 * with a given destination vertex (d) and edge weight (w).
 */
template <class T>
void Vertex<T>::addEdge(Vertex<T> *d, double w) {
	adj.push_back(Edge<T>(this, d, w));
}

template <class T>
bool Vertex<T>::operator<(Vertex<T> & vertex) const {
	return this->dist < vertex.dist;
}

template <class T>
T Vertex<T>::getInfo() const {
	return this->info;
}

template <class T>
double Vertex<T>::getDist() const {
	return this->dist;
}

template <class T>
Vertex<T> *Vertex<T>::getPath() const {
	return this->path;
}

#endif /* SRC_VERTEX_H_ */
