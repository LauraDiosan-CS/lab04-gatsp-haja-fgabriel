#include "Graph.h"
#include <Windows.h>

#include <fstream>
#include <iostream>

using std::fstream;

Graph::Graph(int Size) 
	: Size{Size} {}

Graph::Graph(const string & Filename)
{
	fstream f(Filename);
	double cost;

	f >> Size;
	AdjacencyMatrix.resize(Size + 1);

	for (int i = 1; i <= Size; i++)
	{
		AdjacencyMatrix[i].resize(Size + 1);
		for (int j = 1; j <= Size; j++)
		{
			f >> cost;
			AdjacencyMatrix[i][j] = cost;

			/* ignora virgula */
			if (j < Size)
				f.ignore(1); 

			/* adauga noua muchie */
			if (i < j)
				Edges.push_back(Edge(i, j, cost));
		}
	}
	f >> SourceNode >> DestinationNode;
}

vector<Edge>& Graph::GetEdges()
{
	return Edges;
}

int Graph::GetSize()
{
	return Size;
}

void Graph::AddEdge(const Edge& e)
{
	Edges.push_back(e);
}

Graph::~Graph()
{
}
