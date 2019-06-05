
template <typename T>
AVLnode<T>::AVLnode(T value)
{
	Value = value;
	parent = nullptr;
	left = nullptr;
	right = nullptr;
}
