#pragma once

#include <memory>
#include <iostream>
#include <vector>

#include "Vertex.h"

template <typename T>
class Graph
{
public:
	std::vector<Vertex<T>> verticies;
	int count;
	Graph();

	void AddVertex(Vertex<T> vertex);
	bool RemoveVertex(Vertex<T>* vertex);
	//bool AddEdge(Vertex<T>* a, Vertex<T>* b);
	bool RemoveEdge(Vertex<T>* a, Vertex<T>* b);
	//Vertex<T>* Search(T value);
	int IndexOf(T vertex);
};



template <typename T>
Graph<T>::Graph()
{
	count = verticies.size();
}

template <typename T>
int Graph<T>::IndexOf(T vertex)
{
	int index = -1;
	for (int i = 0; i < count; i++)
	{
		if (verticies[i].value = vertex)
		{
			index = i;
		}
	}
	return index;
}

template <typename T>
void Graph<T>::AddVertex(Vertex<T> vertex)
{
	if (vertex.count == 0)
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
bool Graph<T>::RemoveVertex(Vertex<T>* vertex)
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
bool Graph<T>::RemoveEdge(Vertex<T>* start, Vertex<T>* end)
{
	int starti = 0;
	int endi = 0;
	//check if they are not null and contain edges to each other
	if (start != nullptr && end != nullptr)
	{
		for (int i = 0; i < start.neighbors.size(); i++)
		{
			if (start.neighbprs[i] == end)
			{
				starti = i;
			}
		}
		for (int i = 0; i < end.neighbors.size(); i++)
		{
			if (end.neighbprs[i] == start)
			{
				endi = i;
			}
		}
		start.neighbors.erase(endi);
		end.neighbors.erase(starti);
	}
}