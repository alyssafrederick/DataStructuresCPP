#pragma once
#include <memory>

template <typename T>
class bstNode
{
public:
	T Value;
	bstNode<T>* parent;
	std::unique_ptr<bstNode<T>> leftChild;
	std::unique_ptr<bstNode<T>> rightChild;
	bstNode(T value);
};

#include "bstNode.tpp"