/*
 * BranchAndBound.cpp
 *
 *  Created on: 24 de mai de 2019
 *      Author: Estudio
 */

#include "BranchAndBound.h"

BranchAndBound::BranchAndBound(Graph graph, vector<unsigned> initialPath, double initialDistance) {
	// adicionar rota inicial e distância inicial ao construtor
	this->graph = graph;
	fw = FloydWarshall(graph);
	performed = false;
	path = initialPath;
	distance = initialDistance;

}

/*vector<unsigned> BranchAndBound::recursion(unsigned currentIndex, vector<bool> visited, double distanceUntilNow) {
	visited[currentIndex] = true;
	vector<unsigned> answer = {};
	for (size_t i = 0; i < network.getChildrenVertices().size(); i++){
		//Falta somar MST na clausula abaixo:
		if (network.getDistances()[currentIndex][i] + distanceUntilNow < distance && !visited[i]){
			recursion(i, visited, network.getDistances()[currentIndex][i] + distanceUntilNow);
		}
	}
	return answer;

}*/



void BranchAndBound::perform(){

	performed = true;
}


BranchAndBound::~BranchAndBound() {
	// TODO Auto-generated destructor stub
}

