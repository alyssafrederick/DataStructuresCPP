#pragma once

#include <memory>
#include <iostream>
#include <vector>

template <typename T>
class Graph
{
public:
	vector<Vertex<T>> verticies;
	int count;
	Graph();

	void AddVertex(Vertex<T> vertex);
	bool RemoveVertex(Vertex<T> vertex);
	//bool AddEdge(Vertex<T> a, Vertex<T> b);
	bool RemoveEdge(Vertex<T> a, Vertex<T> b);
	//Vertex<T> Search(T value);
	//int IndexOf(Vertex<T> vertex);
};



template <typename T>
Graph<T>::Graph()
{
	count = verticies.size();
}

template <typename T>
void AddVertex(Vertex<T> vertex)
{
	if (vertex != nullptr && vertex.count == 0)
	{
		for (int i = 0; i < count; i++)
		{
			if (verticies[i].value == vertex.value)
			{
				return;
			}
		}
		
		verticies.push_back(vertex);
	}
	
	return;
}

template <typename T>
bool RemoveVertex(Vertex<T> vertex)
{
	for (int i = 0; i < count; i++)
	{
		//if the vertex exists in the list, remove its neighbor connections
		if (verticies[i].value == vertex.value)
		{
			while (vertex.neighbors.count != 0)
			{
				vertex.neighbors.front().erase();
			}
			verticies.erase(i);
		}
	}
}

template <typename T>
bool RemoveEdge(Vertex<T> start, Vertex<T> end)
{
	//check if they contain edges to each other

	start.neighbors.erase(end);
	end.neighbors.erase(start);
}