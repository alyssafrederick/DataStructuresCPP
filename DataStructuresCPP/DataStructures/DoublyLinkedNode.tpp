
template <typename T>
DoublyLinkedNode<T>::DoublyLinkedNode(T value)
{
	Value = value;
	nextNode = nullptr;
	lastNode = nullptr;
}

