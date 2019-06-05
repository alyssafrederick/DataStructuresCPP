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


//#include "AVLnode.tpp"

template <typename T>
AVLnode<T>::AVLnode(T value)
{
	Value = value;
	parent = nullptr;
	leftChild = nullptr;
	rightChild = nullptr;
	heightCallCount = 0;
}

template <typename T>
int AVLnode<T>::Height()
{
	heightCallCount++;

	if (leftChild == null && rightChild == null)
	{
		heightCallCount = 0;
		return 1;
	}
	else
	{
		if (leftChild.Height() > rightChild.Height())
		{
			return leftChild.Height() + 1;
		}
		else
		{
			return rightChild.Height() + 1;
		}
	}
}

template <typename T>
int AVLnode<T>::Balance()
{
	if (leftChild == nullptr)
	{
		int leftCount = 0;
	}
	else
	{
		leftCount = leftChild.Height();
	}
	if (rightChild == nullptr)
	{
		int rightCount == 0;
	}
	else
	{
		rightCount = rightChild.Height();
	}
	return rightCount - leftCount;
}