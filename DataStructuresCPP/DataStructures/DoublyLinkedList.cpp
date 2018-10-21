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
	if (IsEmpty())
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
	//if the list is empty
	if (IsEmpty())
	{
		AddAtEnd(value);
	}

	else
	{
		std::unique_ptr <DoublyLinkedNode<T>> tempHead = std::move(First);
		First = std::make_unique<DoublyLinkedNode<T>>(value);
		tempHead->lastNode = First.get();
		First->nextNode = std::move(tempHead);
	}

	Size++;
}

template <typename T>
void DoublyLinkedList<T>::AddAt(T value, int index)
{
	//if the list is empty
	if (IsEmpty())
	{
		AddAtEnd(value);
	}

	//if the index is out of range
	else if (index > Size || index < 0)
	{
		std::cout << "index is out of range" << std::endl;
	}

	//if the index is in range
	else
	{
		DoublyLinkedNode<T>* temp;
		temp = First.get();

		//index starts at 0
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->nextNode.get();
		}

		std::unique_ptr <DoublyLinkedNode<T>> tempRest = std::move(temp->nextNode);
		temp->nextNode = std::make_unique<DoublyLinkedNode<T>>(value);
		tempRest->lastNode = temp->nextNode.get();
		temp->nextNode->nextNode = std::move(tempRest);
	}

	Size++;
}

template <typename T>
void DoublyLinkedList<T>::Clear()
{
	First = nullptr;
}

template <typename T>
void DoublyLinkedList<T>::DeleteAtEnd()
{
	//if there is nothing in the list
	if (IsEmpty())
	{
		return;
	}

	//if there is only one item in the list
	else if (First->nextNode == nullptr)
	{
		Clear();
	}

	// if there is more than 1 item in the list
	else
	{
		DoublyLinkedNode<T>* temp = First.get();
		while (temp->nextNode != nullptr)
		{
			temp = temp->nextNode.get();
		}

		temp->lastNode->nextNode = nullptr;
		temp->lastNode = nullptr;
	}

	Size--;
}

template <typename T>
void DoublyLinkedList<T>::DeleteAtStart()
{
	//if there is nothing in the list
	if (IsEmpty())
	{
		return;
	}

	//if there is only one item in the list
	else if (First->nextNode == nullptr)
	{
		Clear();
	}

	//if there is more than one item in the list
	else
	{
		std::unique_ptr<DoublyLinkedNode<T>> tempRest = std::move(First->nextNode);
		tempRest->lastNode = nullptr;
		First = std::move(tempRest);
	}
}

template <typename T>
void DoublyLinkedList<T>::DeleteValue(T value)
{
	//if the list is empty
	if (IsEmpty())
	{
		return;
	}

	//if the value to delete is the first in the list
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
void DoublyLinkedList<T>::DeleteAt(int index)
{
	//if the list is empty
	if (IsEmpty())
	{
		return;
	}

	//if the index is not in range of the list
	if (index > Size || index < 0)
	{
		std::cout << "index is out of range" << std::endl;
	}

	//if the index is in range
	else
	{
		DoublyLinkedNode<T>* temp;
		temp = First.get();

		//index starts at 0
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->nextNode.get();
		}

		std::unique_ptr<DoublyLinkedNode<T>> tempRest = std::move(temp->nextNode);
		tempRest->lastNode = nullptr;
		temp->nextNode = std::move(tempRest);
	}
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
		std::cout << temp->Value << " ";
		temp = temp->nextNode.get();
	}
	std::cout << " " << std::endl;
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
