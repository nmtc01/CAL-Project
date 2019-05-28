/*
 * Interface.cpp
 *
 */

#include "Interface.h"
#include <ctime>

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
	cout << "\t[4]: Set the garage" << endl;
	cout << "\t[5]: Remove a student house" << endl;
	cout << "\t[6]: Set bus capacity" << endl;
	cout << "\t[7]: Calculate with nearest neighbour" << endl;
	cout << "\t[8]: Calculate with Branch and Bound" << endl;
	cout << "\t[9]: Calculate with Bellman-Held-Karp" << endl;
	cout << "\t[10]: See some graph stats (just for testing)" << endl;
	cout << "\t[11]: See the schools' list" << endl;
	cout << "\t[12]: See the students houses list" << endl;
	cout << "\t[13]: Calculate paths matrix" << endl;
	cout << "\t[14]: Reset network" << endl;
	cout << "\t[15]: Go back to the graph loading menu" << endl << endl;
}

void graph_menu_interface() {
	while(true) {
		big_header("Graph Menu");
		print_graph_menu();

		switch(prompt_menu(1, 15)) {

			case 1:
			{
				cout << endl << "Loading Map..." << endl << endl;
				graphviewer_option();
				break;
			}
			case 2:
			{
				cout << endl << endl << "Insert the id of the vertex for the students' house" << endl;
				unsigned id = NOT_FOUND;
				input_receiver(id);
				clock_t start,end;
				double ms;
				if (network->getGarageId() == NOT_FOUND) {
					cout << endl << endl << "Please, choose the garage address before inserting other addresses" << endl;
					break;
				}
				if (!network->getFloydWarshall().alreadyPerformed()) {
					cout << endl << endl << "Calculating FloydWarshall" << endl;
					start = clock();
					network->calculatePathMatrix();
					end = clock();
					ms = ((double)1000*(end - start))/CLOCKS_PER_SEC;
					cout << endl << "Calculated FloydWarshall in " << ms << " miliseconds" << endl;
				}
				if (network->getFloydWarshall().alreadyPerformed()){
					if (network->getFloydWarshall().getDistance(id,network->getGarage().getId()) != INF){
						network->insertAddress(id);
						cout << "Successfuly inserted address " << id << endl;
					}
					else cout << "Impossible to reach garage from the vertex " << id << ". Please try another vertex" << endl;

				}
				break;
			}
			case 3:
			{

				if (network->getGarageId() == NOT_FOUND) {
					cout << endl << endl << "Please, choose the garage address before inserting other addresses" << endl;
					break;
				}
				clock_t start,end;
				double ms;
				if (!network->getFloydWarshall().alreadyPerformed()) {
					cout << endl << endl << "Calculating FloydWarshall" << endl;
					start = clock();
					network->calculatePathMatrix();
					end = clock();
					ms = ((double)1000*(end - start))/CLOCKS_PER_SEC;
					cout << endl << "Calculated FloydWarshall in " << ms << " miliseconds" << endl;
				}
				cout << endl << endl << "Insert the id of the vertex for the school" << endl;
				unsigned id = NOT_FOUND;
				input_receiver(id);
				if (network->getFloydWarshall().getDistance(id,network->getGarageId()) != INF){
					network->setSchool(id);
					cout << "Successfuly set school at address " << id << endl;
				}
				else cout << "Impossible to reach garage from the vertex " << id << ". Please try another vertex" << endl;
				break;
			}
			case 4:
			{
				cout << endl << endl << "Insert the id of the vertex for the garage" << endl;
				unsigned id = NOT_FOUND;
				input_receiver(id);
				network->setGarage(id);
				cout << "Set garage at address " << id << endl;
				break;
			}
			case 5:
			{
                cout << endl << endl << "Insert the id of the vertex for the students' house that you want to remove" << endl;
				unsigned id = NOT_FOUND;
				input_receiver(id);
                if (network->removeAddress(id)) cout << "Successfuly removed address " << id << endl;
				else cout << "Address " << id << " is not a student house" << endl;
				break;
			}
			case 6:
			{
                cout << endl << endl << "Insert the bus capacity" << endl;
                unsigned cap;
                input_receiver(cap);
                network->setBusCapacity(cap);
				break;
			}

			case 7:
			{
				clock_t start,end;
				double ms;
				if (!network->getFloydWarshall().alreadyPerformed()) {
					cout << endl << endl << "Calculating FloydWarshall" << endl;
					start = clock();
					network->calculatePathMatrix();
					end = clock();
					ms = ((double)1000*(end - start))/CLOCKS_PER_SEC;
					cout << endl << "Calculated FloydWarshall in " << ms << " miliseconds" << endl;
				}
				NearestNeighbour NN;
				if (network->getFloydWarshall().alreadyPerformed()){
					cout << endl << endl << "Calculating with nearest neighbour algorithm" << endl;
					NN = NearestNeighbour(network->getMap(), network->getFloydWarshall());
				}
				else {
					cout << endl << endl << "Calculating with nearest neighbour algorithm" << endl;
					NN = NearestNeighbour(network->getMap(), network->getDijkstra());
				}
				start = clock();
				NN.perform(network->getSchoolId(), network->getGarageId(), network->getChildrenIds(), network->getBusCapacity());
				end = clock();
				ms = ((double)1000*(end - start))/CLOCKS_PER_SEC;
				cout << endl << "Calculated NearestNeighbour in " << ms << " miliseconds" << endl;
				cout << "Path found: " << endl;
				NN.printPath();
				cout << endl << "Total distance: " << NN.getDistance() << endl;
				break;
			}
			case 8:
			{

				clock_t start,end;
				double ms;
				if (!network->getFloydWarshall().alreadyPerformed()) {
					cout << endl << endl << "Calculating FloydWarshall" << endl;
					start = clock();
					network->calculatePathMatrix();
					end = clock();
					ms = ((double)1000*(end - start))/CLOCKS_PER_SEC;
					cout << endl << "Calculated FloydWarshall in " << ms << " miliseconds" << endl;
				}
				cout << endl << endl << "Calculating with Branch and Bound algorithm" << endl;
				BranchAndBound BB(network->getMap(), network->getFloydWarshall());
				start = clock();
				BB.perform(network->getSchoolId(), network->getGarageId(), network->getChildrenIds());
				end = clock();
			    ms = ((double)1000*(end - start))/CLOCKS_PER_SEC;
				cout << endl << "Calculated Branch and Bound in " << ms << " miliseconds" << endl;
				cout << "Path found: " << endl;
				BB.printPath();
				cout << endl << "Total distance: " << BB.getDistance() << endl;
				break;
			}
			case 9:
			{
				clock_t start,end;
				double ms;
				if (!network->getFloydWarshall().alreadyPerformed()) {
					cout << endl << endl << "Calculating FloydWarshall" << endl;
					start = clock();
					network->calculatePathMatrix();
					end = clock();
					ms = ((double)1000*(end - start))/CLOCKS_PER_SEC;
					cout << endl << "Calculated FloydWarshall in " << ms << " miliseconds" << endl;
				}
				cout << endl << endl << "Calculating with Bellman-Held-Karp algorithm" << endl;
				HeldKarp HK(network->getMap(), network->getFloydWarshall());
				start = clock();
				HK.perform(network->getSchoolId(), network->getGarageId(), network->getChildrenIds());
				end = clock();
			    ms = ((double)1000*(end - start))/CLOCKS_PER_SEC;
				cout << endl << "Calculated Bellman-Held-Karp in " << ms << " miliseconds" << endl;
				cout << "Path found: " << endl;
				HK.printPath();
				cout << endl << "Total distance: " << HK.getDistance() << endl;

				break;
			}
			case 10:
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
			case 11:
			{
				small_header("Schools");

				if(network->getSchools().size() == 0)
					cout << "There are no schools in the network" << endl;
				else {
					for(unsigned i = 0; i < network->getSchools().size(); i++)
						cout << "ID " << network->getSchools().at(i).getId() << ": " << network->getSchools().at(i).getAmenity() << endl;
				}

				cout << endl << endl;
				break;
			}
			case 12:
			{
				small_header("Students houses");

				if(network->getChildrenIds().size() == 0)
					cout << "There are no students in the network" << endl;
				else {
					for(unsigned i = 0; i < network->getChildrenIds().size(); i++)
						cout << "ID " << network->getChildrenIds().at(i) << ": " << network->getChildrenVertices().at(i).getAmenity() << endl;
				}

				cout << endl << endl;
				break;
			}
			case 13:
			{
				network->calculatePathMatrix();
				break;
			}
			case 14:
			{
				Graph g= network->getMap();
				network = new Network();
				network->loadMap(g);
				break;
			}
			case 15:
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



/*** WORK IN PROGRESS ***/

void print_network_menu() {
	cout << "Would you like to: " << endl << endl;
	cout << "\t[1]: Add a student house" << endl;
	cout << "\t[2]: Add a school" << endl;
	cout << "\t[3]: Set the garage location" << endl;
	cout << "\t[4]: Remove a student house" << endl;
	cout << "\t[5]: Remove a school" << endl;
	cout << "\t[6]: Go back to the graph menu" << endl << endl;
}

void network_menu_interface() {
	while(true) {
		big_header("School Network Menu");
		print_network_menu();

		switch(prompt_menu(1,6)) {
		case 1:
		{
			cout << endl << endl << "Insert the id of the vertex for the students' house" << endl;
			unsigned id = NOT_FOUND;
			input_receiver(id);
			network->insertAddress(id);
			cout << "Successfuly inserted address " << id << endl;
			break;
		}
		case 2:
		{
			cout << endl << endl << "Insert the id of the vertex for the school" << endl;
			unsigned id = NOT_FOUND;
			input_receiver(id);
			network->setSchool(id);
			cout << "Successfuly set school at address " << id << endl;
			break;
		}
		case 3:
		{
			cout << endl << endl << "Insert the id of the vertex for the garage" << endl;
			unsigned id = NOT_FOUND;
			input_receiver(id);
			network->setGarage(id);
			cout << "Set garage at address " << id << endl;
			break;
		}
		case 4:
		{
            cout << endl << endl << "Insert the id of the vertex for the students' house that you want to remove" << endl;
			unsigned id = NOT_FOUND;
			input_receiver(id);
            if (network->removeAddress(id)) cout << "Successfuly removed address " << id << endl;
			else cout << "Address " << id << " is not a student house" << endl;
			break;
		}
		case 5:
		{
			break;
		}
		case 6:
		{
			return;
		}

		}
	}
}



