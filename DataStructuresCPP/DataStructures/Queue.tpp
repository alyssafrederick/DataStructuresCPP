
template <typename T>
Queue<T>::Queue()
{
	Size = 0;
}

//head is at the end of the list

template <typename T>
void Queue<T>::Enqueue(T value)
{
	LList.AddAtStart(value);
	Size++;
}

template <typename T>
T Queue<T>::Dequeue()
{
	DoublyLinkedNode<T>* temp = LList.First.get();
	while (temp->nextNode != nullptr)
	{
		temp = temp->nextNode.get();
	}

	T toReturn = temp->Value;

	LList.DeleteAtEnd();
	Size--;

	return toReturn;
}

template <typename T>
T Queue<T>:: Peek()
{
	DoublyLinkedNode<T>* temp = LList.First.get();
	while (temp->nextNode != nullptr)
	{
		temp = temp->nextNode.get();
	}

	return temp->Value;
}

template <typename T>
void Queue<T>::Clear()
{
	LList.Clear();
	Size = 0;
}

template <typename T>
bool Queue<T>::isEmpty()
{
	if (LList.First == nullptr)
	{
		return true;
	}
	else { return false; }
}

template <typename T>
Queue<T>::~Queue()
{
	Clear();
}
