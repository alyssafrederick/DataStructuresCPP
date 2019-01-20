#pragma once

//using namespace std;
#include <memory>
#include <iostream>
#include "SinglyLinkedNode.h"

template <typename T>
class SinglyLinkedList
{
public:
	int Size;
	std::unique_ptr<SinglyLinkedNode<T>> First;
	std::unique_ptr<SinglyLinkedNode<T>> Last;
	void Add(T);
	void Delete(T);
	bool Found(T);
	void GetAll();
	SinglyLinkedList();
	~SinglyLinkedList();
};

#include "SinglyLinkedList.tpp"