#pragma once

#include <memory>
#include <iostream>
#include <vector>
//min heap
template <typename T>
class HeapTree
{
public:
	int Size;
	//std::unique_ptr<T[]> Root;
	
	std::vector<T> Root;

	T* Parent(int index);
	T* LChild(int index);
	T* RChild(int index);
	void Add(T value);
	void Pop();
	void HeapifyUp(T value);
	void HeapifyDown(int index);
	HeapTree();
	
private:
	void Resize(int size);
};

#include "HeapTree.tpp"