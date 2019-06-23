#include "AVLnode.h"
template <typename T>
AVLnode<T>::AVLnode(T value)
{
	Value = value;
	leftChild = nullptr;
	rightChild = nullptr;
	height = 1;
	balance = 0;
}


template <typename T>
int AVLnode<T>::GetHeight()
{
	return height;
	/*
	if (leftChild == nullptr && rightChild == nullptr)
	{
		ResetHeight();
		return height;
	}
	else
	{
		if (leftChild->GetHeight() > rightChild->GetHeight())
		{
			leftChild->IncrementHeight();
			return height;
		}
		else
		{
			rightChild->IncrementHeight();
			return height;
		}
	}
	*/
}


template <typename T>
void AVLnode<T>::ResetHeight()
{
	height = 1;
}

template <typename T>
void AVLnode<T>::IncrementHeight()
{
	height++;
}

template <typename T>
int AVLnode<T>::Balance()
{
	int leftCount = 0;
	int rightCount = 0;

	if (leftChild == nullptr)
	{
		int leftCount = 0;
	}
	else
	{
		leftCount = leftChild->GetHeight();
	}
	if (rightChild == nullptr)
	{
		int rightCount = 0;
	}
	else
	{
		rightCount = rightChild->GetHeight();
	}
	return rightCount - leftCount;
}