/*
 * Edge.h
 *
 *  Created on: 20/05/2019
 *      Author: Nuno Cardoso
 */

#ifndef SRC_EDGE_H_
#define SRC_EDGE_H_

#include "Vertex.h"

/********************** Edge  ****************************/

template <class T>
class Edge {
	Vertex<T> *orig; 	// Fp07
	Vertex<T> * dest;      // destination vertex
	double weight;         // edge weight

	bool selected; // Fp07

public:
	Edge(Vertex<T> *o, Vertex<T> *d, double w);
	friend class Graph<T>;
	friend class Vertex<T>;

	// Fp07
	double getWeight() const;
};

template <class T>
Edge<T>::Edge(Vertex<T> *o, Vertex<T> *d, double w): orig(o), dest(d), weight(w) {}

template <class T>
double Edge<T>::getWeight() const {
	return weight;
}


#endif /* SRC_EDGE_H_ */
