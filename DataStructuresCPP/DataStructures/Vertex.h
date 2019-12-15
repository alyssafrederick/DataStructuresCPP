#pragma once

#include <memory>
#include <iostream>
#include <vector>

#include "WeightedEdge.h"

template <typename T>
class Vertex
{
public:
	T value;
	std::vector<std::shared_ptr<Vertex<T>>> neighbors;
	Vertex(T value);
	bool visited;
	int knownDistance;
	std::shared_ptr<Vertex<T>> founder;
};



template <typename T>
Vertex<T>::Vertex(T Value)
{
	value = Value;
	visited = false;
	knownDistance = 0;
	founder = nullptr;
}
