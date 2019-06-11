#pragma once

#include <memory>
#include <iostream>

#include "AVLnode.h"

template <typename T>
class AVLtree
{
public:
	std::unique_ptr<AVLnode<T>> Root;
	bool IsEmpty();
	void Add(T value);
	bool Remove(T value);

	AVLtree();
};


#include "AVLtree.tpp"