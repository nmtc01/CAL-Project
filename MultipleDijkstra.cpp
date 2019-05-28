/*
 * MultipleDijskstra.cpp
 *
 *  Created on: 28 de mai de 2019
 *      Author: Estudio
 */

#include "MultipleDijkstra.h"
#include <iostream>

MultipleDijkstra::MultipleDijkstra() {

}

MultipleDijkstra::MultipleDijkstra(const Graph &graph) : graph(graph) {
	dijkstras={};
	sourceIds={};
}

void MultipleDijkstra::perform(vector<unsigned> sourcesIds) {
	for (size_t i = 0; i < sourcesIds.size(); i++){
		dijkstras.push_back(Dijkstra(graph));
		this->sourceIds.push_back(sourcesIds[i]);
		dijkstras[i].perform(sourcesIds[i]);
	}
}

double MultipleDijkstra::getDistance(unsigned sourceId, unsigned destinyId) const {
	cout << "MultipleDijkstra::getDistance(" << sourceId << ", " << destinyId << ")"  <<endl;
	unsigned i = 0;
	for (i = 0; i < sourceIds.size(); i++){
		if (sourceIds[i]==sourceId) break;
	}
	return dijkstras[i].getDistance(destinyId);
}
vector<unsigned> MultipleDijkstra::getPath(unsigned sourceId, unsigned destinyId) const{
	cout  << "MultipleDijkstra::getDistance" << endl;
	unsigned i = 0;
	for (i = 0; i < sourceIds.size(); i++){
		if (sourceIds[i]==sourceId) break;
	}
	return dijkstras[i].getPath(sourceId, destinyId);
}



MultipleDijkstra::~MultipleDijkstra() {
	// TODO Auto-generated destructor stub
}

