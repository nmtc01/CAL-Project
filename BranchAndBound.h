/*
 * BranchAndBound.h
 *
 *  Created on: 24 de mai de 2019
 *      Author: Estudio
 */

#ifndef SRC_BRANCHANDBOUND_H_
#define SRC_BRANCHANDBOUND_H_
#include <vector>
#include "Network.h"

class BranchAndBound {

	Network network;
	vector<bool> visited;
	double distance;
	vector<unsigned> path;
	bool performed;
	vector<unsigned> recursion(unsigned currentIndex, vector<unsigned> visited, double distanceUntilNow);
	// adicionar private function para minimum spanning tree
public:

	BranchAndBound(Network nw, vector<unsigned> initialPath, double initialDistance);
	virtual ~BranchAndBound();
	void perform();

};

#endif /* SRC_BRANCHANDBOUND_H_ */
