#pragma once

#include <memory>

template<typename T>
class Vertex;

template<typename T>
struct Edge
{
public:
	std::shared_ptr<Vertex<T>> Start;
	std::shared_ptr<Vertex<T>> End;
	float Weight;
	// bool Enabled;
};

