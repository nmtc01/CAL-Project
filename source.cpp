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

void exercicio1();
void exercicio2();
void exercicio3();


void exercicio1()
{
	GraphViewer *gv = new GraphViewer(600, 600, true);

	gv->setBackground("background.jpg");

	gv->createWindow(600, 600);


	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");

	gv->addNode(0);
	gv->addNode(1);
	gv->addEdge(0, 0, 1, EdgeType::UNDIRECTED);

	sleep_func(); // use sleep(1) in linux ; Sleep(100) on Windows

	gv->removeEdge(0);
	gv->removeNode(1);
	gv->addNode(2);

	gv->rearrange();

	sleep_func();

	gv->addEdge(1, 0, 2, EdgeType::UNDIRECTED);

	gv->setVertexLabel(0, "Isto e um no");
	gv->setEdgeLabel(1, "Isto e uma aresta");

	gv->setVertexColor(2, "green");
	gv->setEdgeColor(1, "yellow");

	gv->rearrange();

}

void exercicio2()
{
	GraphViewer *gv = new GraphViewer(600, 600, false);

	gv->createWindow(600, 600);

	gv->defineEdgeColor("blue");
	gv->defineVertexColor("yellow");

	gv->addNode(0,300,50);
	gv->addNode(1,318,58);
	gv->addNode(4,300,100);
	gv->addNode(7,282,58);
	gv->addNode(2,325,75);
	gv->addNode(3,318,93);
	gv->addNode(6,275,75);
	gv->addNode(5,282,93);

	gv->addNode(8,150,200);

	gv->setVertexColor(8, "green");
	gv->setVertexColor(9, "blue");
	gv->setVertexColor(10, "green");
	gv->setVertexColor(11, "blue");
	gv->setVertexColor(12, "green");
	gv->setVertexColor(13, "green");
	gv->addNode(9,300,200);
	gv->addNode(10,450,200);
	gv->addNode(11,300,400);

	gv->addNode(12,200,550);
	gv->addNode(13,400,550);

	gv->addEdge(0, 0, 1, EdgeType::UNDIRECTED);
	gv->addEdge(1, 1, 2, EdgeType::UNDIRECTED);
	gv->addEdge(2, 2, 3, EdgeType::UNDIRECTED);
	gv->addEdge(3, 3, 4, EdgeType::UNDIRECTED);
	gv->addEdge(4, 4, 5, EdgeType::UNDIRECTED);
	gv->addEdge(5, 5, 6, EdgeType::UNDIRECTED);
	gv->addEdge(6, 6, 7, EdgeType::UNDIRECTED);
	gv->addEdge(7, 7, 0, EdgeType::UNDIRECTED);

	gv->addEdge(8, 4, 9, EdgeType::UNDIRECTED);
	gv->addEdge(9, 9, 8, EdgeType::UNDIRECTED);
	gv->addEdge(10, 9, 10, EdgeType::UNDIRECTED);
	gv->addEdge(11, 9, 11, EdgeType::UNDIRECTED);
	gv->addEdge(12, 11, 12, EdgeType::UNDIRECTED);
	gv->addEdge(13, 11, 13, EdgeType::UNDIRECTED);


	gv->rearrange();
	bool first=true;

	while(1)
	{
		sleep_func();
		if (first)
		{
		  gv->removeNode(12);
		  gv->removeNode(13);
		  first=false;
		}
		else
		{
		  gv->removeNode(20);
		  gv->removeNode(21);
		}
		gv->addNode(14,250,550);
		gv->addNode(15,350,550);
		gv->addEdge(14, 11, 14, EdgeType::UNDIRECTED);
		gv->addEdge(15, 11, 15, EdgeType::UNDIRECTED);
		gv->rearrange();

		sleep_func();
		gv->removeNode(14);
		gv->removeNode(15);
		gv->addNode(16,300,550);
		gv->addNode(17,300,550);
		gv->addEdge(16, 11, 16, EdgeType::UNDIRECTED);
		gv->addEdge(17, 11, 17, EdgeType::UNDIRECTED);
		gv->rearrange();
		sleep_func();

		gv->removeNode(16);
		gv->removeNode(17);
		gv->addNode(18,250,550);
		gv->addNode(19,350,550);
		gv->addEdge(18, 11, 18, EdgeType::UNDIRECTED);
		gv->addEdge(19, 11, 19, EdgeType::UNDIRECTED);
		gv->rearrange();
		sleep_func();

		gv->removeNode(18);
		gv->removeNode(19);
		gv->addNode(20,200,550);
		gv->addNode(21,400,550);
		gv->addEdge(20, 11, 20, EdgeType::UNDIRECTED);
		gv->addEdge(21, 11, 21, EdgeType::UNDIRECTED);
		gv->rearrange();
	}
}

void exercicio3()
{
	GraphViewer *gv = new GraphViewer(600, 600, false);

	gv->createWindow(600, 600);

	gv->defineEdgeColor("blue");
	gv->defineVertexColor("yellow");

	ifstream inFile;

	//Ler o ficheiro nos.txt
	inFile.open("nos.txt");

	if (!inFile) {
	    cerr << "Unable to open file datafile.txt";
	    exit(1);   // call system to stop
	}

	std::string   line;

	int idNo=0;
	int X=0;
	int Y=0;

	while(std::getline(inFile, line))
	{
	    std::stringstream linestream(line);
	    std::string         data;

	    linestream >> idNo;

	    std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
	    linestream >> X;
	    std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
	    linestream >> Y;
	    gv->addNode(idNo,X,Y);

	}

	inFile.close();


	//Ler o ficheiro arestas.txt
	inFile.open("arestas.txt");

		if (!inFile) {
		    cerr << "Unable to open file datafile.txt";
		    exit(1);   // call system to stop
		}

		int idAresta=0;
		int idNoOrigem=0;
		int idNoDestino=0;

		while(std::getline(inFile, line))
		{
		    std::stringstream linestream(line);
		    std::string data;


		    linestream >> idAresta;

		    std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		    linestream >> idNoOrigem;
		    std::getline(linestream, data, ';');  // read up-to the first ; (discard ;).
		    linestream >> idNoDestino;
		    gv->addEdge(idAresta,idNoOrigem,idNoDestino, EdgeType::UNDIRECTED);

		}

		inFile.close();

	gv->rearrange();
}



/*** TESTING MAP FILES AND IMPORT ***/

void testing() {
	GraphViewer *gv = new GraphViewer(1000, 1000, false);
	gv->setBackground("background.jpg");
	gv->createWindow(1000, 1000);
	gv->defineEdgeColor("blue");
	gv->defineVertexColor("yellow");

	string nodes_file = "src/Maps/Fafe/T05_nodes_X_Y_Fafe.txt";
	string edges_file = "src/Maps/Fafe/T05_edges_Fafe.txt";
	string tags_file = "src/Maps/Fafe/T05_tags_Fafe.txt";

	Graph graph(nodes_file, edges_file, tags_file);

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

int main() {
	//printf("AAAAAAAAAAAAA");
	//printf("\n");
	//exercicio1();
	//exercicio2();
	//exercicio3();
	//testing();

	welcome_menu_interface();

	getchar();
	return 0;
}
