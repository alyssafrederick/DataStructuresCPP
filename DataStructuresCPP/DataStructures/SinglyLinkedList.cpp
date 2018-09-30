#include "SinglyLinkedList.h"
#include <memory>
#include <iostream>

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
	First = nullptr;
	Size = 0;
}

template <typename T>
void SinglyLinkedList<T>::Add(T value)
{
	//when linkedList is empty (first is null)
	if (First == nullptr)
	{
		First = std::make_unique<SinglyLinkedNode<T>>(value);
	}

	//when there are already things in the linkedList
	else if (First != nullptr)
	{
		SinglyLinkedNode<T>* temp;
		temp = First.get();

		while (temp->nextNode != nullptr)
		{
			temp = temp->nextNode.get();
		}

		temp->nextNode = std::make_unique<SinglyLinkedNode<T>>(value);
	}

	Size++;
}

template <typename T>
void SinglyLinkedList<T>::Clear()
{
	First = nullptr;
}

template <typename T>
void SinglyLinkedList<T>::Delete(T value)
{
	//if the head == value
	if (First->Value == value)
	{
		First = std::move(First->nextNode);
		Size--;
		return;
	}

	SinglyLinkedNode<T>* temp = First.get();
	//if the value is in the list
	if (Found(value) == true)
	{
		while (temp->nextNode != nullptr && temp->nextNode->Value != value)
		{
			bool isNull = temp->nextNode->nextNode == nullptr;
			temp = temp->nextNode.get();
		}

		//if the value is in the middle of the list
		if (temp->nextNode->nextNode != nullptr)
		{
			temp->nextNode = std::move(temp->nextNode->nextNode);
		}

		//if the value is at the end
		else if (temp->nextNode->nextNode == nullptr)
		{
			temp->nextNode = nullptr;
		}

		Size--;
	}

	//if the value was not in the list
	else { return; }
}

template <typename T>
bool SinglyLinkedList<T>::Found(T value)
{
	SinglyLinkedNode<T>* temp = First.get();
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
void SinglyLinkedList<T>::GetAll()
{
	SinglyLinkedNode<T>* temp;
	temp = First.get();
	while (temp != nullptr)
	{
		std::cout << temp->Value << std::endl;
		temp = temp->nextNode.get();
	}
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
}
