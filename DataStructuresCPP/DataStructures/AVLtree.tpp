template <typename T>
AVLtree<T>::AVLtree()
{
	Root = nullptr;
}

template <typename T>
bool AVLtree<T>::IsEmpty()
{
	if (Root == nullptr)
	{
		return false;
	}
	return true;
}

template <typename T>
void AVLtree<T>::Add(T value)
{
	if (Root == nullptr)
	{
		Root = new AVLnode<T>(value);
		return;
	}
	else
	{
		AVLnode<T> current = Root;
		Stack<AVLnode<T>> stack = new Stack<AVLnode<T>>();

		while (current != null)
		{
			stack.Push(current);

			//if new node's value should be to the left of current
			if (current.Value < value)
			{
				current = current.leftChild;
			}

			//if new node's value should be to the right of current
			else if (current.Value >= value)
			{
				current = current.rightChild;
			}
		}
	}
}

template <typename T>
bool AVLtree<T>::Remove(T value)
{
	return false;
}