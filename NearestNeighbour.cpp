/*
 * NearestNeighbour.cpp
 *
 */

#include "NearestNeighbour.h"
#include <iostream>


NearestNeighbour::NearestNeighbour(Graph graph, AbstractPathCalculator *APC) {
	//network=nw;
	this->graph = graph;
	this->APC = APC;
	performed = false;
	distance = 0;
	path = {};
	visited = {};

}

void NearestNeighbour::perform(unsigned school, unsigned garage, vector<unsigned> addresses, AbstractPathCalculator *APC2){
	size_t k, k2;
	double dist = INF;
	path = {};
	path.push_back(school);
	visited = {};
	cout << "starting nearest neighbour" << endl;
	for (size_t i = 0; i < addresses.size(); i++) visited.push_back(false);
	if (addresses.size() == 0){
		cout << "There are no children addresses in the path. Please insert the addresses." << endl << endl;
		distance = APC->getDistance(school, garage);
		path.push_back(garage);
		return;
	}
	//encontra vertice mais proximo da escola
	for (size_t i = 0; i < addresses.size(); i++){
		cout << "for" << endl;
		if (dist > APC2->getDistance(school, addresses[i])){
			cout << "if" << endl;
			k = i;
			dist = APC2->getDistance(school, addresses[i]);
		}
		else cout << "else" << endl;
	}
	if (dist != INF){
		visited[k]=true;
		distance += dist;
		path.push_back(addresses[k]);
	}


	cout << addresses.size() << endl;
	for (size_t i = 0; i < addresses.size(); i++) {
		cout << "2nd for" << endl;
		dist = INF;
		for (size_t j = 0; j < addresses.size(); j++){
			cout << "forfor" << endl;
			if (dist > APC->getDistance(addresses[k],addresses[j]) && !visited[j]){
				cout << "if" << endl;
				k2 = j;
				dist = APC->getDistance(addresses[k],addresses[j]);
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
		path.push_back(addresses[k]);

	}
	distance+=APC->getDistance(addresses[k],garage);
	path.push_back(garage);


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

