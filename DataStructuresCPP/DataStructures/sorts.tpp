

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

}

template <typename T>
Sorts<T>::~Sorts()
{

}