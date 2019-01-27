
template <typename T>
bstNode<T>::bstNode(T value)
{
	Value = value;
	parent = nullptr;
	leftChild = nullptr;
	rightChild = nullptr;
}

