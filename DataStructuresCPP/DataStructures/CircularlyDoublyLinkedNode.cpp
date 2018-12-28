#include "CircularlyDoublyLinkedNode.h"


template <typename T>
CircularlyDoublyLinkedNode<T>::CircularlyDoublyLinkedNode(T value)
{
	Value = value;
	nextNode = nullptr;
	lastNode = nullptr;
}

