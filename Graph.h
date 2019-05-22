/*
 * Graph.h
 */
#ifndef GRAPH_CPP_
#define GRAPH_CPP_

#include <stdlib.h>
#include <iostream>
#include <limits>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <fstream>
#include <math.h>
#include "Vertex.h"


using namespace std;


#define INF std::numeric_limits<double>::max()


/*************************** Graph  **************************/


class Graph {
	vector<Vertex *> vertexSet;    // vertex set

	// Fp05
	//Vertex * initSingleSource(const unsigned &orig);
	bool relax(Vertex *v, Vertex *w, double weight);
	//double ** W = nullptr;   // dist
	//int **P = nullptr;   // path
	int findVertexIdx(const unsigned in) const;


public:
	//Constructor
	Graph(string nodes_filename, string edges_filename, string tags_filename);

	//Useful
	//bool addVertex(const unsigned id);
	void addVertex(double x, double y); 	// ---> probably temporary
	bool addEdge(unsigned first_id, unsigned sec_id, const double weight);
	unsigned getVertexIndex(unsigned id);
	void setVerticesNotVisited();

	/*** Class Functions ***/

	Vertex *findVertex(const unsigned in) const;
	//bool addVertex(const unsigned &in);
	//bool addEdge(const unsigned &sourc, const unsigned &dest, double w);
	int getNumVertex() const;
	vector<Vertex *> getVertexSet() const;

	// Fp05 - single source
	/*
	void dijkstraShortestPath(const unsigned &s);
	void unweightedShortestPath(const unsigned &s);
	void bellmanFordShortestPath(const unsigned &s);
	vector getPath(const unsigned &origin, const unsigned &dest) const;
*/
	// Fp05 - all pairs
	/*void floydWarshallShortestPath();
	vector<unsigned> getfloydWarshallPath(const unsigned &origin, const unsigned &dest) const;*/
	~Graph();

	// Fp07 - minimum spanning tree
	/*
	vector<Vertex*> calculatePrim();
	vector<Vertex*> calculateKruskal();*/
};


#endif /* GRAPH_CPP_ */
