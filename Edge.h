/*
 * Edge.h
 *
 *  Created on: 20/05/2019
 *      Author: Nuno Cardoso
 */

#ifndef SRC_EDGE_H_
#define SRC_EDGE_H_

class Vertex;

/********************** Edge  ****************************/

class Edge {
	Vertex *orig; 	// Fp07
	Vertex *dest;      // destination vertex
	double weight;         // edge weight

	bool selected; // Fp07

public:

	Vertex* getDest() const;

	/*** Class functions ***/

	Edge(Vertex *o, Vertex *d, double w);
	friend class Graph;
	friend class Vertex;

	// Fp07
	double getWeight() const;
};



#endif /* SRC_EDGE_H_ */
