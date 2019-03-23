#pragma once

#include <memory>
#include <iostream>

#include "bstNode.h"

template <typename T>
class binarySearchTree
{
public:
	std::unique_ptr<bstNode<T>> Root;
	int Size;
	bool isEmpty();
	void Add(T value);
	bool Remove(T value);
	bstNode<T>* Search(T value);
	bstNode<T>* Maximum(bstNode<T>* node);
	bstNode<T>* Minimun(bstNode<T>* node);
	Stack<T>* TraverseInOrder();
	Stack<T>* TraversePreOrder();
	Stack<T>* TraversePostOrder();
	Stack<T>* TraverseLevelOrder();
	binarySearchTree();
	~binarySearchTree();
};

#include "binarySearchTree.tpp"