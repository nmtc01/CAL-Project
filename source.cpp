/*
 * source.cpp
 *
 */


#include <cstdio>
#include <fstream>
#include <iostream>

#include "Interface.h"

#ifdef __linux__
	void sleep_func() {
		sleep(1);
	}
#else
	void sleep_func() {
		Sleep(100);
	}
#endif

int main() {

	welcome_menu_interface();

	getchar();
	return 0;
}
