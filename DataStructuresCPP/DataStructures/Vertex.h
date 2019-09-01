#pragma once

#include <memory>
#include <iostream>
#include <vector>

#include "Edge.h"

template <typename T>
class Vertex
{
public:
	T value;
	std::vector<std::shared_ptr<Vertex<T>>> neighbors;
	int count;
	Vertex(T value);
};



template <typename T>
Vertex<T>::Vertex(T Value)
{
	//Value = value;
	value = Value;
	count = neighbors.size();
}
