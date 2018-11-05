#include "CircularlyDoublyLinkedList.h"
#include <memory>
#include <iostream>

template <typename T>
CircularlyDoublyLinkedList<T>::CircularlyDoublyLinkedList()
{
	Head = nullptr;
	Size = 0;
}

template <typename T>
void CircularlyDoublyLinkedList<T>::AddAt(T value, int index)
{
	if (IsEmpty())
	{
		AddAtHead(value);
	}
}

template <typename T>
void CircularlyDoublyLinkedList<T>::AddAtHead(T value)
{
	if (IsEmpty())
	{
		Head = std::make_shared<CircularlyDoublyLinkedNode<T>>(value);
		Head.get()->nextNode = Head;
		Head->lastNode = Head.get();
	}
	
	//when there are already things in the linked list
	else if (!IsEmpty())
	{
		CircularlyDoublyLinkedNode<T>* end;
		end = Head.get()->lastNode;

		end->nextNode = std::make_shared<CircularlyDoublyLinkedNode<T>>(value);
		end->nextNode->lastNode = end;
		end->nextNode.get()->nextNode = Head;
		Head->lastNode = end->nextNode.get();
		Head = end->nextNode;
	}

	Size++;
}

template <typename T>
void CircularlyDoublyLinkedList<T>::AddAtTail(T value)
{

}

template <typename T>
void CircularlyDoublyLinkedList<T>::Clear()
{
	Head->lastNode->nextNode = nullptr; //cuts off circularity
	Head = nullptr; //calls destructor on the head node which will delete the following nodes NON RECURSIVELY
	Size = 0;
}

template <typename T>
void CircularlyDoublyLinkedList<T>::DeleteAt(int index)
{

}

template <typename T>
void CircularlyDoublyLinkedList<T>::DeleteAtTail()
{

}

template <typename T>
void CircularlyDoublyLinkedList<T>::DeleteValue(T value)
{

}

template <typename T>
bool CircularlyDoublyLinkedList<T>::Found(T value)
{
	CircularlyDoublyLinkedNode<T>* temp = Head.get();
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
void CircularlyDoublyLinkedList<T>::GetAllForward()
{
	CircularlyDoublyLinkedNode<T>* temp;
	temp = Head.get();
	while (temp != nullptr)
	{
		std::cout << temp->Value << " ";
		temp = temp->nextNode.get();
	}
	std::cout << " " << std::endl;
}

template <typename T>
bool CircularlyDoublyLinkedList<T>::IsEmpty()
{
	if (Head == nullptr)
	{
		return true;
	}
	else { return false; }
}

template <typename T>
CircularlyDoublyLinkedList<T>::~CircularlyDoublyLinkedList()
{
	Clear();
}
