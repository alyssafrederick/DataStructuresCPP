#pragma once
#include <memory>
#include "SinglyLinkedNode.cpp"

template <typename T>
class SinglyLinkedList
{
public:
	int Size;
	std::unique_ptr<SinglyLinkedNode<T>> First;
	std::unique_ptr<SinglyLinkedNode<T>> Last;
	void Add(T);
	void Clear();
	void Delete(T);
	bool Found(T);
	void GetAll();
	SinglyLinkedList();
	~SinglyLinkedList();
};

