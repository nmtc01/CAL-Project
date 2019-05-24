/*
 * Graph.cpp
 *
 */

#include "Graph.h"

//Constructors

Graph::Graph() {
	vertexSet = {};
	numEdges = 0;
}

Graph::Graph(string nodes_filename, string edges_filename, string tags_filename) {

	string line;
	numEdges = 0;


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

		double weight = sqrt( pow(vertexSet.at(id_dest).getX() - vertexSet.at(id_src).getX(), 2) + pow(vertexSet.at(id_dest).getY() - vertexSet.at(id_src).getY(), 2) );

		addEdge(id_src, id_dest, weight);
		addEdge(id_dest, id_src, weight);
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

			vertexSet.at(id_tag).setAmenity(amenity);
		}
	}
	tags.close();
}


//Useful methods
void Graph::addVertex(double x, double y) {
	unsigned new_id = vertexSet.size();

	vertexSet.push_back(Vertex(new_id, x, y) );
}

bool Graph::addEdge(unsigned first_id, unsigned sec_id, const double &weight) {
	if(first_id == sec_id || first_id > vertexSet.size() || sec_id > vertexSet.size())
		return false;

	vertexSet.at(first_id).addEdge(sec_id, weight);
	numEdges++;
	return true;
}

unsigned Graph::getVertexIndex(unsigned id) const {
	for (unsigned i = 0; i < vertexSet.size(); i++)
		if (vertexSet[i].id == id)
			return i;
	return -1;
}

unsigned Graph::getNumVertex() const {
	return vertexSet.size();
}
unsigned Graph::getNumEdges() const {
	return numEdges;
}

Vertex Graph::getVertex(unsigned id) const {
	return vertexSet.at(id);
}


//Get methods
vector<Vertex> Graph::getVertexSet() {
	return vertexSet;
}



