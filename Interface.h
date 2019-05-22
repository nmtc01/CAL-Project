/*
 * Interface.h
 *
 *  Created on: 22/05/2019
 *      Author: mike
 */

#ifndef INTERFACE_H_
#define INTERFACE_H_

#include <sstream>

#include "Graph.h"
#include "graphviewer.h"

#define HEADER_SIZE_BIG 50
#define HEADER_SIZE_SMALL 30


//Input functions
void input_receiver(unsigned &input) {
	while(true) {

		cout << "Input: ";
		string value_str;
		cin >> value_str;

		istringstream ss(value_str);
                unsigned value;
		ss >> value;

		cin.ignore(1000, '\n');

		if(!ss.eof()) {
			cout << "Invalid input. Please try again" << std::endl << std::endl;
			continue;
		}
		else {
			input = value;
			break;
		}
	}
}

//General header drawing functions
void big_header(string message);
void small_header(string message);

//General menu prompt
int prompt_menu(int lower_bound, int upper_bound);

//Welcome menu
void print_welcome_menu();
void welcome_menu_interface();

//Graph menu
void print_graph_menu();
void graph_menu_interface(Graph &graph);


#endif /* INTERFACE_H_ */
