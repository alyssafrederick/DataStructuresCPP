#include "Stack.h"
#include <memory>
#include <iostream>

template <typename T>
Stack<T>::Stack()
{
	int Size = 0;
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
T Stack<T>::Peak()
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
	else { return false;  }
}

template <typename T>
Stack<T>::~Stack()
{
	Clear();
}