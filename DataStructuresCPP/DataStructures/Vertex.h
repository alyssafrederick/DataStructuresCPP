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
};



template <typename T>
Vertex<T>::Vertex(T Value)
{
	value = Value;
	visited = false;
}
