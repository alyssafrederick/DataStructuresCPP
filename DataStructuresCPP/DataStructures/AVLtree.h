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
	int Count;
	void addOld(T value); //old
	bool Removeold(T value); //old
	void Add(T value);
	bool Remove(T value);
	AVLtree();

private:
	std::unique_ptr<AVLnode<T>> add(T value, std::unique_ptr<AVLnode<T>> parent);
	AVLnode<T> remove(T value, AVLnode<T> parent);
	std::unique_ptr<AVLnode<T>> RotateRight(std::unique_ptr<AVLnode<T>> node);
	std::unique_ptr<AVLnode<T>> RotateLeft(std::unique_ptr<AVLnode<T>> node);
	std::unique_ptr<AVLnode<T>> Balance(std::unique_ptr<AVLnode<T>> node);
	void UpdateHeight(AVLnode<T>* node);
};


#include "AVLtree.tpp"