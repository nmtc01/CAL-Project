/*
 * Graph.cpp
 *
 *  Created on: 17 de mai de 2019
 *      Author: Estudio
 */


#include "Graph.h"
using namespace std;

template <class T>
Graph<T>::Graph(string nodes_filename, string edges_filename, string tags_filename) {

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

		addVertex(x, y, "");
	}
	nodes.close();


	/*** EDGE READING ***/

	ifstream edges(edges_filename);

	getline(edges, line);

	while(!edges.eof()) {
		getline(nodes, line);

		long unsigned giant_id_src = stoul(line.substr(1, line.find_first_of(",")));
		line = line.substr(line.find_first_of(","));

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

		for(int rep : repetitions) {
			getline(tags, line);
			unsigned id_tag = ids.at(stoul(line));

			vertexSet.at(id_tag)->setAmenity(amenity);
		}
	}
	tags.close();
}

template <class T>
void Graph<T>::addVertex(double x, double y, T in) {
	unsigned new_id = vertexSet.size();

	vertexSet.push_back(new Vertex<T>(new_id, x, y, in) );
}

template <class T>
bool Graph<T>::addEdge(unsigned first_id, unsigned sec_id, const double &weight) {
	if(first_id == sec_id || first_id > vertexSet.size() || sec_id > vertexSet.size())
		return false;

	Vertex<T>* v1 = vertexSet.at(first_id);
	Vertex<T>* v2 = vertexSet.at(sec_id);

	v1->addEdge(v2);

	return true;
}


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





