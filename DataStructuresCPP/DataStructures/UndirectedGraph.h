#pragma once

#include <memory>
#include <iostream>
#include <vector>
#include <unordered_set>

#include "Stack.h"
#include "Queue.h"
#include "Vertex.h"
#include "UnweightedEdge.h"


template <typename T>
class UndirectedGraph
{
private:
	std::unordered_set<std::shared_ptr<Vertex<T>>> verticies;
	std::unordered_set<std::shared_ptr<UnweightedEdge<T>>> edges;
	void DepthFirstTraversalRecursive(std::shared_ptr<Vertex<T>>, Stack<std::shared_ptr<Vertex<T>>>* stack);
	void BreadthFirstTraversalRecursive(std::shared_ptr<Vertex<T>>, Queue<std::shared_ptr<Vertex<T>>>* q);

public:
	UndirectedGraph();
	std::shared_ptr<Vertex<T>> AddVertex(T value);
	bool AddEdge(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end);
	bool RemoveVertex(std::shared_ptr<Vertex<T>> vertex);
	bool RemoveEdge(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end);
	std::vector<std::shared_ptr<Vertex<T>>> Search(T value);
	std::shared_ptr<UnweightedEdge<T>> GetEdge(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end);
	void DepthFirstTraversal(std::shared_ptr<Vertex<T>> start);
	void BreadthFirstTraversal(std::shared_ptr<Vertex<T>> start);
};



template <typename T>
UndirectedGraph<T>::UndirectedGraph()
{
}

template <typename T>
std::shared_ptr<Vertex<T>> UndirectedGraph<T>::AddVertex(T value)
{
	std::shared_ptr<Vertex<T>> temp = std::make_shared<Vertex<T>>(value);
	verticies.emplace(temp);
	return Search(value).front();
}

template <typename T>
bool UndirectedGraph<T>::AddEdge(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end)
{
	std::shared_ptr<UnweightedEdge<T>> temp = std::make_shared<UnweightedEdge<T>>(start, end);
	edges.emplace(temp);

	//add the each to the other's neighbors vector
	start->neighbors.push_back(end);
	end->neighbors.push_back(start);

	if (start->neighbors[start->neighbors.size() - 1] == end)
	{
		return true;
	}
	return false;
}

template <typename T>
bool UndirectedGraph<T>::RemoveVertex(std::shared_ptr<Vertex<T>> vertexToFind)
{
	int count = 0;

	//delete edges connected to vertexToFind.. both if vertexToFind is start or end 
	for (auto itr = edges.begin(); itr != edges.end(); itr++)
	{
		auto edge = *itr;
		if ((*edge).End == vertexToFind || (*edge).Start == vertexToFind)
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
			if ((*edge).Start == vertexToFind)
			{
				RemoveEdge(vertexToFind, (*edge).End);
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
bool UndirectedGraph<T>::RemoveEdge(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end)
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
std::vector<std::shared_ptr<Vertex<T>>> UndirectedGraph<T>::Search(T value)
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
std::shared_ptr<UnweightedEdge<T>> UndirectedGraph<T>::GetEdge(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end)
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
void UndirectedGraph<T>::DepthFirstTraversal(std::shared_ptr<Vertex<T>> start)
{
	for (auto vert : verticies)
	{
		vert->visited = false;
	}

	DepthFirstTraversalRecursive(start, new Stack<Vertex<T>>());
}

template <typename T>
void UndirectedGraph<T>::DepthFirstTraversalRecursive(std::shared_ptr<Vertex<T>> start, Stack<std::shared_ptr<Vertex<T>>>* stack)
{
	start->visited = true;

	std::cout << start->value << std::endl;

	for (auto n : start->neighbors)
	{
		if (!n->visited)
		{
			stack->Push(n);
			DepthFirstTraversalRecursive(n, stack);
		}
	}
}

template <typename T>
void UndirectedGraph<T>::BreadthFirstTraversal(std::shared_ptr<Vertex<T>> start)
{
	for (auto vert : verticies)
	{

		vert->visited = false;
	}

	BreadthFirstTraversalRecursive(start, new Queue<std::shared_ptr<Vertex<T>>>());
}

template <typename T>
void UndirectedGraph<T>::BreadthFirstTraversalRecursive(std::shared_ptr<Vertex<T>> start, Queue<std::shared_ptr<Vertex<T>>>* q)
{
	start->visited = true;
	std::cout << start->value << std::endl;

	for (auto neighbor : start->neighbors)
	{
		if (!neighbor->visited)
		{
			neighbor->visited = true;
			q->Enqueue(neighbor);
		}
	}

	for (int i = 0; i < q->Size; i++)
	{
		BreadthFirstTraversalRecursive(q->Dequeue(), q);
	}
}