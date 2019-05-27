/*
 * Network.cpp
 *
 */

#include "Network.h"
#include <cmath>

//Constructor
Network::Network() {
	numberOfBus = 0;
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
	//if (fw.AlreadyPerformed) return; //N�o � necessario executar o FloydWarshall mais de uma vez. Este if evita perda de tempo.
	unsigned v = map.getNumVertex();
	unsigned e = map.getNumEdges();
	//distances = {};
	//paths = {};

	if ((v+e)*log2((double)v)*childrenVertices.size() > pow(v, 3)){ //o true é só para testar
		//Neste caso calcular FloydWarshall
		FloydWarshall fw = FloydWarshall(map);
		fw.perform();
		*APC = fw;
	}
	else {
		//Neste caso calcular Dijkstra para cada vertice
		Dijkstra dij = Dijkstra(map);
		for (size_t i = 0; i < childrenVertices.size(); i++){
			dij.perform(school.getId(), childrenVertices[i].getId());
			dij.perform(childrenVertices[i].getId(),garage.getId());
			for (size_t j = 0; j < childrenVertices.size(); j++) dij.perform(childrenVertices[i].getId(),childrenVertices[j].getId());
		}
		*APC=dij;
	}
}

AbstractPathCalculator* Network::getAPC(){
	return APC;
}


unsigned Network::getSchoolId(){
	return school.getId();
}
unsigned Network::getGarageId(){
	return garage.getId();
}

vector<unsigned> Network::getChildrenIds(){
	vector<unsigned> ids = {};
	for (size_t i = 0; i < childrenVertices.size(); i++){
		ids.push_back(childrenVertices[i].getId());
	}
	return ids;
}



/*
Matrix Network::getDistances(){
	return distances;
}

vector<vector<vector<unsigned>>> Network::getPaths(){
	return paths;
}

vector<double> Network::getDistancesFromSchool(){
	return distancesFromSchool;
}

vector<double> Network::getDistancesToGarage(){
	return distancesToGarage;
}

vector<vector<unsigned>> Network::getPathsFromSchool(){
	return pathsFromSchool;
}

vector<vector<unsigned>> Network::getPathsToGarage(){
	return pathsToGarage;
}*/







