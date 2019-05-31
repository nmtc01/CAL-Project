/*
 * Interface.cpp
 *
 */

#include "Interface.h"
#include <ctime>

Network* network = new Network();
vector<unsigned> visitedVerticesIds;

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
	cout << "\t[4]: Leave the program" << endl << endl;
}

void welcome_menu_interface() {
	while(true) {
		big_header("Graph Loading");
		print_welcome_menu();

		switch(prompt_menu(1, 4)) {

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
	cout << "\t[2]: Go to the school network menu" << endl;
	cout << "\t[3]: Go to the path calculation menu" << endl;
	cout << "\t[4]: See some graph stats" << endl;
	cout << "\t[5]: Reset network" << endl;
	cout << "\t[6]: Go back to the welcome menu" << endl << endl;
}

void graph_menu_interface() {
	while(true) {
		big_header("Graph Menu");
		print_graph_menu();

		switch(prompt_menu(1, 6)) {

			case 1:
			{
				cout << endl << "Loading Map..." << endl << endl;
				graphviewer_option();
				break;
			}
			case 2:
			{
				network_menu_interface();
				break;
			}
			case 3:
			{
				path_menu_interface();
				break;
			}
			case 4:
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
			case 5:
			{
				Graph g= network->getMap();
				network = new Network();
				network->loadMap(g);
				break;
			}
			case 6:
			{
				cout << endl << "Returning to the welcome menu..." << endl << endl;
				return;
			}
		}
	}
}

//Functions for the network menu
void print_network_menu() {
	cout << "Would you like to: " << endl << endl;
	cout << "\t[1]: Add a student house" << endl;
	cout << "\t[2]: Set the school" << endl;
	cout << "\t[3]: Set the garage location" << endl;
	cout << "\t[4]: Set the bus capacity" << endl;
	cout << "\t[5]: Remove a student house" << endl;
	cout << "\t[6]: Show the school, garage and students" << endl;
	cout << "\t[7]: Go back to the graph menu" << endl << endl;
}

void network_menu_interface() {
	while(true) {
		big_header("School Network Menu");
		print_network_menu();

		switch(prompt_menu(1,7)) {
			case 1:
			{
				small_header("Student house");

				if (network->getGarageId() == NOT_FOUND) {
					cout << endl << endl << "Please, set the garage address before inserting other addresses" << endl;
					break;
				}

				cout << endl << endl << "Insert the id of the vertex for the students' house" << endl;
				unsigned id = NOT_FOUND;
				input_receiver(id);

				DFS dfs(network->getMap());
				cout << endl << "Performing a Depth First Search (DFS) for the selected vertex..." << endl;

				clock_t start = clock();
				bool isPossible = dfs.isPossible(id, network->getGarageId());
				clock_t end = clock();

				double ms = ((double)1000*(end - start))/CLOCKS_PER_SEC;
				cout << "Task finished in " << ms << " miliseconds" << endl;

				if(!isPossible) {
					cout << endl << endl << "It's impossible to reach the garage from the inserted vertex" << endl;
					cout << endl << "Returning to the network menu..." << endl << endl;
					break;
				}

				network->insertAddress(id);
				cout << endl << endl << "The address in ID " << id << " was successfuly inserted as a student's house" << endl << endl;
				break;
			}
			case 2:
			{
				small_header("School");

				if (network->getGarageId() == NOT_FOUND) {
					cout << endl << endl << "Please, choose the garage address before inserting other addresses" << endl;
					break;
				}

				cout << endl << endl << "Insert the id of the vertex for the school" << endl;
				unsigned id = NOT_FOUND;
				input_receiver(id);

				DFS dfs(network->getMap());
				cout << endl << "Performing a Depth First Search (DFS) for the selected vertex..." << endl;

				clock_t start = clock();
				bool isPossible = dfs.isPossible(id, network->getGarageId());
				clock_t end = clock();

				double ms = ((double)1000*(end - start))/CLOCKS_PER_SEC;
				cout << "Task finished in " << ms << " miliseconds" << endl;

				if(!isPossible) {
					cout << endl << endl << "It's impossible to reach the garage from the inserted vertex" << endl;
					cout << endl << "Returning to the network menu..." << endl << endl;
					break;
				}

				network->setSchool(id);
				cout << endl << endl << "The address in ID " << id << " was successfuly set as the school" << endl << endl;
				break;
			}
			case 3:
			{
				small_header("Garage");

				cout << endl << endl << "Insert the id of the vertex for the garage" << endl;
				cout << "Please mind that setting a new garage will clear the students' and schools' adresses" << endl;
				unsigned id = NOT_FOUND;
				input_receiver(id);

				//Resets the network
				Graph g= network->getMap();
				network = new Network();
				network->loadMap(g);

				network->setGarage(id);
				cout << "The address in ID " << id << " was successfuly set as the garage" << endl;
				break;
			}
			case 4:
			{
				small_header("Bus capacity");

                cout << endl << endl << "Insert the bus capacity" << endl;
                unsigned cap;
                input_receiver(cap);
                network->setBusCapacity(cap);

                break;
			}
			case 5:
			{
				small_header("Student removal");

				cout << endl << endl << "Insert the id of the vertex for the students' house that you want to remove" << endl;
				unsigned id = NOT_FOUND;
				input_receiver(id);

				if (network->removeAddress(id))
					cout << "Successfuly removed the student house at the address with ID " << id << endl;
				else
					cout << "The address in " << id << " is not a student house" << endl;
				break;
			}
			case 6:
			{
				small_header("Show everything");

				if(network->getGarageId() == NOT_FOUND)
					cout << "No garage is set in the network" << endl << endl;
				else
					cout << "The garage is at the vertex with ID " << network->getGarageId() << endl << endl;

				if(network->getSchoolId() == NOT_FOUND)
					cout << "No school is set in the network" << endl << endl;
				else
					cout << "The school is at the vertex with ID " << network->getSchoolId() << endl << endl;

				if(network->getChildrenIds().size() == 0)
					cout << "There are no students in the network" << endl;
				else {
					cout << "The students are the vertexes:" << endl;
					for(unsigned i = 0; i < network->getChildrenIds().size(); i++)
						cout << "ID " << network->getChildrenIds().at(i) << ": " << network->getChildrenVertices().at(i).getAmenity() << endl;
				}

				cout << endl << endl;
				break;
			}
			case 7:
			{
				cout << endl << "Returning to the graph menu..." << endl;
				return;
			}
		}
	}
}


//Functions for the paths menu
void print_path_menu() {
	cout << "Would you like to: " << endl << endl;
	cout << "\t[1]: Calculate with Nearest Neighbour" << endl;
	cout << "\t[2]: Calculate with Branch and Bound" << endl;
	cout << "\t[3]: Calculate with Bellman-Held-Karp" << endl;
	cout << "\t[4]: Calculate the paths matrix" << endl;
	cout << "\t[5]: Go back to the graph menu" << endl << endl;
}

void path_menu_interface() {
	while(true) {
		big_header("Paths Menu");
		print_path_menu();

		switch(prompt_menu(1,5)) {
			case 1:
			{
				small_header("Nearest Neighbour");

				clock_t start,end;
				double ms;

				//Updates the path matrix if needed
				if (!network->getFloydWarshall().alreadyPerformed()) {
					cout << endl << endl << "Calculating FloydWarshall..." << endl;

					start = clock();
					network->calculatePathMatrix();
					end = clock();
					ms = ((double)1000*(end - start))/CLOCKS_PER_SEC;

					cout << "Task performed in " << ms << " miliseconds" << endl;
				}

				//Calculates the path with Nearest Neighbour
				cout << endl << endl << "Calculating the path with Nearest Neighbour..." << endl;
				NearestNeighbour NN = NearestNeighbour(network->getMap(), network->getFloydWarshall());

				start = clock();
				NN.perform(network->getSchoolId(), network->getGarageId(), network->getChildrenIds(), network->getBusCapacity());
				end = clock();
				ms = ((double)1000*(end - start))/CLOCKS_PER_SEC;

				cout << endl << "Task performed in " << ms << " miliseconds" << endl << endl;

				visitedVerticesIds = NN.getCompletePath();

				//Displays the path and total distance
				if(network->getBusCapacity() == NOT_FOUND) {
					cout << "Path found: "; NN.printPath();
					cout << "Total distance: " << NN.getDistance() << endl;
				}

				else {
					cout << "Paths found: " << endl;
					NN.printPaths();
					cout << endl << "Total distance: " << NN.getDistance() << endl;
				}

				break;
			}
			case 2:
			{
				small_header("Branch and Bound");

				clock_t start,end;
				double ms;

				//Updates the path matrix if needed
				if (!network->getFloydWarshall().alreadyPerformed()) {
					cout << endl << endl << "Calculating FloydWarshall..." << endl;

					start = clock();
					network->calculatePathMatrix();
					end = clock();
					ms = ((double)1000*(end - start))/CLOCKS_PER_SEC;

					cout << "Task performed in " << ms << " miliseconds" << endl;
				}

				//Calculates the path with Branch and Bound
				cout << endl << endl << "Calculating the path with Branch and Bound..." << endl;
				BranchAndBound BB(network->getMap(), network->getFloydWarshall());

				start = clock();
				BB.perform(network->getSchoolId(), network->getGarageId(), network->getChildrenIds());
				end = clock();
				ms = ((double)1000*(end - start))/CLOCKS_PER_SEC;

				cout << endl << "Task performed in " << ms << " miliseconds" << endl << endl;

				visitedVerticesIds = BB.getPath();

				//Displays the path and total distance
				cout << "Path found: "; BB.printPath();
				cout << "Total distance: " << BB.getDistance() << endl;
				break;
			}
			case 3:
			{
				small_header("Held-Karp");

				clock_t start,end;
				double ms;

				//Updates the path matrix if needed
				if (!network->getFloydWarshall().alreadyPerformed()) {
					cout << endl << endl << "Calculating FloydWarshall..." << endl;

					start = clock();
					network->calculatePathMatrix();
					end = clock();
					ms = ((double)1000*(end - start))/CLOCKS_PER_SEC;

					cout << endl << "Task performed in " << ms << " miliseconds" << endl;
				}

				//Calculating path with Bellman-Held-Karp
				cout << endl << endl << "Calculating the path with Bellman-Held-Karp..." << endl;
				HeldKarp HK(network->getMap(), network->getFloydWarshall());

				start = clock();
				HK.perform(network->getSchoolId(), network->getGarageId(), network->getChildrenIds());
				end = clock();
				ms = ((double)1000*(end - start))/CLOCKS_PER_SEC;

				cout << endl << "Task performed in " << ms << " miliseconds" << endl << endl;

				visitedVerticesIds = HK.getPath();

				//Displays the path found and total distance
				cout << "Path found: "; HK.printPath();
				cout << "Total distance: " << HK.getDistance() << endl;

				break;
			}
			case 4:
			{
				small_header("Path Matrix");
				network->calculatePathMatrix();
				break;
			}
			case 5:
			{
				cout << "Returning to the graph menu..." << endl << endl;
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

	bool isSchool = false;
	bool isHouse = false;
	bool isGarage = false;

	for(Vertex node: nodes) {

		for(Vertex school : network->getSchools())
			if(node.getId() == school.getId()) {
				gv->setVertexColor(node.getId(), RED);
				isSchool = true;
			}

		if(!isSchool)
			for(Vertex house : network->getChildrenVertices())
				if(node.getId() == house.getId()) {
					gv->setVertexColor(node.getId(), GREEN);
					isHouse = true;
				}

		if(!isSchool && !isHouse)
			if(node.getId() == network->getGarageId()) {
				gv->setVertexColor(node.getId(), BLACK);
				isGarage = true;
			}

		if(!isSchool && !isHouse && !isGarage)
			for(unsigned id : visitedVerticesIds)
				if(node.getId() == id) {
					gv->setVertexColor(node.getId(), BLUE);
				}

		gv->setVertexLabel(node.getId(), to_string(node.getId()));
		gv->addNode(node.getId(), node.getX()-xmin, node.getY()-ymin);

		isSchool = false;
		isHouse = false;
		isGarage = false;
	}


	int idEdge = 0;
	for(Vertex node : nodes) {
		vector<Edge> edges = node.getEdges();

		for(Edge edge : edges){
			gv->addEdge(idEdge, node.getId(), edge.getDestinyId(), EdgeType::DIRECTED);
			idEdge++;
		}
	}
}

