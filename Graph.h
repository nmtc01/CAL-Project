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


Graph::Graph(string nodes_filename, string edges_filename, string tags_filename) {

	string line;


	/*** VERTEX READING ***/

	ifstream nodes(nodes_filename);

	getline(nodes, line);

	map<long unsigned,unsigned> ids;

	//added vertexes to graph will have sequential IDs
	unsigned current_id = 0;

	while(!nodes.eof()) {
		getline(nodes, line);

		long unsigned giant_id = stoul(line.substr(1, line.find_first_of(",")));
		line = line.substr(line.find_first_of(",") + 1);

		double x = stod(line.substr(0, line.find_first_of(",")));
		line = line.substr(line.find_first_of(",") + 1);

		double y = stod(line.substr(0, line.size() - 1));

		ids.insert(make_pair(giant_id, current_id));
		current_id++;

		//addVertex(x, y, "");
		addVertex(x, y);
	}
	nodes.close();


	/*** EDGE READING ***/

	ifstream edges(edges_filename);

	getline(edges, line);

	while(!edges.eof()) {
		getline(edges, line);

		long unsigned giant_id_src = stoul(line.substr(1, line.find_first_of(",")));
		line = line.substr(line.find_first_of(",") + 1);

		long unsigned giant_id_dest = stoul(line.substr(0, line.size()-1));

		unsigned id_src = ids.at(giant_id_src);
		unsigned id_dest = ids.at(giant_id_dest);

		double weight = sqrt( pow(vertexSet.at(id_dest)->getX() - vertexSet.at(id_src)->getX(), 2) + pow(vertexSet.at(id_dest)->getY() - vertexSet.at(id_src)->getY(), 2) );

		addEdge(id_src, id_dest, weight);
	}
	edges.close();


	/*** TAG READING ***/

	ifstream tags(tags_filename);

	getline(tags, line);

	while(!tags.eof()) {
		getline(tags, line);
		string amenity = line.substr(line.find_first_of("=") + 1);

		getline(tags, line);
		int repetitions = stoi(line);

		for(int rep = 0; rep < repetitions; rep++) {
			getline(tags, line);
			unsigned id_tag = ids.at(stoul(line));

			vertexSet.at(id_tag)->setAmenity(amenity);
		}
	}
	tags.close();
}


void Graph::addVertex(double x, double y) {
	unsigned new_id = vertexSet.size();

	vertexSet.push_back(new Vertex(new_id, x, y) );
}

//probably temporary
/*
void Graph::addVertex(double x, double y) {
	unsigned new_id = vertexSet.size();

	vertexSet.push_back(new Vertex(new_id, x, y) );
}*/

/*
bool Graph::addEdge(unsigned first_id, unsigned sec_id, const double &weight) {
	if(first_id == sec_id || first_id > vertexSet.size() || sec_id > vertexSet.size())
		return false;

	Vertex* v1 = vertexSet.at(first_id);
	Vertex* v2 = vertexSet.at(sec_id);

	v1->addEdge(v2, weight);

	return true;
}*/



int Graph::getNumVertex() const {
	return vertexSet.size();
}


vector<Vertex *> Graph::getVertexSet() const {
	return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */

Vertex * Graph::findVertex(const unsigned id) const {
	for (auto v : vertexSet)
		if (v->id == id)
			return v;
	return nullptr;
}

/*
 * Finds the index of the vertex with a given content.
 */

int Graph::findVertexIdx(const unsigned id) const {
	for (unsigned i = 0; i < vertexSet.size(); i++)
		if (vertexSet[i]->id == id)
			return i;
	return -1;
}

/*
 *  Adds a vertex with a given content or id (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
/*
bool Graph::addVertex(const unsigned id) {
	if (findVertex(id) != nullptr)
		return false;
	vertexSet.push_back(new Vertex(id));
	return true;
}*/

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
bool Graph::addEdge(const unsigned sourc, const unsigned dest, double w) {
	auto v1 = findVertex(sourc);
	auto v2 = findVertex(dest);
	if (v1 == nullptr || v2 == nullptr)
		return false;
	v1->addEdge(v2, w);
	return true;
}




void Graph::setVerticesNotVisited(){
	for (size_t i=0; i<vertexSet.size(); i++){
		vertexSet[i]->visited=false;
	}
}


#endif /* GRAPH_H_ */
