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
	Vertex(T value);
	Vertex(T value, int x, int y);

	std::vector<std::shared_ptr<Vertex<T>>> neighbors;
	bool visited;
	int knownDistance;
	int finalDistance;
	std::shared_ptr<Vertex<T>> founder;

	int x;
	int y;
};



template <typename T>
Vertex<T>::Vertex(T Value)
{
	value = Value;
	visited = false;
	knownDistance = 0;
	founder = nullptr;
	finalDistance = 0;
}

template <typename T>
Vertex<T>::Vertex(T Value, int X, int Y)
{
	value = Value;
	visited = false;
	knownDistance = 0;
	founder = nullptr;
	finalDistance = 0;
	x = X;
	y = Y;
}