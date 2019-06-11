#pragma once
#include <memory> 

template <typename T>
class AVLnode
{
public:
	T Value;
	AVLnode<T>* parent;
	AVLnode<T>* leftChild;
	AVLnode<T>* rightChild;

	int heightCallCount;
	int Height();
	int Balance();

	AVLnode(T value);
};


#include "AVLnode.tpp"