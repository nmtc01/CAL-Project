/*
 * Edge.cpp
 *
 */

#include "Edge.h"

Edge::Edge(unsigned sourceId, unsigned destinyId, double weight) : sourceId(sourceId), destinyId(destinyId), weight(weight) {};

unsigned Edge::getSourceId() const {
	return sourceId;
}

unsigned Edge::getDestinyId() const {
	return destinyId;
}

double Edge::getWeight() const {
	return weight;
}


