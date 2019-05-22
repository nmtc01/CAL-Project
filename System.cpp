/*
 * System.cpp
 *
 *  Created on: 17 de mai de 2019
 *      Author: Estudio
 */

#include "System.h"
using namespace std;


Vertex* System::getSchool(){
	return school;
}


Vertex* System::getGarage(){
	return garage;
}


void System::setSchool(unsigned address){
	school = map.findVertex(address);
}


void System::setGarage(unsigned address){
	garage = map.findVertex(address);
}


void System::insertAddress(unsigned address){
	childrenVertices.push_back(map.findVertex(address));
}


void System::removeAddress(unsigned address){
	vector<Vertex*> newVector = {};
	for (size_t i = 0; i < childrenVertices.size(); i++){
		if (childrenVertices[i]->getId() != address){
			newVector.push_back(childrenVertices[i]);
		}
		else break;
	}
	childrenVertices = newVector;
}
/*

vector System::nearestNeighbour() {
	vector answer;

	school


	return answer;
}*/
