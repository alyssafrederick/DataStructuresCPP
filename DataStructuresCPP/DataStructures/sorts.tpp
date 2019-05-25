

template <typename T>
Sorts<T>::Sorts()
{

}

template <typename T>
void Sorts<T>::BubbleSort()
{
	bool swapped;

	do
	{
		swapped = false;
		for (int i = 0; i < toSort.size() - 1; i++)
		{
			if (toSort.at(i) > toSort.at(i + 1))
			{
				swapped = true;
				T temp = toSort.at(i);
				toSort.at(i) = toSort.at(i + 1);
				toSort.at(i + 1) = temp;
			}
		}
	} while (swapped == true);

}

template <typename T>
void Sorts<T>::SelectionSort()
{
	for (int i = 0; i < toSort.size(); i++)
	{
		int smallestindex = i;
		int smallest = toSort.at(i);

		for (int k = i + 1; k < toSort.size(); k++)
		{
			if (toSort.at(k) < smallest)
			{
				smallest = toSort.at(k);
				smallestindex = k;
			}
		}

		T temp = toSort.at(i);
		toSort.at(i) = smallest;
		toSort.at(smallestindex) = temp;
	}
}

template <typename T>
void Sorts<T>::InsertionSort()
{
	for (int i = 0; i < toSort.size(); i++)
	{
		for (int k = i - 1; k > -1; k--)
		{
			if (toSort.at(k) > toSort.at(k + 1))
			{
				T temp = toSort.at(k + 1);
				toSort.at(k + 1) = toSort.at(k);
				toSort.at(k) = temp;
			}

		}
	}
}

template <typename T>
void Sorts<T>::MergeSort(int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		MergeSort(start, mid);
		MergeSort(mid + 1, end);
		Merge(start, end);
	}
}

template <typename T>
void Sorts<T>::Merge(int start, int end)
{
	for (int i = start; i < end; i++)
	{
		for (int k = i; k < end - 1; k++)
		{
			if (toSort.at(k) > toSort.at(k + 1))
			{
				T temp = toSort.at(k);
				toSort.at(k) = toSort.at(k + 1);
				toSort.at(k + 1) = temp;
			}
		}
	}
}

template <typename T>
void Sorts<T>::QuickSort()
{

}

template <typename T>
int Sorts<T>::HoarePartition(int left, int right)
{
	int pivot = toSort.at(left);

	while (left < right)
	{
		while (toSort.at(left) < pivot)
		{
			left++;
		}
		while (toSort.at(right) > pivot)
		{
			right--;
		}

		T temp = toSort.at(left);
		toSort.at(left) = toSort.at(right);
		toSort.at(right) = temp;
	}
	
	

}

template <typename T>
Sorts<T>::~Sorts()
{

}