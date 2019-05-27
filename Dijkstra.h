/*
 * Dijkstra.h
 *
 */

#pragma once

#include <unordered_map>
#include <queue>
#include <functional>

#include "Graph.h"
#include "AbstractPathCalculator.h"

using namespace std;

//Pair with a vertex ID associated to its weight
typedef pair<unsigned, double> iPair;

//Auxiliary struct for priority queue comparison
struct prioritize {
	bool operator ()(iPair &p1, iPair &p2) {
		return p1.second > p2.second;
	}
};



class Dijkstra : public AbstractPathCalculator {
	Graph graph;
	VertexHashTable visitedVertices;
	priority_queue<iPair, vector<iPair>, prioritize> pQueue;
	unordered_map<unsigned, unsigned> paths;
	unordered_map<unsigned, double> distances;

	//Stores the last calculated solution
	vector<unsigned> solution;

	//Useful private functions
	void resetDataStructures();
	void addPathsMap(unsigned sourceId, unsigned destinyId);
	void addDistancesMap(unsigned id, double weight);
	bool wasVisited(unsigned id);


public:
	//Constructors
	Dijkstra();
	Dijkstra(const Graph &graph);
	double getDistance(unsigned sourceId, unsigned destinyId);
	vector<unsigned> getPath(unsigned sourceId, unsigned destinyId);

	//Calculates the optimal path between source and destiny
	vector<unsigned> perform(unsigned sourceId, unsigned destinyId);

};


