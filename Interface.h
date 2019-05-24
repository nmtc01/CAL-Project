/*
 * Interface.h
 *
 */

#pragma once

#include <sstream>

#include "Graphviewer/graphviewer.h"
#include "Network.h"
#include "NearestNeighbour.h"

#define HEADER_SIZE_BIG 50
#define HEADER_SIZE_SMALL 30


//Input functions
template <class T>
void input_receiver(T &input) {
	while(true) {

		cout << "Input: ";
		string value_str;
		cin >> value_str;

		istringstream ss(value_str);
		T value;
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
void graph_menu_interface();
void graphviewer_option();


