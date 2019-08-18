//min heap

template <typename T>
HeapTree<T>::HeapTree()
{
	Size = 0;
}

template <typename T>
T* HeapTree<T>::Parent(int index)
{
	return &Root.at((index - 1) / 2);
}

template <typename T>
T* HeapTree<T>::LChild(int index)
{
	return &Root.at((index * 2) + 1);
}

template <typename T>
T* HeapTree<T>::RChild(int index)
{
	return &Root.at((index * 2) + 2);
}

template <typename T>
void HeapTree<T>::Add(T value)
{
	Size++;

	//add value to next available slot
	Root.push_back(value);

	int valuesIndex = 0;
	while (Root[valuesIndex] != value)
	{
		valuesIndex++;
	}

	if (valuesIndex > 0)
	{
		while (*Parent(valuesIndex) > value)
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
	if (Size >= 1)
	{
		T temp = Root.front();
		Root[0] = Root.back();
		Root[Size - 1] = temp;
		Root.pop_back();
		Size--;
		int index = 0;
		HeapifyDown(index);
	}

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
	if (value < *Parent(valuesIndex))
	{
		Root[valuesIndex] = *Parent(valuesIndex);
		Root[(valuesIndex - 1) / 2] = value;
	}
}

template <typename T>
void HeapTree<T>::HeapifyDown(int index)
{
	//if there are no children = it is at the bottom of the heap
	if (((index * 2) + 1) >= Size && ((index * 2) + 1) >= Size)
	{
		return;
	}
	//there is no RChild so do not swap with it = swap with LChild if its less than itself
	else if (((index * 2) + 2) >= Size)
	{
		if (*LChild(index) > Root[index])
		{
			return;
		}
		T temp = Root[index];
		Root.at(index) = *LChild(index);
		Root[(index * 2) + 1] = temp;
		return;
	}
	//LChild's value is greater than RChild = swap with RChild
	else if (*LChild(index) > *RChild(index))
	{
		if (*RChild(index) > Root[index])
		{
			return;
		}
		T temp = Root[index];
		Root[index] = *RChild(index);
		Root[(index * 2) + 2] = temp;
		index = (index * 2) + 2;
		HeapifyDown(index);
	}
	//RChild's value is greater than LChild = swap with LChild
	else if (*LChild(index) < *RChild(index))
	{
		if (*LChild(index) > Root[index])
		{
			return;
		}
		T temp = Root[index];
		Root[index] = *LChild(index);
		Root[(index * 2) + 1] = temp;
		index = (index * 2) + 1;
		HeapifyDown(index);
	}
}