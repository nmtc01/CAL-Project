/*
 * System.cpp
 *
 *  Created on: 17 de mai de 2019
 *      Author: Estudio
 */

include "System.h"
using namespace std;

Vertex<T> getSchool(){
	return school;
}
Vertex<T> getGarage(){
	return garage;
}

void setSchool(T address){
	school = map.findVertex(address);
}

void setGarage(T address){
	garage = map.findVertex(address);
}

void insertAdress(T address){
	childrenVertices.push_back(map.findVertex(address));
}

void removeAddress(T address){
	vector<Vertex<T>*> newVector = {};
	for (size_t = 0; i < childrenVertices.size(); i++){
		if (childrenVertices[i]->getInfo() != address){
			newVector.push_back(childrenVertices[i]);
		}
		else break;
	}
	
}
