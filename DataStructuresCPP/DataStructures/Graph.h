#pragma once

#include <memory>
#include <iostream>
#include <vector>
#include <unordered_set>

#include "Vertex.h"

#include "Edge.h"


template <typename T>
class Graph
{
private:
	std::unordered_set<std::shared_ptr<Vertex<T>>> verticies;
	std::unordered_set<std::shared_ptr<Edge<T>>> edges;

public:
	Graph();
	std::shared_ptr<Vertex<T>> AddVertex(T value);
	bool AddEdge(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end, float weight);
	bool RemoveVertex(std::shared_ptr<Vertex<T>> vertex);
	bool RemoveEdge(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end);
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
	//add the end to the start's neighbors vector
	start->neighbors.push_back(end);
	
	if (start->neighbors[start->neighbors.size() - 1] == end)
	{
		return true;
	}
	return false;
}

template <typename T>
bool Graph<T>::RemoveVertex(std::shared_ptr<Vertex<T>> vertexToFind)
{
	int count = 0;

	//delete edges connected to vertextofind.. those that their end point it vertextofind
	for (auto itr = edges.begin(); itr != edges.end(); itr++)
	{
		auto edge = *itr;
		if ((*edge).End == vertexToFind)
		{
			count++;
		}
	}

	int i = 0;
	while (i < count)
	{
		for (auto itr = edges.begin(); itr != edges.end(); itr++)
		{
			auto edge = *itr;
			if ((*edge).End == vertexToFind)
			{
				RemoveEdge((*edge).Start, vertexToFind);
				break;
			}
		}
		i++;
	}

	//delete the actual vertex
	verticies.erase(verticies.find(vertexToFind));

	return true;
}

template <typename T>
bool Graph<T>::RemoveEdge(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end)
{
	for (auto itr = edges.begin(); itr != edges.end(); itr++)
	{
		auto edge = *itr;		
		if ((*edge).Start == start && (*edge).End == end)
		{
			edges.erase(itr);
			
			for (auto i = (*start).neighbors.begin(); i != (*start).neighbors.end(); i++)
			{
				if ((*i) == end)
				{
					(*start).neighbors.erase(i);
					break;
				}				
			}

			return true;
		}
	}

	return false;
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
