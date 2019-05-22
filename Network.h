/*
 * Network.h
 *
 */

#pragma once

#include "Graph.h"


class Network {

	Graph map;
	//vector<string> childrenAdresses;
	Vertex school;
	Vertex garage;
	vector<Vertex> schools;
	vector<Vertex> childrenVertices;    // vertex set
	unsigned int numberOfBus;

public:
	Network();
	Graph getMap();
	void loadMap(const Graph& newMap);
	void initializeSchools();
	vector<Vertex> getSchools();
	Vertex getSchool();
	void setSchool(unsigned id);
	Vertex getGarage();
	void setGarage(unsigned id);
	vector<Vertex>	getChildrenVertices();
	void insertAddress(unsigned id);
	void removeAddress(unsigned id);
	unsigned int getNumberOfBus();
	void setNumberOfBus();

	//void calculatePathsMatrix(); //calculate Matrix with shortest path for each pair of vertices
	//void calculateBusPath();       //calculate shortest path passing by all the addresses

};
