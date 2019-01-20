#pragma once

//both a part of std
#include <memory>    //uniqueptr, etc
#include <iostream>  //cout, cin, etc

template <typename T>
class CircularlyDoublyLinkedNode
{
public:
	T Value;
	std::shared_ptr<CircularlyDoublyLinkedNode> nextNode;
	std::shared_ptr<CircularlyDoublyLinkedNode> lastNode;
	CircularlyDoublyLinkedNode(T value);
};


#include "CircularlyDoublyLinkedNode.tpp"