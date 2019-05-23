/*
 * NearestNeighbour.h
 *
 *  Created on: 23 de mai de 2019
 *      Author: Estudio
 */

#ifndef SRC_NEARESTNEIGHBOUR_H_
#define SRC_NEARESTNEIGHBOUR_H_

#include "Network.h"

class NearestNeighbour {
	Network network;
	vector<bool> visited;
	double distance;
	vector<unsigned> path;
	bool performed;
public:
	NearestNeighbour(Network nw);

	void perform();

	virtual ~NearestNeighbour();
};

#endif /* SRC_NEARESTNEIGHBOUR_H_ */
