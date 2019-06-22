#pragma once
#include <memory> 

template <typename T>
class AVLnode
{
public:
	T Value;
	std::unique_ptr<AVLnode<T>> leftChild;
	std::unique_ptr<AVLnode<T>> rightChild;

	int GetHeight();
	void ResetHeight();
	void IncrementHeight();

	int Balance();

	AVLnode(T value);

//private:
	int height;
	int balance;
};


#include "AVLnode.tpp"