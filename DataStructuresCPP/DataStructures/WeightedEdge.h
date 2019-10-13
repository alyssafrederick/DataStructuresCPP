#pragma once

#include <memory>

template<typename T>
class Vertex;

template<typename T>
struct WeightedEdge
{
public:
	std::shared_ptr<Vertex<T>> Start;
	std::shared_ptr<Vertex<T>> End;
	float Weight;
	WeightedEdge(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end, float weight);
};

template<typename T>
WeightedEdge<T>::WeightedEdge(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end, float weight)
{
	Start = start;
	End = end;
	Weight = weight;
}