#pragma once

#include <memory>
#include <iostream>
#include <vector>

template <typename T>
class Vertex
{
public:
	T value;
	vector<Vertex<T>> neighbors;
	int count;
	Vertex(T value);
};



template <typename T>
Vertex<T>::Vertex(T Value)
{
	Value = value;
	count = neighbors.size();
}
