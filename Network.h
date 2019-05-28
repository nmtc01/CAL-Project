/*
 * Network.h
 *
 */

#pragma once

#include "Graph.h"
#include "FloydWarshall.h"
#include "MultipleDijkstra.h"


class Network {

	Graph map;
	Vertex school;
	Vertex garage;
	vector<Vertex> schools;
	vector<Vertex> childrenVertices;    // vertex set
	unsigned int numberOfBus;
	unsigned busCapacity;
	FloydWarshall fw;
	MultipleDijkstra dij;
public:
	Network();
	Graph getMap();
	FloydWarshall getFloydWarshall();
	MultipleDijkstra getDijkstra();
	void loadMap(const Graph& newMap);
	void initializeSchools();
	vector<Vertex> getSchools();
	Vertex getSchool();
	unsigned getSchoolId();
	void setSchool(unsigned id);
	Vertex getGarage();
	unsigned getGarageId();
	void setGarage(unsigned id);
	vector<Vertex>	getChildrenVertices();
	vector<unsigned> getChildrenIds();
	void clearChildrenVertices();


	void insertAddress(unsigned id);
	bool removeAddress(unsigned id);
	unsigned getBusCapacity();
	void setBusCapacity(unsigned cap);

	unsigned int getNumberOfBus();
	void setNumberOfBus();

	void calculatePathMatrix(); //calculate Matrix with shortest path for each pair of vertices

};
