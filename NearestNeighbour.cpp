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
	complete_path = {};
	visited = {};
}

NearestNeighbour::NearestNeighbour(Graph graph, FloydWarshall fw) {
	this->graph=graph;
	this->fw=fw;
	withFW = true;
	performed = false;
	distance = 0;
	path = {};
	complete_path = {};
	visited = {};
}
NearestNeighbour::NearestNeighbour(Graph graph, MultipleDijkstra dij) {
	this->graph=graph;
	this->dij=dij;
	withFW = false;
	performed = false;
	distance = 0;
	path = {};
	complete_path = {};
	visited = {};
}


void NearestNeighbour::perform(unsigned school, unsigned garage, vector<unsigned> addresses, unsigned capacity){
	if (withFW){
		vector<unsigned> tmp;
		while (0 < addresses.size() ){
			tmp = {};
			performWithFW(school, garage, addresses, capacity);

			vector<unsigned> percorridos = getPath();

			for (size_t i = 0; i < addresses.size(); i++){
				bool b = true;
				for (size_t j = 1; j < percorridos.size()-1; j++){
					if (addresses[i] == percorridos[j]) b = false;
				}
				if (b) tmp.push_back(addresses[i]);
			}
			addresses=tmp;
		}
	}
	else performWithDij(school, garage, addresses);
}


void NearestNeighbour::performWithFW(unsigned school, unsigned garage, vector<unsigned> addresses, unsigned capacity){
		size_t k, k2;
		double dist = INF;
		path = {};
		path.push_back(school);

		complete_path = {};
		complete_path.push_back(school);

		visited = {};
		distance = 0;
		unsigned number_of_children = 0;
		for (size_t i = 0; i < addresses.size(); i++) visited.push_back(false);
		if (addresses.size() == 0){
			path.push_back(garage);
			complete_path.push_back(garage);
			return;
		}
		if (capacity == 0){
			path.push_back(garage);
			complete_path.push_back(garage);
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
			complete_path.insert(complete_path.end(), tmp.begin(), tmp.end());

			path.push_back(addresses[k]);
			number_of_children += 1;
		}


		for (size_t i = 0; i < addresses.size(); i++) {
			if (number_of_children >= capacity) break;
			dist = INF;
			for (size_t j = 0; j < addresses.size(); j++){
				if (dist > fw.getDistance(addresses[k],addresses[j]) && !visited[j]){
					k2 = j;
					dist = fw.getDistance(addresses[k],addresses[j]);
				}
			}
			if (dist == INF){
				break;
			}
			k=k2;
			visited[k]=true;
			distance += dist;

			vector<unsigned> tmp = fw.getPath(school, addresses[k]);
			complete_path.insert(complete_path.end(), tmp.begin(), tmp.end());

			path.push_back(addresses[k]);
			number_of_children+=1;

		}
		distance+=fw.getDistance(addresses[k],garage);
		path.push_back(garage);
		paths.push_back(path);
		distances.push_back(distance);

		vector<unsigned> tmp = fw.getPath(garage, addresses[k]);
		complete_path.insert(complete_path.end(), tmp.begin(), tmp.end());

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

	vector<unsigned> tmp = fw.getPath(addresses[k], garage);
	complete_path.insert(complete_path.end(), tmp.begin(), tmp.end());

	performed = true;

}

vector<unsigned> NearestNeighbour::getPath(){
	return path;
}

vector<unsigned> NearestNeighbour::getCompletePath(){
	return complete_path;
}

double NearestNeighbour::getDistance(){
	return distance;
}

void NearestNeighbour::printPath(){
	for (size_t i=0; i < path.size(); i++){
		cout << path[i] << " ";
	}
}

void NearestNeighbour::printPaths(){
	for (size_t i=0; i < paths.size(); i++){

		cout << endl <<"Path "<< i+1 << ": ";
		for (size_t j=0; j < paths[i].size(); j++)
			cout << paths[i][j] << " ";
	}
}

NearestNeighbour::~NearestNeighbour() {
	// TODO Auto-generated destructor stub
}
