#pragma once
#include <memory>



class SinglyLinkedNode
{
public:
	int Value;
	std::unique_ptr<SinglyLinkedNode> nextNode;
	SinglyLinkedNode(int value);
};

