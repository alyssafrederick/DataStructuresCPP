#pragma once

#include <memory>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <limits>

#include "Vertex.h"
#include "WeightedEdge.h"
#include "HeapTree.h"


template <typename T>
class DirectedGraph
{
private:
	std::unordered_set<std::shared_ptr<Vertex<T>>> verticies;
	std::unordered_set<std::shared_ptr<WeightedEdge<T>>> edges;

public:
	DirectedGraph();
	std::shared_ptr<Vertex<T>> AddVertex(T value);
	bool AddEdge(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end, float weight);
	bool RemoveVertex(std::shared_ptr<Vertex<T>> vertex);
	bool RemoveEdge(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end);
	std::vector<std::shared_ptr<Vertex<T>>> Search(T value);
	std::shared_ptr<WeightedEdge<T>> GetEdge(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end);

	std::vector<std::shared_ptr<Vertex<T>>> Dijkstras(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end);
};



template <typename T>
DirectedGraph<T>::DirectedGraph()
{
}

template <typename T>
std::shared_ptr<Vertex<T>> DirectedGraph<T>::AddVertex(T value)
{
	std::shared_ptr<Vertex<T>> temp = std::make_shared<Vertex<T>>(value);
	verticies.emplace(temp);
	return Search(value).front();
}

template <typename T>
bool DirectedGraph<T>::AddEdge(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end, float weight)
{
	std::shared_ptr<WeightedEdge<T>> temp = std::make_shared<WeightedEdge<T>>(start, end, weight);
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
bool DirectedGraph<T>::RemoveVertex(std::shared_ptr<Vertex<T>> vertexToFind)
{
	int count = 0;

	//delete edges connected to vertexToFind.. those that their end point it vertexToFind
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

	//delete the actual vertex (vertexToFind)
	verticies.erase(verticies.find(vertexToFind));

	return true;
}

template <typename T>
bool DirectedGraph<T>::RemoveEdge(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end)
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
std::vector<std::shared_ptr<Vertex<T>>> DirectedGraph<T>::Search(T value)
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

template <typename T>
std::shared_ptr<WeightedEdge<T>> DirectedGraph<T>::GetEdge(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end)
{
	for (auto itr = edges.begin(); itr != edges.end(); itr++)
	{
		auto edge = *itr;
		if ((*edge).Start == start && (*edge).End == end)
		{
			return edge;
		}
	}

	return nullptr;
}

template <typename T>
std::vector<std::shared_ptr<Vertex<T>>> DirectedGraph<T>::Dijkstras(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end)
{
	for each (vertex var in verticies)
	{
		vertex.visited = false;
		vertex.knownDistance = std::numeric_limits<int>::max(); //infinity
		vertex.founder = nullptr;
	}

	//using heap as a priority queue
	Heap<Vertex<T>> priorityQ = new Heap<Vertex<T>>();

	start.knownDistance = 0;
	priorityQ.Add(start);
}