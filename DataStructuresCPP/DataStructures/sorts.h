#pragma once

#include <memory>
#include <iostream>

template <typename T>
class sorts
{
public:
	int size;
	std::array <T, int size>;
	void BubbleSort();
	void SelectionSort();
	void InsertionSort();
	sorts();
	~sorts();
};

#include "sorts.tpp"