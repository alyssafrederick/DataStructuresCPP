#pragma once

#include <memory>
#include "DoublyLinkedList.h"

template <typename T>
class Stack
{
public:
	int Size;
	DoublyLinkedList<T> LList;
	void Push(T);
	T Pop();
	T Peak();
	void Clear();
	bool IsEmpty();
	Stack();
	~Stack();
};

#include "Stack.tpp"