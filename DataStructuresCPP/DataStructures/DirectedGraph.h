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
	float FindEdgeWeight(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end);
	std::vector<std::shared_ptr<Vertex<T>>> Search(T value);
	std::shared_ptr<WeightedEdge<T>> GetEdge(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end);

	std::shared_ptr<Vertex<T>> AddVertexPosit(T value, int x, int y);

	void Dijkstras(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end);
	void AStar(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end);
	int ManhattanHeuristic(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end);
	int EuclideanHeuristic(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end);

	bool BellmanFord();
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
std::shared_ptr<Vertex<T>> DirectedGraph<T>::AddVertexPosit(T value, int x, int y)
{
	std::shared_ptr<Vertex<T>> temp = std::make_shared<Vertex<T>>(value, x, y);
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
float DirectedGraph<T>::FindEdgeWeight(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end)
{
	for (auto itr = edges.begin(); itr != edges.end(); itr++)
	{
		auto edge = *itr;
		if ((*edge).Start == start && (*edge).End == end)
		{
			return edge->Weight;
		}
	}
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
void DirectedGraph<T>::Dijkstras(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end)
{
	for (auto i = verticies.begin(); i != verticies.end(); i++)
	{
		auto& vert = *i;

		vert->visited = false;
		vert->knownDistance = std::numeric_limits<int>::max(); //infinity
		vert->founder = nullptr;
	}

	//using heap as a priority queue
	HeapTree<std::shared_ptr<Vertex<T>>> priorityQ;

	start->knownDistance = 0;
	priorityQ.Add(start);

	while (priorityQ.Size != 0)
	{
		auto current = priorityQ.PopT();
		current->visited = true;

		//if (current == end)


		for (auto& neighbor : current->neighbors)
			//for (auto neighbor = current.get()->neighbors.begin(); neighbor != current.get()->neighbors.end(); neighbor++)
		{
			float edgeWeight = FindEdgeWeight(current, neighbor);
			int tentativeDist = current->knownDistance + edgeWeight;

			if (tentativeDist < neighbor->knownDistance)
			{
				neighbor->knownDistance = tentativeDist;
				neighbor->founder = current;
				neighbor->visited = false;
			}
			else
			{
				neighbor->visited = true;
			}

			if (neighbor->visited == false /* && neighbor is not in priorityQ already */)
			{
				priorityQ.Add(neighbor);
			}
		}
	}

	//start at the end and work back
	Stack<std::shared_ptr<Vertex<T>>> stack;
	stack.Push(end);
	std::cout << end->value << std::endl;
	while (stack.Peek() != start)
	{
		stack.Push(stack.Peek()->founder);
		std::cout << stack.Peek().get()->value << std::endl; //displays order backwards but yea
	}
}

template <typename T>
void DirectedGraph<T>::AStar(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end)
{
	for (auto i = verticies.begin(); i != verticies.end(); i++)
	{
		auto& vert = *i;

		vert->visited = false;
		vert->knownDistance = std::numeric_limits<int>::max(); //infinity
		vert->finalDistance = std::numeric_limits<int>::max(); //infinity
		vert->founder = nullptr;
	}

	//using heap as a priority queue
	HeapTree<std::shared_ptr<Vertex<T>>> priorityQ;

	start->knownDistance = 0;
	start->finalDistance = ManhattanHeuristic(start, end);
	priorityQ.Add(start);

	while (priorityQ.Size != 0)
	{
		auto current = priorityQ.PopT();
		current->visited = true;

		for (auto& neighbor : current->neighbors)
		{
			float edgeWeight = FindEdgeWeight(current, neighbor);
			int tentativeDist = current->knownDistance + edgeWeight;

			if (tentativeDist < neighbor->knownDistance)
			{
				neighbor->knownDistance = tentativeDist;
				neighbor->founder = current;
				neighbor->visited = false;
				neighbor->finalDistance = neighbor->knownDistance + ManhattanHeuristic(neighbor, end);
			}
			else
			{
				neighbor->visited = true;
			}

			if (neighbor->visited == false)
			{
				priorityQ.Add(neighbor);
			}
		}
	}

	//start at the end and work back
	Stack<std::shared_ptr<Vertex<T>>> stack;
	stack.Push(end);
	std::cout << end->value << std::endl;
	while (stack.Peek() != start)
	{
		stack.Push(stack.Peek()->founder);
		std::cout << stack.Peek().get()->value << std::endl; //displays order backwards but yea
	}
}

template <typename T>
int DirectedGraph<T>::ManhattanHeuristic(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end)
{
	//four directions of movement

	int D = 1;
	int dx = std::abs(start->x - end->x);
	int dy = std::abs(start->y - end->y);

	return D * (dx + dy);
}

template <typename T>
int DirectedGraph<T>::EuclideanHeuristic(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end)
{
	//any direction of movement

	int D = 1;
	int dx = std::abs(start->x - end->x);
	int dy = std::abs(start->y - end->y);

	return D * std::sqrt(dx * dx + dy * dy);
}

template <typename T>
bool DirectedGraph<T>::BellmanFord()
{
	for (auto i = verticies.begin(); i != verticies.end(); i++)
	{
		auto& vert = *i;

		vert->knownDistance = std::numeric_limits<int>::max(); //infinity
		vert->founder = nullptr;
	}

	auto current = verticies.begin();
	auto& vert = *current;
	vert->knownDistance = 0;

	//going through the graph
	for (auto i = verticies.begin(); i != verticies.end(); i++)
	{
		auto& vert = *i;

		for (auto& neighbor : vert->neighbors)
		{
			float edgeWeight = FindEdgeWeight(vert, neighbor);
			int tentativeDist = vert->knownDistance + edgeWeight;

			if (tentativeDist < neighbor->knownDistance)
			{
				neighbor->knownDistance = tentativeDist;
				neighbor->founder = vert;
			}
		}
	}

	//check for negative cycles
	for (auto i = verticies.begin(); i != verticies.end(); i++)
	{
		auto& vert = *i;

		for (auto& neighbor : vert->neighbors)
		{
			float edgeWeight = FindEdgeWeight(vert, neighbor);
			int tentativeDist = vert->knownDistance + edgeWeight;

			if (tentativeDist < neighbor->knownDistance)
			{
				return true;
			}
		}
	}


	////using heap as a priority queue
	//HeapTree<std::shared_ptr<Vertex<T>>> q;

	//for (auto i = verticies.begin(); i != verticies.end(); i++)
	//{
	//	auto& vert = *i;
	//	q.Add(vert);
	//}

	//auto start = q.PopT();

	//start->knownDistance = 0;
	//q.Add(start);



	//while (q.Size != 0)
	//{
	//	auto current = q.PopT();

	//	for (auto& neighbor : current->neighbors)
	//	{
	//		//going through the graph

	//		float edgeWeight = FindEdgeWeight(current, neighbor);
	//		int tentativeDist = current->knownDistance + edgeWeight;

	//		if (tentativeDist < neighbor->knownDistance)
	//		{
	//			neighbor->knownDistance = tentativeDist;
	//			neighbor->founder = current;
	//		}
	//	}


		//for (auto& neighbor : current->neighbors)
		//{
		//	//check for negative cycles

		//	float edgeWeight = FindEdgeWeight(current, neighbor);
		//	int tentativeDist = current->knownDistance + edgeWeight;

		//	if (tentativeDist < neighbor->knownDistance)
		//	{
		//		return true;
		//	}
		//}
		//}

	return false;
}