/*
 * System.h
 *
 *  Created on: 17 de mai de 2019
 *      Author: Estudio
 */

#include <vector>
#include <string>
#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"
using namespace std;





class System {

	Graph map;
	Vertex *school;
	Vertex *garage;
	vector<Vertex *> childrenVertices;    // vertex set
	unsigned int numberOfBus;

public:
	void loadMap(string fileName);
	Vertex* getSchool();
	void setSchool(unsigned address);
	Vertex* getGarage();
	void setGarage(unsigned address);
	vector<Vertex *>	getChildrenVertices();
	void insertAddress(unsigned address);
	void removeAddress(unsigned address);
	unsigned int getNumberOfBus();
	void setNumberOfBus();

	//void calculatePathsMatrix(); //calculate Matrix with shortest path for each pair of vertices
	//void calculateBusPath();       //calculate shortest path passing by all the addresses

};
