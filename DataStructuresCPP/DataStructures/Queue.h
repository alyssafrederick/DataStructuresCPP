#pragma once

#include <memory>
#include <iostream>
#include "DoublyLinkedList.h"

template <typename T>
class Queue
{
public:	
	DoublyLinkedList<T> LList;
	int Size;
	bool isEmpty();
	void Enqueue(T);
	T Dequeue();
	T Peek();
	void Clear();
	Queue();
	~Queue();
};

#include "Queue.tpp"