/*
 * NearestNeighbour.cpp
 *
 */

#include "NearestNeighbour.h"
#include <iostream>

NearestNeighbour::NearestNeighbour() {
	withFW = false;
	performed = false;
	distance = 0;
	path = {};
	visited = {};
}

NearestNeighbour::NearestNeighbour(Graph graph, FloydWarshall fw) {
	this->graph=graph;
	this->fw=fw;
	withFW = true;
	performed = false;
	distance = 0;
	path = {};
	visited = {};
}
NearestNeighbour::NearestNeighbour(Graph graph, MultipleDijkstra dij) {
	this->graph=graph;
	this->dij=dij;
	withFW = false;
	performed = false;
	distance = 0;
	path = {};
	visited = {};
}

void NearestNeighbour::perform(unsigned school, unsigned garage, vector<unsigned> addresses){
	if (withFW) performWithFW(school, garage, addresses);
	else performWithDij(school, garage, addresses);
}



void NearestNeighbour::performWithFW(unsigned school, unsigned garage, vector<unsigned> addresses){
	size_t k, k2;
	double dist = INF;
	path = {};
	path.push_back(school);
	visited = {};
	for (size_t i = 0; i < addresses.size(); i++) visited.push_back(false);
	if (addresses.size() == 0){
		cout << "There are no children addresses in the path. Please insert the addresses." << endl << endl;
		path.push_back(garage);
		return;
	}
	//encontra vertice mais proximo da escola
	for (size_t i = 0; i < addresses.size(); i++){
		if (dist > fw.getDistance(school, addresses[i])){
			k = i;
			dist = fw.getDistance(school, addresses[i]);
		}
	}
	if (dist != INF){
		visited[k]=true;
		distance += dist;
		vector<unsigned> tmp = fw.getPath(school, addresses[k]);
		path.insert(path.end(), tmp.begin(), tmp.end());
	}


	cout << addresses.size() << endl;
	for (size_t i = 0; i < addresses.size(); i++) {
		cout << "2nd for" << endl;
		dist = INF;
		for (size_t j = 0; j < addresses.size(); j++){
			cout << "forfor" << endl;
			if (dist > fw.getDistance(addresses[k],addresses[j]) && !visited[j]){
				cout << "if" << endl;
				k2 = j;
				dist = fw.getDistance(addresses[k],addresses[j]);
				cout << "dist = " << dist << endl;
			}
		}
		if (dist == INF){
			cout << "dist = INF --- break"<< endl;
			break;
		}
		k=k2;
		visited[k]=true;
		distance += dist;
		path.push_back(addresses[k]);

	}
	cout << "exited for"<< endl;
	distance+=fw.getDistance(addresses[k],garage);
	cout << "fw.getDistance"<< endl;
	path.push_back(garage);


	performed = true;

}

void NearestNeighbour::performWithDij(unsigned school, unsigned garage, vector<unsigned> addresses){
	size_t k, k2;
	double dist = INF;
	path = {};
	path.push_back(school);
	visited = {};
	cout << "performWithDij" << endl;
	for (size_t i = 0; i < addresses.size(); i++) visited.push_back(false);
	if (addresses.size() == 0){
		cout << "There are no children addresses in the path. Please insert the addresses." << endl << endl;
		path.push_back(garage);
		return;
	}
	//encontra vertice mais proximo da escola
	for (size_t i = 0; i < addresses.size(); i++){
		if (dist > dij.getDistance(school, addresses[i])){
			k = i;
			dist = dij.getDistance(school, addresses[i]);
		}
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
			if (k!=j){
				cout << "k!=j" << endl;
				if (dij.getDistance(addresses[k],addresses[j])!=INF){
					cout << "not INF" << endl;
					if (dist > dij.getDistance(addresses[k],addresses[j]) && !visited[j]){
						cout << "if" << endl;
						k2 = j;
						dist = dij.getDistance(addresses[k],addresses[j]);
						cout << "dist = " << dist << endl;
					}
				}
			}
		}
		if (dist == INF){
			cout << "dist = INF --- break"<< endl;
			break;
		}
		k=k2;
		visited[k]=true;
		distance += dist;
		path.push_back(addresses[k]);

	}
	distance+=dij.getDistance(addresses[k],garage);
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

