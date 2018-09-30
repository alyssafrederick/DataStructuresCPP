#pragma once
#include <memory>


template <typename T>
class SinglyLinkedNode
{
public:
	T Value;
	std::unique_ptr<SinglyLinkedNode> nextNode;
	SinglyLinkedNode(T value);
};

