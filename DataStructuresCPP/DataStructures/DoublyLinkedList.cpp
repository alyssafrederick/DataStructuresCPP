#include "DoublyLinkedList.h"
#include <memory>
#include <iostream>

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	First = nullptr;
	Size = 0;
}

template <typename T>
void DoublyLinkedList<T>::AddAtEnd(T value)
{
	//when linkedList is empty (first is null)
	if (First == nullptr)
	{
		First = std::make_unique<DoublyLinkedNode<T>>(value);
	}

	//when there are already things in the linkedList
	else if (First != nullptr)
	{
		DoublyLinkedNode<T>* temp;
		temp = First.get();

		while (temp->nextNode != nullptr)
		{
			temp = temp->nextNode.get();
		}

		temp->nextNode = std::make_unique<DoublyLinkedNode<T>>(value);
		temp->nextNode->lastNode = temp;
	}

	Size++;
}

template <typename T>
void DoublyLinkedList<T>::AddAtStart(T value)
{
	//////////////////////////////////////////////////////////////////to do 
	DoublyLinkedNode<T>* temp = First.get();

	First = std::make_unique<DoublyLinkedList<T>>(value);
	First->nextnode = temp;

	
}

template <typename T>
void DoublyLinkedList<T>::AddAt(T value, int index)
{

}

template <typename T>
void DoublyLinkedList<T>::Clear()
{
	First = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::DeleteAtEnd()
{

}

template <typename T>
void DoublyLinkedList<T>::DeleteAtStart()
{

}

template <typename T>
void DoublyLinkedList<T>::DeleteValue(T value)
{
	if (First->Value == value)
	{
		First = std::move(First->nextNode);
		Size--;
		return;
	}

	DoublyLinkedNode<T>* temp = First.get();
	if (Found(value))
	{
		while (temp->nextNode != nullptr && temp->nextNode->Value != value)
		{
			bool isNull = temp->nextNode->nextNode == nullptr;
			temp = temp->nextNode.get();
		}

		//we want to get rid of temp.nextnode
		//if the value is in the middle of the list
		if (temp->nextNode->nextNode != nullptr)
		{
			temp->nextNode = std::move(temp->nextNode->nextNode);
			temp->nextNode->lastNode = temp;
		}

		//if the value is at the end
		else if (temp->nextNode->nextNode == nullptr)
		{
			temp->nextNode = nullptr;
		}

		Size--;
	}

	else { return; }
}

template <typename T>
void DoublyLinkedList<T>::DeleteAt(T value, int index)
{

}

template <typename T>
bool DoublyLinkedList<T>::Found(T value)
{
	DoublyLinkedNode<T>* temp = First.get();
	while (temp->nextNode != nullptr && temp->Value != value)
	{
		temp = temp->nextNode.get();
	}

	if (temp->Value == value)
	{
		std::cout << "true" << std::endl;
		return true;
	}
	if (temp->nextNode == nullptr)
	{
		std::cout << "false" << std::endl;
		return false;
	}
}

template <typename T>
void DoublyLinkedList<T>::GetAllForward()
{
	DoublyLinkedNode<T>* temp;
	temp = First.get();
	while (temp != nullptr)
	{
		std::cout << temp->Value << std::endl;
		temp = temp->nextNode.get();
	}
}

template <typename T>
bool DoublyLinkedList<T>::IsEmpty()
{
	if (First == nullptr)
	{
		return true;
	}
	else { return false; }
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
}
