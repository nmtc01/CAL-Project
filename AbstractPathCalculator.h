/*
 * AbstractPathCalculator.h
 *
 *  Created on: 27 de mai de 2019
 *      Author: Estudio
 */

#pragma once
#include <vector>
#include <iostream>
using namespace std;


class AbstractPathCalculator {
public:
	AbstractPathCalculator();
    virtual double getDistance(unsigned source, unsigned dest){
		cout << "Parent class :: getDistance" << endl;
		return 0.0;
	}
	virtual vector<unsigned> getPath(unsigned source, unsigned dest) {
		cout << "Parent class :: getPath" << endl;
		return {};
	}

	virtual ~AbstractPathCalculator();
};
