#pragma once
#include <memory>


template <typename T>
class DoublyLinkedNode
{
public:
	T Value;
	std::unique_ptr<SinglyLinkedNode> nextNode;
	std::unique_ptr<SinglyLinkedNode> lastNode;
	DoublyLinkedNode(T value);
};

