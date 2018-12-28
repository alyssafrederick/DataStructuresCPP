#pragma once

#include <memory>

template <typename T>
class DoublyLinkedNode
{
public:
	T Value;
	std::unique_ptr<DoublyLinkedNode> nextNode;
	DoublyLinkedNode* lastNode;
	DoublyLinkedNode(T value);
};

#include "DoublyLinkedNode.tpp"