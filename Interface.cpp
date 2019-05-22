/*
 * Interface.cpp
 *
 *  Created on: 22/05/2019
 *      Author: mike
 */
#include "Interface.h"

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

                                graph_menu_interface(graph);

                                break;
                        }
                        case 2:
                        {
                                cout << endl << "Loading Gondomar..." << endl << endl;

                                string nodes_file = "src/Maps/Gondomar/T05_nodes_X_Y_Gondomar.txt";
                                string edges_file = "src/Maps/Gondomar/T05_edges_Gondomar.txt";
                                string tags_file = "src/Maps/Gondomar/T05_tags_Gondomar.txt";

                                Graph graph(nodes_file, edges_file, tags_file);

                                graph_menu_interface(graph);

                                break;
                        }
                        case 3:
                        {
                                cout << endl << "Loading Porto..." << endl << endl;

                                string nodes_file = "src/Maps/Porto/T05_nodes_X_Y_Porto.txt";
                                string edges_file = "src/Maps/Porto/T05_edges_Porto.txt";
                                string tags_file = "src/Maps/Porto/T05_tags_Porto.txt";

                                Graph graph(nodes_file, edges_file, tags_file);

                                graph_menu_interface(graph);

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
        cout << "\t[2]: Add a student house" << endl;
        cout << "\t[3]: Add a school" << endl;
        cout << "\t[4]: Calculate a path" << endl;
        cout << "\t[5]: See some graph stats (just for testing)" << endl;
        cout << "\t[6]: Go back to the graph loading menu" << endl << endl;
}

void graph_menu_interface(Graph &graph) {
        while(true) {
                big_header("Graph Menu");
                print_graph_menu();

                switch(prompt_menu(1, 6)) {

                        case 1:
                        {
                                cout << endl << "NOT YET IMPLEMENTED" << endl << endl;

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

                                int edge_counter = 0;
                                for(auto vertex : graph.getVertexSet()) {
                                        vector<Edge<string>> edges = vertex->getOutEdges();

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
                                return;
                        }

                }
        }
}
