/*
 * NearestNeighbour.cpp
 *
 *  Created on: 23 de mai de 2019
 *      Author: Estudio
 */

#include "NearestNeighbour.h"

NearestNeighbour::NearestNeighbour(Network nw) {
	network=nw;
	performed = false;
	distance = 0;
	path = {};
	visited = {};
	for (size_t i = 0; i < network.getChildrenVertices().size(); i++) visited.push_back(false);

}

void NearestNeighbour::perform(){
	size_t k, k2;
	double dist = INF;

	//encontra vertice mais proximo da escola
	for (size_t i = 0; i < network.getDistancesFromSchool().size(); i++){
		if (dist > network.getDistancesFromSchool()[i]){
			k = i;
			dist = network.getDistancesFromSchool()[i];
		}
	}
	distance += distance;
	path.push_back(network.getChildrenVertices()[k].getId());


	for (size_t i = 0; i < network.getDistances().size(); i++) {
		dist = INF;
		for (size_t j = 0; j < network.getDistances()[k].size(); j++){
			if (dist > network.getDistances()[k][j]){
				k2 = j;
				dist = network.getDistances()[k][j];
			}
		}
		k=k2;
		distance += dist;
		path.push_back(network.getChildrenVertices()[k].getId());

	}
	distance+=network.getDistancesToGarage()[k];
	path.push_back(network.getGarage().getId());




	performed = true;

}

NearestNeighbour::~NearestNeighbour() {
	// TODO Auto-generated destructor stub
}

