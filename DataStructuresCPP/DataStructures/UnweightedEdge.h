#pragma once

#include <memory>

template<typename T>
class Vertex;

template<typename T>
struct UnweightedEdge
{
public:
	std::shared_ptr<Vertex<T>> Start;
	std::shared_ptr<Vertex<T>> End;
	UnweightedEdge(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end);
};

template<typename T>
UnweightedEdge<T>::UnweightedEdge(std::shared_ptr<Vertex<T>> start, std::shared_ptr<Vertex<T>> end)
{
	Start = start;
	End = end;
}