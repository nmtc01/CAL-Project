/*
 * Interface.cpp
 *
 */

#include "Interface.h"

Network* network = new Network();

//General header drawing function
void big_header(string message) {
	cout << endl << endl;

	for (unsigned int i=0 ; i<HEADER_SIZE_BIG ; i++) { cout << '-'; }
	cout << endl;
	for (unsigned int i=0 ; i<HEADER_SIZE_BIG ; i++) { cout << '-'; }
	cout << endl << "--";
	for (unsigned int i=0 ; i<HEADER_SIZE_BIG - 4 ; i++) { cout << ' '; }
	cout << "--" << endl << "--";
	for (unsigned int i=0 ; i<(HEADER_SIZE_BIG-message.size())/2 - 2 ; i++) { cout << ' '; }
	cout << message;
	for (unsigned int i=0 ; i<(HEADER_SIZE_BIG-message.size())/2 - 2 ; i++) { cout << ' '; }
	cout << "--" << endl << "--";
	for (unsigned int i=0 ; i<HEADER_SIZE_BIG - 4 ; i++) { cout << ' '; }
	cout << "--" << endl;
	for (unsigned int i=0 ; i<HEADER_SIZE_BIG ; i++) { cout << '-'; }
	cout << endl;
	for (unsigned int i=0 ; i<HEADER_SIZE_BIG ; i++) { cout << '-'; }
	cout << endl << endl;
}

void small_header(string message) {
	cout << endl << endl;

	for (unsigned int i=0 ; i<HEADER_SIZE_SMALL ; i++) { cout << '-'; }
	cout << endl << "--";
	for (unsigned int i=0 ; i<(HEADER_SIZE_SMALL-message.size())/2 - 2 ; i++) { cout << ' '; }
	cout << message;
	for (unsigned int i=0 ; i<(HEADER_SIZE_SMALL-message.size())/2 - 2 ; i++) { cout << ' '; }
	cout << "--" << endl;
	for (unsigned int i=0 ; i<HEADER_SIZE_SMALL ; i++) { cout << '-'; }
	cout << endl << endl;
}

//General menu prompt
int prompt_menu(int lower_bound, int upper_bound) {
	int input = -1;
	input_receiver(input);
	while(input < lower_bound || input > upper_bound) {
		cout << "Please insert an integer between " << lower_bound << " and " << upper_bound << endl << endl;
		input_receiver(input);
	}
	return input;
}


//Functions for the welcome menu
void print_welcome_menu() {
	cout << "Would you like to: " << endl << endl;
	cout << "\t[1]: Load a small map (Fafe)" << endl;
	cout << "\t[2]: Load a medium map (Gondomar)" << endl;
	cout << "\t[3]: Load a big map (Porto)" << endl;
	cout << "\t[4]: Load a huge map (Portugal)" << endl;
	cout << "\t[5]: Leave the program" << endl << endl;
}

void welcome_menu_interface() {
	while(true) {
		big_header("Graph Loading");
		print_welcome_menu();

		switch(prompt_menu(1, 5)) {

			case 1:
			{
				cout << endl << "Loading Fafe..." << endl << endl;

				string nodes_file = "src/Maps/Fafe/T05_nodes_X_Y_Fafe.txt";
				string edges_file = "src/Maps/Fafe/T05_edges_Fafe.txt";
				string tags_file = "src/Maps/Fafe/T05_tags_Fafe.txt";

				Graph graph(nodes_file, edges_file, tags_file);
				network->loadMap(graph);

				graph_menu_interface();

				break;
			}
			case 2:
			{
				cout << endl << "Loading Gondomar..." << endl << endl;

				string nodes_file = "src/Maps/Gondomar/T05_nodes_X_Y_Gondomar.txt";
				string edges_file = "src/Maps/Gondomar/T05_edges_Gondomar.txt";
				string tags_file = "src/Maps/Gondomar/T05_tags_Gondomar.txt";

				Graph graph(nodes_file, edges_file, tags_file);
				network->loadMap(graph);

				graph_menu_interface();

				break;
			}
			case 3:
			{
				cout << endl << "Loading Porto..." << endl << endl;

				string nodes_file = "src/Maps/Porto/T05_nodes_X_Y_Porto.txt";
				string edges_file = "src/Maps/Porto/T05_edges_Porto.txt";
				string tags_file = "src/Maps/Porto/T05_tags_Porto.txt";

				Graph graph(nodes_file, edges_file, tags_file);
				network->loadMap(graph);

				graph_menu_interface();

				break;
			}
			case 4:
			{
				cout << endl << "Loading Portugal..." << endl << endl;

				string nodes_file = "src/Maps/Portugal/T05_nodes_X_Y_Portugal.txt";
				string edges_file = "src/Maps/Portugal/T05_edges_Portugal.txt";
				string tags_file = "src/Maps/Portugal/T05_tags_Portugal.txt";

				Graph graph(nodes_file, edges_file, tags_file);
				network->loadMap(graph);

				graph_menu_interface();

				break;
			}
			case 5:
			{
				cout << endl << "Exiting..." << endl;
				return;
			}

		}
	}
}


//Functions for the graph menu
void print_graph_menu() {
	cout << "Would you like to: " << endl << endl;
	cout << "\t[1]: See the graph" << endl;
	cout << "\t[2]: Add a student house" << endl;
	cout << "\t[3]: Add a school" << endl;
	cout << "\t[4]: Calculate a path" << endl;
	cout << "\t[5]: See some graph stats (just for testing)" << endl;
	cout << "\t[6]: See the schools' list" << endl;
	cout << "\t[7]: Go back to the graph loading menu" << endl << endl;
}

void graph_menu_interface() {
	while(true) {
		big_header("Graph Menu");
		print_graph_menu();

		switch(prompt_menu(1, 7)) {

			case 1:
			{
				cout << endl << "Loading Map..." << endl << endl;
				graphviewer_option();
				break;
			}
			case 2:
			{
				cout << endl << "NOT YET IMPLEMENTED" << endl << endl;

				break;
			}
			case 3:
			{
				cout << endl << "NOT YET IMPLEMENTED" << endl << endl;

				break;
			}
			case 4:
			{
				cout << endl << "NOT YET IMPLEMENTED" << endl << endl;

				break;
			}
			case 5:
			{
				small_header("Statistics");
				Graph graph = network->getMap();

				int edge_counter = 0;
				for(auto vertex : graph.getVertexSet()) {
					vector<Edge> edges = vertex.getEdges();

					for(auto edge : edges)
						edge_counter++;
				}

				cout << "Number of nodes: " << graph.getVertexSet().size() << endl;
				cout << "Number of edges: " << edge_counter << endl;
				cout << endl << endl;

				break;
			}
			case 6:
			{
				small_header("Schools");

				if(network->getSchools().size() == 0)
					cout << "There are no schools in the network" << endl;
				else {
					for(unsigned i = 0; i < network->getSchools().size(); i++)
						cout << network->getSchools().at(i).getAmenity() << endl;
				}

				cout << endl << endl;
				break;
			}
			case 7:
			{
				return;
			}

		}
	}
}

void graphviewer_option() {
	GraphViewer *gv = new GraphViewer(1000, 1000, false);

	gv->setBackground("background.jpg");

	gv->createWindow(1000, 1000);
	gv->defineEdgeColor("blue");
	gv->defineVertexColor("yellow");

	Graph graph = network->getMap();

	vector<Vertex> nodes = graph.getVertexSet();
	double xmin = nodes.at(0).getX();
	double ymin = nodes.at(0).getY();
	for(Vertex node : nodes) {
		if (node.getX() < xmin)
			xmin = node.getX();
		if (node.getY() < ymin)
			ymin = node.getY();
	}

	for(Vertex node : nodes)
		gv->addNode(node.getId(), node.getX()-xmin, node.getY()-ymin);

	int idEdge = 0;
	for(Vertex node : nodes) {
		vector<Edge> edges = node.getEdges();

		for(Edge edge : edges){
			gv->addEdge(idEdge, node.getId(), edge.getDestinyId(), EdgeType::DIRECTED);
			idEdge++;
		}
	}
}



