/*
 * Dijkstra.h
 *
 */

#pragma once

#include <unordered_map>
#include <queue>
#include <functional>

#include "Graph.h"

class Dijkstra {
	Graph graph;
	VertexHashTable visitedVertices;
	priority_queue<unsigned, vector<unsigned>, std::greater<unsigned>> idsQueue; //MutablePriorityQueue<Vertex> pQueue;
	unordered_map<unsigned, unsigned> paths;
	unordered_map<unsigned, double> distances;

	//Stores the last calculated solution
	vector<unsigned> solution;

	//Useful private functions
	void resetDataStructures();
	vector<unsigned> getPath(unsigned sourceId, unsigned destinyId);


public:
	//Constructor
	Dijkstra(const Graph &graph);

	//Calculates the optimal path between source and destiny
	vector<unsigned> perform(unsigned sourceId, unsigned destinyId);

};
