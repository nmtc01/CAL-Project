/*
 * NearestNeighbour.cpp
 *
 */

#include "NearestNeighbour.h"
#include <iostream>

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
	path = {};
	path.push_back(network.getSchool().getId());
	if (network.getChildrenVertices().size() == 0){
		cout << "There are no children addresses in the path. Please insert the addresses." << endl << endl;
		path.push_back(network.getGarage().getId());
		return;
	}
	//encontra vertice mais proximo da escola
	for (size_t i = 0; i < network.getDistancesFromSchool().size(); i++){
		if (dist > network.getDistancesFromSchool()[i]){
			k = i;
			dist = network.getDistancesFromSchool()[i];
		}
	}
	if (dist != INF){
		visited[k]=true;
		distance += dist;
		path.push_back(network.getChildrenIds()[k]);
	}


	cout << network.getDistances().size() << endl;
	for (size_t i = 0; i < network.getDistances().size(); i++) {
		cout << "2nd for" << endl;
		dist = INF;
		for (size_t j = 0; j < network.getDistances()[k].size(); j++){
			cout << "forfor" << endl;
			if (dist > network.getDistances()[k][j] && !visited[j]){
				cout << "if" << endl;
				k2 = j;
				dist = network.getDistances()[k][j];
				cout << "dist = " << dist << endl;
			}
		}
		if (dist == INF){
			cout << "dist = INF --- brak"<< endl;
			break;
		}
		k=k2;
		visited[k]=true;
		distance += dist;
		path.push_back(network.getChildrenIds()[k]);

	}
	distance+=network.getDistancesToGarage()[k];
	path.push_back(network.getGarageId());


	performed = true;

}

vector<unsigned> NearestNeighbour::getPath(){
	return path;
}

double NearestNeighbour::getDistance(){
	return distance;
}

void NearestNeighbour::printPath(){
	for (size_t i=0; i < path.size(); i++){
		cout << path[i] << " ";
	}
}

NearestNeighbour::~NearestNeighbour() {
	// TODO Auto-generated destructor stub
}

