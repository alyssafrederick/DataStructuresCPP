#pragma once
#include <memory>

template <typename T>
class CircularlyDoublyLinkedNode
{
public:
	T Value;
	std::shared_ptr<CircularlyDoublyLinkedNode> nextNode;
	std::shared_ptr<CircularlyDoublyLinkedNode> lastNode;
	CircularlyDoublyLinkedNode(T value);
};