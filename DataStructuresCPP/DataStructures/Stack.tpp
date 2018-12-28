#include "Stack.h"
#include <memory>
#include <iostream>

template <typename T>
Stack<T>::Stack()
{
	int Size = 0;
}

template <typename T>
void Stack<T>::Push(T value)
{
	LList.AddAtEnd(value);
	Size++;
}

template <typename T>
T Stack<T>::Pop()
{
	DoublyLinkedNode<T>* temp = LList.First.get();
	while (temp->nextNode != nullptr)
	{
		temp = temp->nextNode.get();
	}

	LList.DeleteAtEnd();
	Size--;

	return temp->Value;
}

template <typename T>
T Stack<T>::Peak()
{
	DoublyLinkedNode<T>* temp = LList.First.get();
	while (temp->nextNode != nullptr)
	{
		temp = temp->nextNode.get();
	}

	return temp->Value;
}

template <typename T>
void Stack<T>::Clear()  //FIX
{
	LList.First = nullptr;
}

template <typename T>
bool Stack<T>::IsEmpty()
{
	if (LList.First == nullptr)
	{
		return true;
	}
	else { return false;  }
}

template <typename T>
Stack<T>::~Stack()  //TODO
{
}
