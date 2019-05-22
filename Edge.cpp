/*
 * Edge.cpp
 *
 *  Created on: 22 de mai de 2019
 *      Author: Estudio
 */

#include "Edge.h"
using namespace std;



Vertex* Edge::getDest() const {
	return dest;
}

/*** Class Functions ***/


Edge::Edge(Vertex *o, Vertex *d, double w): orig(o), dest(d), weight(w) {
	selected = false;
}


double Edge::getWeight() const {
	return weight;
}


