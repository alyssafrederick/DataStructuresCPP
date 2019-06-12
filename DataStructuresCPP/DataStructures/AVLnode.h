#pragma once
#include <memory> 

template <typename T>
class AVLnode
{
public:
	T Value;
	std::unique_ptr<AVLnode<T>> leftChild;
	std::unique_ptr<AVLnode<T>> rightChild;

	int Height();
	int Balance();

	AVLnode(T value);

private:
	int heightCallCount;
};


#include "AVLnode.tpp"