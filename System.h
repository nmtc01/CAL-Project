/*
 * System.h
 *
 *  Created on: 17 de mai de 2019
 *      Author: Estudio
 */

#include <vector>
#include <string>
using namespace std;

template <class T> class Vertex;
template <class T> class Graph;

template <class T>
class System {

	Graph<T> map;
	//vector<string> childrenAdresses;
	Vertex<T> school;
	Vertex<T> garage;
	vector<Vertex<T> *> childrenVertices;    // vertex set
	unsigned int numberOfBus;

public:
	void loadMap(string fileName);
	Vertex<T> getSchool();
	void setSchool(T address);
	Vertex<T> getGarage();
	void setGarage(T address);
	vector<Vertex<T> *>	getChildrenVertices();
	void insertAddress(T address);
	void removeAddress(T address);
	unsigned int getNumberOfBus();
	void setNumberOfBus();

	//void calculatePathsMatrix(); //calculate Matrix with shortest path for each pair of vertices
	//void calculateBusPath();       //calculate shortest path passing by all the addresses

};
