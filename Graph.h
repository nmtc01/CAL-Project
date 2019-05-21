/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <stdlib.h>
#include <iostream>
#include <limits>
#include <algorithm>
#include <unordered_set>
#include <map>
#include <fstream>
#include <math.h>
#include "Edge.h"


using namespace std;

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;

#define INF std::numeric_limits<double>::max()


/*************************** Graph  **************************/

template <class T>
class Graph {
	vector<Vertex<T> *> vertexSet;    // vertex set

	// Fp05
	Vertex<T> * initSingleSource(const T &orig);
	bool relax(Vertex<T> *v, Vertex<T> *w, double weight);
	double ** W = nullptr;   // dist
	int **P = nullptr;   // path
	int findVertexIdx(const T &in) const;


public:
	//Constructor
	Graph(string nodes_filename, string edges_filename, string tags_filename);

	//Useful
	void addVertex(double x, double y, T in);
	void addVertex(double x, double y); 	// ---> probably temporary
	bool addEdge(unsigned first_id, unsigned sec_id, const double &weight);
	unsigned getVertexIndex(unsigned id);


	/*** Class Functions ***/

	Vertex<T> *findVertex(const T &in) const;
	bool addVertex(const T &in);
	bool addEdge(const T &sourc, const T &dest, double w);
	int getNumVertex() const;
	vector<Vertex<T> *> getVertexSet() const;

	// Fp05 - single source
	void dijkstraShortestPath(const T &s);
	void unweightedShortestPath(const T &s);
	void bellmanFordShortestPath(const T &s);
	vector<T> getPath(const T &origin, const T &dest) const;

	// Fp05 - all pairs
	void floydWarshallShortestPath();
	vector<T> getfloydWarshallPath(const T &origin, const T &dest) const;
	~Graph();

	// Fp07 - minimum spanning tree
	vector<Vertex<T>*> calculatePrim();
	vector<Vertex<T>*> calculateKruskal();
};



#endif /* GRAPH_H_ */
