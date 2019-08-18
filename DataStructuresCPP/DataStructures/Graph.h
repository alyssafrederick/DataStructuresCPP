#pragma once

#include <memory>
#include <iostream>
#include <vector>

template <typename T>
class Graph
{
public:
	vector<Vertex<T>> Verticies;
	int count;
	Graph();

	void AddVertex(Vertex<T> vertex);
	bool RemoveVertex(Vertex<T> vertex);
	bool AddEdge(Vertex<T> a, Vertex<T> b);
	bool RemoveEdge(Vertex<T> a, Vertex<T> b);
	Vertex<T> Serch(T value);
	int IndexOf(Vertex<T> vertex);
};



template <typename T>
Graph<T>::Graph()
{
	count = verticies.size();
}