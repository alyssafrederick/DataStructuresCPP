#include "HeapTree.h"
//min heap

template <typename T>
HeapTree<T>::HeapTree()
{
	Root = std::make_unique<T[]>(3);
	Size = 0;
}

template <typename T>
T* HeapTree<T>::Parent(int index)
{
	return Root[(index - 1) / 2];
}

template <typename T>
T* HeapTree<T>::LChild(int index)
{
	return Root[(index * 2) + 1];
}

template <typename T>
T* HeapTree<T>::RChild(int index)
{
	return Root[(index * 2) + 2]
}

template <typename T>
void HeapTree<T>::Add(T value)
{
	Size++;

	//if the new size is bigger than the root's length, double the slots in array
	if (Size >= Root.Length) //CHECK
	{
		Resize(Root.Length * 2);
	}
	//add value to next available slot
	Root[Size - 1] = value;

	int valuesIndex = 0;
	while (Root[valuesIndex] != value)
	{
		valuesIndex++
	}

	if (valuesIndex > 0)
	{
		while (Parent(valuesIndex) > value)
		{
			HeapifyUp(value);

			valuesIndex = 0;
			while (Root[valuesIndex] != value)
			{
				valuesIndex++;
			}
		}
	}

}

template <typename T>
void HeapTree<T>::Pop()
{
	if (Size > 1)
	{
		int index = 0;
		HeapifyDown(index);
	}
	Size--;
}

template <typename T>
void HeapTree<T>::HeapifyUp(T value)
{
	int valuesIndex = 0;
	while (Root[valuesIndex] != value)
	{
		valuesIndex++;
	}

	//if the value is less than its parent's, switch value and parent 
	if (value < Parent(valuesIndex))
	{
		Root[valuesIndex] = Parent(valuesIndex);
		Root[(valuesIndex - 1) / 2] = value;
	}
}

template <typename T>
void HeapTree<T>::HeapifyDown(int index)
{
	//if there are no children = it is at the bottom of the heap
	if (((index * 2) + 1) > Size && ((index * 2) + 1) > Size)
	{
		return;
	}
	//there is no RChild so do not swap with it = swap with LChild
	else if (((index * 2) + 2) >= Size)
	{
		T temp = Root[index];
		Root[index] = LChild(index);
		Root[(index * 2) + 1] = temp;
		return;
	}
	//LChild's value is greater than RChild = swap with RChild
	else if (LChild(index) > RChild(index))
	{
		T temp = Root[index];
		Root[index] = RChild(index);
		Root[(index * 2) + 2] = temp;
		index = (index * 2) + 2;
		HeapifyDown(index);
	}
	//wants to swap with LChild but if it does, there will just be a RChild
	else if (LChild(index) < RChild(index))
	{
		Root[index] = LChild(index);
		Root[(index * 2) + 1] = Root[(index * 2) + 2];
		index = (index * 2) + 1;
		HeapifyDown(index);
	}
}

template <typename T>
void HeapTree<T>::Resize(int size)
{
	T[] temp = new T[size];
	if (size > 1)
	{
		for (int i = 0; i < size; i++)
		{
			temp[i] = Root[i];
		}
	}
	Root = temp;
}