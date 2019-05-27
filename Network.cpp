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
	if (fw.alreadyPerformed()) return; //N„o È necessario executar o FloydWarshall mais de uma vez. Este if evita perda de tempo.
	unsigned v = map.getNumVertex();
	unsigned e = map.getNumEdges();
	//distances = {};
	//paths = {};

	if ((v+e)*log2((double)v)*childrenVertices.size() > pow(v, 3) || true){ //o true √© s√≥ para testar
		//Neste caso calcular FloydWarshall
		FloydWarshall FW = FloydWarshall(map);
		FW.perform();
		//O ciclo abaixo aloca os resultados em duas matrizes (distances e paths)
		//provavelmente n„o vamos mais usar isto
		/*
		for (size_t i = 0; i < childrenVertices.size(); i++){
			distances.push_back({});
			paths.push_back({});
			for (size_t j = 0; j < childrenVertices.size(); j++){
				distances[i].push_back(FW.getDistance(childrenVertices[i].getId(), childrenVertices[j].getId()));
				paths[i].push_back(FW.getPath(childrenVertices[i].getId(), childrenVertices[j].getId()));
			}
		}
		for (size_t i = 0; i < childrenVertices.size(); i++){
			//as informacoes sobre a escola e a garagem sao postas em vetores separados
			distancesFromSchool.push_back(FW.getDistance(school.getId(), childrenVertices[i].getId()));
			distancesToGarage.push_back(FW.getDistance(childrenVertices[i].getId(), garage.getId()));

			pathsFromSchool.push_back(FW.getPath(school.getId(), childrenVertices[i].getId()));
			pathsToGarage.push_back(FW.getPath(childrenVertices[i].getId(), garage.getId()));

		}*/
		fw=FW;
	}
	else {
		//Neste caso calcular Dijkstra para cada vertice
		dij = Dijkstra(map);
		/*
		 * Algo assim (quando o Dijkstra estiver pronto):
		for (size_t i = 0; i < childrenIds.size(); i++){
			perform(childrenIds[i]);
		}
		*/
	}
}

FloydWarshall Network::getFloydWarshall(){
	return fw;
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







