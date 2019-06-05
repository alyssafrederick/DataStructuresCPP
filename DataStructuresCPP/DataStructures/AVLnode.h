#pragma once
#include <memory> 

template <typename T>
class AVLnode
{
public:
	T Value;
	AVLnode<T>* parent;
	AVLnode<T>* left;
	AVLnode<T>* right;
	AVLnode(T value);
};

#include "AVLnode.tpp"