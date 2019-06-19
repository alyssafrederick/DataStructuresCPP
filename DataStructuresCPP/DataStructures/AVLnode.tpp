template <typename T>
AVLnode<T>::AVLnode(T value)
{
	Value = value;
	leftChild = nullptr;
	rightChild = nullptr;
	heightCallCount = 0;
}

template <typename T>
int AVLnode<T>::Height()
{
	heightCallCount++;

	if (leftChild == nullptr && rightChild == nullptr)
	{
		heightCallCount = 0;
		return 1;
	}
	else
	{
		if (leftChild.Height() > rightChild.Height())
		{
			return leftChild.Height() + 1;
		}
		else
		{
			return rightChild.Height() + 1;
		}
	}
}

template <typename T>
int AVLnode<T>::Balance()
{
	int leftCount = 0;
	int rightCount = 0;

	if (leftChild == nullptr)
	{
		int leftCount = 0;
	}
	else
	{
		leftCount = leftChild.Height();
	}
	if (rightChild == nullptr)
	{
		int rightCount = 0;
	}
	else
	{
		rightCount = rightChild.Height();
	}
	return rightCount - leftCount;
}