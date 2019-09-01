#pragma once

#include <memory>
#include <iostream>
#include <vector>
#include <unordered_set>

#include "Vertex.h"

#include "Edge.h"
//template <typename T>
//class Edge;


template <typename T>
class Graph
{
private:
	//std::unordered_set<std::shared_ptr<Vertex<T>>> verticies;
	std::unordered_set<std::shared_ptr<Edge<T>>> edges;

public:
	Graph();

	std::unordered_set<std::shared_ptr<Vertex<T>>> verticies;
	std::shared_ptr<Vertex<T>> AddVertex(T value);
	bool AddEdge(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end, float weight);
	bool RemoveVertex(std::shared_ptr<Vertex<T>> vertex);
	bool RemoveEdge(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end);
	bool RemoveEdge(std::shared_ptr<Edge<T>> edge);
	std::vector<std::shared_ptr<Vertex<T>>> Search(T value);
};



template <typename T>
Graph<T>::Graph()
{
}

template <typename T>
std::shared_ptr<Vertex<T>> Graph<T>::AddVertex(T value)
{
	std::shared_ptr<Vertex<T>> temp = std::make_shared<Vertex<T>>(value);
	verticies.emplace(temp);
	return Search(value).front();
}

template <typename T>
bool Graph<T>::AddEdge(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end, float weight)
{
	std::shared_ptr<Edge<T>> temp = std::make_shared<Edge<T>>(start, end, weight);
	edges.emplace(temp);
	//add each other to the other's neighbors vector
	start->neighbors.push_back(end);
	end->neighbors.push_back(start);
	
	if (start->neighbors[start->neighbors.size() - 1] == end && end->neighbors[end->neighbors.size() - 1] == start)
	{
		return true;
	}
	return false;
}

template <typename T>
bool Graph<T>::RemoveVertex(std::shared_ptr<Vertex<T>> vertexToFind)
{
	verticies.erase(verticies.find(vertexToFind));
	/*for (auto& vertex : this->verticies)
	{
		if (vertex == vertexToFind)
		{
			this->verticies.erase(vertex);
		}
	}*/


	//Search(vertex)
	return true;
}

template <typename T>
std::vector<std::shared_ptr<Vertex<T>>> Graph<T>::Search(T value)
{
	std::vector<std::shared_ptr<Vertex<T>>> matches;
	for (std::shared_ptr<Vertex<T>> vertex : verticies)
	{
		if (vertex->value == value)
		{
			matches.push_back(vertex);
		}
	}

	return matches;
}


//template <typename T>
//bool Graph<T>::RemoveVertex(Vertex<T>* vertex)
//{
//	for (int i = 0; i < count; i++)
//	{
//		//if the vertex exists in the list, remove its neighbor connections
//		if (verticies[i].value == vertex.value)
//		{
//			while (vertex.neighbors.count != 0)
//			{
//				vertex.neighbors.front().erase();
//			}
//			verticies.erase(i);
//		}
//	}
//}
//
//template <typename T>
//bool Graph<T>::RemoveEdge(Vertex<T>* start, Vertex<T>* end)
//{
//	int starti = 0;
//	int endi = 0;
//	//check if they are not null and contain edges to each other
//	if (start != nullptr && end != nullptr)
//	{
//		for (int i = 0; i < start.neighbors.size(); i++)
//		{
//			if (start.neighbprs[i] == end)
//			{
//				starti = i;
//			}
//		}
//		for (int i = 0; i < end.neighbors.size(); i++)
//		{
//			if (end.neighbprs[i] == start)
//			{
//				endi = i;
//			}
//		}
//		start.neighbors.erase(endi);
//		end.neighbors.erase(starti);
//	}
//}