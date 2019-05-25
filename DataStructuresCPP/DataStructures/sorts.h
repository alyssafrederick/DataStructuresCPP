#pragma once

#include <memory>
#include <iostream>
#include <vector>

template <typename T>
class Sorts
{
public:
	std::vector<T> toSort;
	void BubbleSort();
	void SelectionSort();
	void InsertionSort();
	Sorts();
	~Sorts();
};

#include "Sorts.tpp"

