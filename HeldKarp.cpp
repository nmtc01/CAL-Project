/*
 * HeldKarp.cpp
 *
 *  Created on: 25 de mai de 2019
 *      Author: Estudio
 */

#include "HeldKarp.h"

HeldKarp::HeldKarp(Graph graph, FloydWarshall fw) {
	this->graph = graph;
	this->fw = fw;
	performed = false;
}

PathDistance HeldKarp::recursion(vector<unsigned> addresses, unsigned end){
	PathDistance answer, aux;
	double currentDistance = INF;
	if (addresses.size()==1){
		answer.path = {addresses[0], end};
		answer.distance = fw.getDistance(addresses[0], end);
		return answer;
	}

	for (size_t i = 0; i < addresses.size(); i++){
		vector<unsigned> tmp = {};
		for (size_t j = 0; j < addresses.size(); j++){
			if (i !=j) tmp.push_back(addresses[j]);
		}
		aux = recursion(tmp, addresses[i]);
		if (aux.distance + fw.getDistance(addresses[i], end) < currentDistance){
			answer.path = aux.path;
			currentDistance = aux.distance + fw.getDistance(addresses[i], end);
		}
	}
	answer.path.push_back(end);
	answer.distance = currentDistance;

	return answer;
}

void HeldKarp::perform(unsigned school, unsigned garage, vector<unsigned> addresses){

	PathDistance aux, answer;
	answer.distance = INF;
	path = {};
	distance = 0;
	if (addresses.size()==1){
		path = {school, garage};
		distance = fw.getDistance(school, garage);
		return;
	}

	if (addresses.size()==1){
		path = {school, addresses[0], garage};
		distance = fw.getDistance(addresses[0], garage) + fw.getDistance(school, addresses[0]);
		return;
	}

	for (size_t i = 0; i < addresses.size(); i++){
		vector<unsigned> tmp = {};
		for (size_t j = 0; j < addresses.size(); j++){
			if (i != j) tmp.push_back(addresses[j]);
		}
		aux = recursion(tmp, garage);
		if (fw.getDistance(school, addresses[i]) + fw.getDistance(addresses[i], aux.path[0]) + aux.distance < answer.distance){
			answer.distance = fw.getDistance(school, addresses[i]) + fw.getDistance(addresses[i], aux.path[0]) + aux.distance;
			answer.path = {school, addresses[i]};
			answer.path.insert( answer.path.end(), aux.path.begin(), aux.path.end() );
		}
	}

	path = answer.path;
	distance = answer.distance;
	performed = true;
}


vector<unsigned> HeldKarp::getPath(){
	return path;
}

double HeldKarp::getDistance(){
	return distance;
}

void HeldKarp::printPath(){
	for (size_t i = 0; i < path.size(); i++){
		cout << path[i] << " ";
	}
	cout << endl;

}


HeldKarp::~HeldKarp() {
	// TODO Auto-generated destructor stub
}

