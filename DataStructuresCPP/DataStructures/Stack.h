#pragma once

#include <memory>
#include <iostream>
#include "DoublyLinkedList.h"

template <typename T>
class Stack
{
public:
	int Size;
	DoublyLinkedList<T> LList;
	void Push(T);
	T Pop();
	T Peek();
	void Clear();
	bool IsEmpty();
	Stack();
	~Stack();
};




template <typename T>
Stack<T>::Stack()
{
	Size = 0;
}

//the head/start is at the top of the stack
template <typename T>
void Stack<T>::Push(T value)
{
	LList.AddAtStart(value);
	Size++;
}

template <typename T>
T Stack<T>::Pop()
{
	T toReturn = LList.First.get()->Value;

	LList.DeleteAtStart();
	Size--;

	return toReturn;
}

template <typename T>
T Stack<T>::Peek()
{
	return LList.First.get()->Value;
}

template <typename T>
void Stack<T>::Clear()
{
	LList.Clear();
	Size = 0;
}

template <typename T>
bool Stack<T>::IsEmpty()
{
	if (LList.First == nullptr)
	{
		return true;
	}
	else { return false; }
}

template <typename T>
Stack<T>::~Stack()
{
	Clear();
}