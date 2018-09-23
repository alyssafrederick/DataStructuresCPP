#pragma once
#include <memory>
#include "SinglyLinkedNode.h"

class SinglyLinkedList
{
public:
	int Size;
	std::unique_ptr<SinglyLinkedNode> First;
	std::unique_ptr<SinglyLinkedNode> Last;
	void Add(int);
	void Delete(int);
	void Clear();
	bool Found(int);
	SinglyLinkedList();
	~SinglyLinkedList();
};

