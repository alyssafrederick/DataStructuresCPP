#pragma once
#include <memory>

template <typename T>
class CircularlyDoublyLinkedNode
{
public:
	T Value;
	std::shared_ptr<CircularlyDoublyLinkedNode> nextNode;
	CircularlyDoublyLinkedNode* lastNode;
	CircularlyDoublyLinkedNode(T value);
	~CircularlyDoublyLinkedNode();
};