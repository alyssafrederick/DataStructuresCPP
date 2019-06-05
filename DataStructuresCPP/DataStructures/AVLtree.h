#pragma once

#include <memory>
#include <iostream>

#include "AVLnode.h"

template <typename T>
class AVLtree
{
public:
	std::unique_ptr<bstNode<T>> Root;

};

#include "AVLtree.tpp"
