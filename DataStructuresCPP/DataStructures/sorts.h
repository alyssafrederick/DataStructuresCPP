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
	void MergeSort(int start, int end);
	void Merge(int start, int end);
	void QuickSort(int start, int end);
	int HoarePartition(int left, int right);
	Sorts();
	~Sorts();
};

#include "Sorts.tpp"

