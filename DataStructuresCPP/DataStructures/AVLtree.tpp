#include "Stack.h"

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
void AVLtree<T>::addOld(T value)
{
	if (Root == nullptr)
	{
		Root = std::make_unique<AVLnode<T>>(value);
		return;
	}
	else
	{
		AVLnode<T>* current = Root.get();
		//Stack<AVLnode<T>>* stk = new Stack<AVLnode<T>>();

		while (current != nullptr)
		{
			//stk->Push(current);

			//if new node's value should be to the left of current
			if (current->Value > value)
			{
				if (current->leftChild == nullptr)
				{
					current->leftChild = std::make_unique<AVLnode<T>>(value);
					break;
				}
				current = current->leftChild.get();
			}

			//if new node's value should be to the right of current
			else if (current->Value <= value)
			{
				if (current->rightChild == nullptr)
				{
					current->rightChild = std::make_unique<AVLnode<T>>(value);
					break;
				}
				current = current->rightChild.get();
			}
		}


	}
}

template <typename T>
void AVLtree<T>::Add(T value)
{
	Root = add(value, Root);
}

template <typename T>
AVLnode<T> AVLtree<T>::add(T value, AVLnode<T> parent)
{
	//placing the new node
	if (parent == nullptr)
	{
		return new AVLnode<T>(value);
	}

	//if the new node is to the left of the parent
	if (value < parent->Value)
	{
		parent->leftChild = add(item, parent->leftChild.get());
	}
	//if the new node is to the right of the parent
	else if (parent->Value < value)
	{
		parent->rightChild = add(item, parent->rightChild.get());
	}


	//TODO:
	//UpdateHeight(parent);
	//return Balance(parent);
};

template <typename T>
bool AVLtree<T>::Remove(T value)
{
	if (Root == nullptr)
	{
		return false;
	}
	else
	{
		AVLnode<T>* temp = Root.get();
		AVLnode<T>* toRemove = nullptr;

		//finding and setting the node toRemove
		while (temp != nullptr)
		{
			//if node to remove is to the left of temp
			if (temp->Value > value)
			{
				temp = temp->leftChild;
			}

			//if node to remove is to the right of temp
			else if (temp->Value = value)
			{
				temp = temp->rightChild;
			}

			//if we have found the node to remove
			else if (temp->Value == value)
			{
				toRemove = temp;
			}
		}

		if (toRemove != nullptr)
		{
			//if toRemove has no children
			if (toRemove->leftChild == nullptr && toRemove->rightChild == nullptr)
			{
				//if toRemove is a left child
				
				//if toRemove is a right child
			}

			//if toRemove only has a left child
			else if (toRemove->rightChild == nullptr)
			{

			}

			//if toRemove only has a right child
			else if (toRemove->leftChild == nullptr)
			{

			}

			//if toRemove has a left and right child
			else
			{

			}
		}
	}
}

template <typename T>
AVLnode<T> AVLtree<T>::RotateRight(AVLnode<T> node)
{

}

template <typename T>
AVLnode<T> AVLtree<T>::RotateLeft(AVLnode<T> node)
{

}

template <typename T>
AVLnode<T> AVLtree<T>::Balance(AVLnode<T> node)
{
	if (node.Balance < -1)
	{

	}
	else if (node.Balance > 1)
	{

	}

	return node;
}