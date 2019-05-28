/*
 * BranchAndBound.cpp
 *
 *  Created on: 24 de mai de 2019
 *      Author: Estudio
 */

#include "BranchAndBound.h"

BranchAndBound::BranchAndBound(Graph graph, FloydWarshall fw) {
	this->graph = graph;
	this->fw = fw;
	performed = false;
	bound = INF;

}

double BranchAndBound::Prim(vector<unsigned> addresses) {
	if (addresses.size() == 0)
		return 0;
	// Reset auxiliary info
	double min_dist = INF;
	unsigned k = 0;
	vector<double> dist;
	vector<bool> visited;
	dist.push_back(0);
	visited.push_back(false);
	for(size_t i = 1; i < addresses.size(); i++) {
		dist.push_back(INF);
		//v->path = nullptr;
		visited.push_back(false);
	}
		// start with an arbitrary vertex
	unsigned s = addresses[0];

	// process vertices in the priority queue
	for(size_t i = 0; i < addresses.size(); i++) {
		min_dist=INF;
		for(size_t j = 0; j < addresses.size(); j++) {
			if (!visited[j] && dist[j] < min_dist) {
				k = j;
				min_dist=dist[j];
			}
		}
		visited[k] = true;
		for(size_t j = 0; j < addresses.size(); j++) {
			if (!visited[j]) {
				if(fw.getDistance(addresses[k], addresses[j]) < dist[j] ) {
					dist[j] = fw.getDistance(addresses[k],addresses[j]);
				}
			}
		}
	}
	double total = 0;
	for(size_t i = 0; i < dist.size(); i++) total += dist[i];
	return total;
}



void BranchAndBound::recursion(unsigned start, unsigned garage, vector<unsigned> addresses, double distanceUntilNow, vector<unsigned> pathUntilNow) {
	cout << "recursion" << endl;
	if (addresses.size() == 0){
		if (distanceUntilNow + fw.getDistance(start, garage) < bound){
			bound = distanceUntilNow + fw.getDistance(start, garage);
			pathUntilNow.push_back(garage);
			path = pathUntilNow;
			return;
		}
		else return;
	}
	if (addresses.size() == 1){
		double dist = distanceUntilNow + fw.getDistance(start, addresses[0]) + fw.getDistance(addresses[0], garage);
		if (dist < bound){
			bound = dist;
			pathUntilNow.push_back(addresses[0]);
			pathUntilNow.push_back(garage);
			path = pathUntilNow;
			return;
		}
		else return;
	}
	clock_t now = clock();
	if ((now-initial_time)/CLOCKS_PER_SEC > TIME_LIMIT) return;

	vector<unsigned> dest = addresses;
	dest.push_back(garage);
	dest.push_back(start);
	if (Prim(dest) + distanceUntilNow > bound)	return;

	vector<bool> checked;
	for (size_t j = 0; j < addresses.size(); j++) checked.push_back(false);
	unsigned k=0;
	vector<unsigned> path_tmp, addr_tmp;
	double min_dist = INF;
	for (size_t i = 0; i < addresses.size(); i++) {
		for (size_t j = 0; j < addresses.size(); j++){
			if (!checked[j] && fw.getDistance(start,addresses[j]) < min_dist) {
				k = j;
				min_dist = fw.getDistance(start,addresses[j]);
			}
		}

		addr_tmp={};
		for (size_t j = 0; j < addresses.size(); j++){
			if (k != j) addr_tmp.push_back(addresses[j]);
		}
		path_tmp = pathUntilNow;
		path_tmp.push_back(start);
		recursion(addresses[k], garage, addr_tmp, distanceUntilNow + fw.getDistance(start,addresses[k]), path_tmp);
		now = clock();
		if ((now-initial_time)/CLOCKS_PER_SEC > TIME_LIMIT) return;

	}
	return;
}



void BranchAndBound::perform(unsigned school, unsigned garage, vector<unsigned> addresses){
	NearestNeighbour NN(graph, fw);
	NN.perform(school, garage, addresses);
	path = NN.getPath();
	bound = NN.getDistance();
	vector<unsigned> tmp = {};
	double zero = 0.0;
	recursion(school, garage, addresses, zero, tmp);
	performed = true;
}

void BranchAndBound::printPath(){
	for (size_t j = 0; j < path.size(); j++)
		cout << path[j] << " ";
	cout << endl;
}

vector<unsigned> BranchAndBound::getPath(){
	return path;
}

double BranchAndBound::getDistance(){
	return bound;
}


BranchAndBound::~BranchAndBound() {
	// TODO Auto-generated destructor stub
}
