#include "CircularlyDoublyLinkedNode.h"
#include <memory>
#include <iostream>

template <typename T>
CircularlyDoublyLinkedNode<T>::CircularlyDoublyLinkedNode(T value)
{
	Value = value;
	nextNode = nullptr;
	lastNode = nullptr;
}