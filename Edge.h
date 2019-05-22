/*
 * Edge.h
 *
 */

#pragma once


class Edge {
	unsigned sourceId;
	unsigned destinyId;
	double weight;

	bool selected;	//?

public:
	//Constructor
	Edge(unsigned sourceId, unsigned destinyId, double weight);

	//Get methods
	unsigned getSourceId() const;
	unsigned getDestinyId() const;
	double getWeight() const;

	//Friend classes
	friend class Graph;
	friend class Vertex;
};
