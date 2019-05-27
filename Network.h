/*
 * Network.h
 *
 */

#pragma once

#include "Graph.h"
#include "FloydWarshall.h"


class Network {

	Graph map;
	//vector<string> childrenAdresses;
	Vertex school;
	Vertex garage;
	vector<Vertex> schools;
	vector<Vertex> childrenVertices;    // vertex set
	unsigned int numberOfBus;
	FloydWarshall fw;
/*
	Matrix distances;
	vector<double> distancesFromSchool;
	vector<double> distancesToGarage;
	vector<vector<vector<unsigned>>> paths;
	vector<vector<unsigned>> pathsFromSchool;
	vector<vector<unsigned>> pathsToGarage;
*/
public:
	Network();
	Graph getMap();
	FloydWarshall getFloydWarshall();
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
	/*
	Matrix getDistances();
	vector<vector<vector<unsigned>>> getPaths();
	vector<double> getDistancesFromSchool();
	vector<double> getDistancesToGarage();
	vector<vector<unsigned>> getPathsFromSchool();
	vector<vector<unsigned>> getPathsToGarage();
*/


	void insertAddress(unsigned id);
	void removeAddress(unsigned id);
	unsigned int getNumberOfBus();
	void setNumberOfBus();

	void calculatePathMatrix(); //calculate Matrix with shortest path for each pair of vertices
	//void calculateBusPath();       //calculate shortest path passing by all the addresses

};
