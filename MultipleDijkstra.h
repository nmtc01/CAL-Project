/*
 * MultipleDijskstra.h
 *
 *  Created on: 28 de mai de 2019
 *      Author: Estudio
 */

#pragma once
#include "Dijkstra.h"

class MultipleDijkstra {
	Graph graph;
	vector<unsigned> sourceIds;
	vector<Dijkstra> dijkstras;

public:
	MultipleDijkstra();
	MultipleDijkstra(const Graph &graph);
	void perform(vector<unsigned> sourcesIds);
	double getDistance(unsigned sourceId, unsigned destinyId) const;
	vector<unsigned> getPath(unsigned sourceId, unsigned destinyId) const;
	virtual ~MultipleDijkstra();
};

