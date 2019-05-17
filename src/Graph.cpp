/*
 * Graph.cpp
 *
 *  Created on: 17 de mai de 2019
 *      Author: Estudio
 */


#include "Graph.h"
using namespace std;

template <class T>
int Graph<T>::getNumVertex() const {
	return vertexSet.size();
}

template <class T>
vector<Vertex<T> *> Graph<T>::getVertexSet() const {
	return vertexSet;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
template <class T>
Vertex<T> * Graph<T>::findVertex(const T &in) const {
	for (auto v : vertexSet)
		if (v->info == in)
			return v;
	return nullptr;
}

/*
 * Finds the index of the vertex with a given content.
 */
template <class T>
int Graph<T>::findVertexIdx(const T &in) const {
	for (unsigned i = 0; i < vertexSet.size(); i++)
		if (vertexSet[i]->info == in)
			return i;
	return -1;
}
/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
template <class T>
bool Graph<T>::addVertex(const T &in) {
	if (findVertex(in) != nullptr)
		return false;
	vertexSet.push_back(new Vertex<T>(in));
	return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
	auto v1 = findVertex(sourc);
	auto v2 = findVertex(dest);
	if (v1 == nullptr || v2 == nullptr)
		return false;
	v1->addEdge(v2, w);
	return true;
}


/**************** Single Source Shortest Path algorithms ************/

/**
 * Initializes single source shortest path data (path, dist).
 * Receives the content of the source vertex and returns a pointer to the source vertex.
 * Used by all single-source shortest path algorithms.
 */
template<class T>
Vertex<T> * Graph<T>::initSingleSource(const T &origin) {
	for(auto v : vertexSet) {
		v->dist = INF;
		v->path = nullptr;
	}
	auto s = findVertex(origin);
	s->dist = 0;
	return s;
}

/**
 * Analyzes an edge in single source shortest path algorithm.
 * Returns true if the target vertex was relaxed (dist, path).
 * Used by all single-source shortest path algorithms.
 */
template<class T>
inline bool Graph<T>::relax(Vertex<T> *v, Vertex<T> *w, double weight) {
	if (v->dist + weight < w->dist) {
		w->dist = v->dist + weight;
		w->path = v;
		return true;
	}
	else
		return false;
}
/**
* Dijkstra algorithm.
*/
template<class T>
void Graph<T>::dijkstraShortestPath(const T &origin) {
	auto s = initSingleSource(origin);
	MutablePriorityQueue<Vertex<T>> q;
	q.insert(s);
	while ( ! q.empty() ) {
		auto v = q.extractMin();
		for (auto e : v->adj) {
			auto oldDist = e.dest->dist;
			if (relax(v, e.dest, e.weight)) {
				if (oldDist == INF)
					q.insert(e.dest);
				else
					q.decreaseKey(e.dest);
			}
		}
	}
}

template<class T>
vector<T> Graph<T>::getPath(const T &origin, const T &dest) const{
	vector<T> res;
	auto v = findVertex(dest);
	if (v == nullptr || v->dist == INF) // missing or disconnected
		return res;
	for ( ; v != nullptr; v = v->path)
		res.push_back(v->info);
	reverse(res.begin(), res.end());
	return res;
}

template<class T>
void Graph<T>::unweightedShortestPath(const T &orig) {
	auto s = initSingleSource(orig);
	queue< Vertex<T>* > q;
	q.push(s);
	while( ! q.empty() ) {
		auto v = q.front();
		q.pop();
		for(auto e: v->adj)
			if (relax(v, e.dest, 1))
				q.push(e.dest);
	}
}

template<class T>
void Graph<T>::bellmanFordShortestPath(const T &orig) {
	initSingleSource(orig);
	for (unsigned i = 1; i < vertexSet.size(); i++)
		for (auto v: vertexSet)
			for (auto e: v->adj)
				relax(v, e.dest, e.weight);
	for (auto v: vertexSet)
		for (auto e: v->adj)
			if (relax(v, e.dest, e.weight))
				cout << "Negative cycle!" << endl;
}


/**************** All Pairs Shortest Path  ***************/

template <class T>
void deleteMatrix(T **m, int n) {
	if (m != nullptr) {
		for (int i = 0; i < n; i++)
			if (m[i] != nullptr)
				delete [] m[i];
		delete [] m;
	}
}

template <class T>
Graph<T>::~Graph() {
	deleteMatrix(W, vertexSet.size());
	deleteMatrix(P, vertexSet.size());
}

template<class T>
void Graph<T>::floydWarshallShortestPath() {
	unsigned n = vertexSet.size();
	deleteMatrix(W, n);
	deleteMatrix(P, n);
	W = new double *[n];
	P = new int *[n];
	for (unsigned i = 0; i < n; i++) {
		W[i] = new double[n];
		P[i] = new int[n];
		for (unsigned j = 0; j < n; j++) {
			W[i][j] = i == j? 0 : INF;
			P[i][j] = -1;
		}
		for (auto e : vertexSet[i]->adj) {
			int j = findVertexIdx(e.dest->info);
			W[i][j]  = e.weight;
			P[i][j]  = i;
		}
	}

	for(unsigned k = 0; k < n; k++)
		for(unsigned i = 0; i < n; i++)
			for(unsigned j = 0; j < n; j++) {
				if(W[i][k] == INF || W[k][j] == INF)
					continue; // avoid overflow
				int val = W[i][k] + W[k][j];
				if (val < W[i][j]) {
					W[i][j] = val;
					P[i][j] = P[k][j];
				}
			}
}


template<class T>
vector<T> Graph<T>::getfloydWarshallPath(const T &orig, const T &dest) const{
	vector<T> res;
	int i = findVertexIdx(orig);
	int j = findVertexIdx(dest);
	if (i == -1 || j == -1 || W[i][j] == INF) // missing or disconnected
		return res;
	for ( ; j != -1; j = P[i][j])
		res.push_back(vertexSet[j]->info);
	reverse(res.begin(), res.end());
	return res;
}





