/*
 * Network.cpp
 *
 */

#include "Network.h"
#include <cmath>

//Constructor
Network::Network() {
	numberOfBus = 0;
	busCapacity = NOT_FOUND;
};


//Loads a map
void Network::loadMap(const Graph& newMap) {
	map = newMap;

	//initializeSchools();
}

void Network::initializeSchools() {
	for (unsigned int i = 0; i < map.getVertexSet().size(); i++) {
		if(map.getVertexSet()[i].getAmenity() != "")
			schools.push_back(map.getVertexSet()[i]);
	}
}

//Get methods
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

vector<Vertex>	Network::getChildrenVertices() {
	return childrenVertices;
}


//Set methods
void Network::setSchool(unsigned id){
	school = map.getVertexSet().at(id);
	schools.push_back(map.getVertexSet().at(id));
}

void Network::setGarage(unsigned id){
	garage = map.getVertexSet().at(id);
}


//Adress methods
void Network::insertAddress(unsigned id){
	childrenVertices.push_back(map.getVertexSet().at(id));
}

bool Network::removeAddress(unsigned id){
	vector<Vertex> newVector = {};
	bool returnValue = true; //true if found the id, else false
	for (size_t i = 0; i < childrenVertices.size(); i++){
		if (childrenVertices[i].getId() != id)
			newVector.push_back(childrenVertices[i]);
		else returnValue = true;
	}
	childrenVertices = newVector;
	return returnValue;
}


//Path methods
void Network::calculatePathMatrix(){
	if (fw.alreadyPerformed()) return; //Não é necessario executar o FloydWarshall mais de uma vez. Este if evita perda de tempo.
	unsigned v = map.getNumVertex();
	unsigned e = map.getNumEdges();
	//distances = {};
	//paths = {};

	if ((v+e)*log2((double)v)*childrenVertices.size() > pow(v, 3) || true){ //o true Ã© sÃ³ para testar
		//Neste caso calcular FloydWarshall
		FloydWarshall FW = FloydWarshall(map);
		FW.perform();
		fw=FW;
	}
	else {
		//Neste caso calcular Dijkstra para cada vertice
		dij = MultipleDijkstra(map);
		vector<unsigned> tmp = {};
		for (size_t i = 0; i < childrenVertices.size(); i++){
				tmp.push_back(childrenVertices[i].getId());
		}
		tmp.push_back(school.getId());
		dij.perform(tmp);

	}
}

FloydWarshall Network::getFloydWarshall(){
	return fw;
}
MultipleDijkstra Network::getDijkstra(){
	return dij;
}


unsigned Network::getSchoolId(){
	return school.getId();
}
unsigned Network::getGarageId(){
	return garage.getId();
}

unsigned Network::getBusCapacity(){
	return busCapacity;
}

vector<unsigned> Network::getChildrenIds(){
	vector<unsigned> ids = {};
	for (size_t i = 0; i < childrenVertices.size(); i++){
		ids.push_back(childrenVertices[i].getId());
	}
	return ids;
}

void Network::setBusCapacity(unsigned cap){
	busCapacity = cap;
}


void Network::clearChildrenVertices(){
	childrenVertices = {};
}

