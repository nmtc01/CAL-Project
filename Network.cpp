/*
 * Network.cpp
 *
 */

#include "Network.h"

Network::Network() {
	numberOfBus = 0;
};

void Network::loadMap(const Graph& newMap) {
	map = newMap;
}

Graph Network::getMap() {
	return map;
}

vector<Vertex> Network::getSchools() {
	return schools;
}

Vertex Network::getSchool(){
	return school;
}

Vertex Network::getGarage(){
	return garage;
}

void Network::setSchool(unsigned id){
	school = map.getVertexSet().at(id);
}

void Network::setGarage(unsigned id){
	garage = map.getVertexSet().at(id);
}

void Network::insertAddress(unsigned id){
	childrenVertices.push_back(map.getVertexSet().at(id));
}

void Network::removeAddress(unsigned id){
	vector<Vertex> newVector = {};
	for (size_t i = 0; i < childrenVertices.size(); i++){
		if (childrenVertices[i].getId() != id)
			newVector.push_back(childrenVertices[i]);
	}

	childrenVertices = newVector;
}




