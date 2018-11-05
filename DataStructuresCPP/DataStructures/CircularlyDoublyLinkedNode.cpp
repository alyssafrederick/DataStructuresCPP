#include "CircularlyDoublyLinkedNode.h"


template <typename T>
CircularlyDoublyLinkedNode<T>::CircularlyDoublyLinkedNode(T value)
{
	Value = value;
	nextNode = nullptr;
	lastNode = nullptr;
}

template<typename T>
CircularlyDoublyLinkedNode<T>::~CircularlyDoublyLinkedNode()
{
	std::shared_ptr<CircularlyDoublyLinkedNode<T>> temp = std::move(nextNode);
	while (temp)
	{
		temp = std::move(temp->nextNode);
	}
}
