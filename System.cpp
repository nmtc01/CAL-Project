/*
 * System.cpp
 *
 *  Created on: 17 de mai de 2019
 *      Author: Estudio
 */

#include "System.h"
using namespace std;

template<class T>
Vertex<T> System<T>::getSchool(){
	return school;
}

template<class T>
Vertex<T> System<T>::getGarage(){
	return garage;
}

template<class T>
void System<T>::setSchool(T address){
	school = map.findVertex(address);
}

template<class T>
void System<T>::setGarage(T address){
	garage = map.findVertex(address);
}

template<class T>
void System<T>::insertAdress(T address){
	childrenVertices.push_back(map.findVertex(address));
}

template<class T>
void System<T>::removeAddress(T address){
	vector<Vertex<T>*> newVector = {};
	for (size_t i = 0; i < childrenVertices.size(); i++){
		if (childrenVertices[i]->getInfo() != address){
			newVector.push_back(childrenVertices[i]);
		}
		else break;
	}
	childrenVertices = newVector;
}

