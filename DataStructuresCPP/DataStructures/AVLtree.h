#pragma once

#include <memory>
#include <iostream>

#include "AVLnode.h"

template <typename T>
class AVLtree
{
public:
	std::unique_ptr<AVLnode<T>> Root;
	bool IsEmpty();
	void addOld(T value); //old
	void Add(T value);
	AVLnode<T> add(T value, AVLnode<T> parent);

	bool Remove(T value); //old
	AVLnode<T> RotateRight(AVLnode<T> node);
	AVLnode<T> RotateLeft(AVLnode<T> node);
	AVLnode<T> Balance(AVLnode<T> node);

	//void UpdateHeight(AVLnode<T> node);

	AVLtree();
};


#include "AVLtree.tpp"