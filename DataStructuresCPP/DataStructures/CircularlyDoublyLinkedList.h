#pragma once

#include <memory>
#include "CircularlyDoublyLinkedNode.h"

template <typename T>
class CircularlyDoublyLinkedList
{
public:
	int Size;
	std::shared_ptr<CircularlyDoublyLinkedNode<T>> Head;
	void AddAt(T, int);
	void AddAtHead(T);
	void AddAtTail(T);
	void Clear();
	void DeleteAtTail();
	void DeleteValue(T);
	void DeleteAt(int);
	bool Found(T);
	void GetAllForward();
	bool IsEmpty();
	CircularlyDoublyLinkedList();
	~CircularlyDoublyLinkedList();
};

#include "CircularlyDoublyLinkedList.tpp"