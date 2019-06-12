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
void AVLtree<T>::Add(T value)
{
	if (Root == nullptr)
	{
		Root = std::make_unique<AVLnode<T>>(value);
		return;
	}
	else
	{
		AVLnode<T>* current = Root.get();
		Stack<T>* stk = new Stack<T>();

		while (current != nullptr)
		{
			stk->Push(current->Value);

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

		if (toRemove != null)
		{

		}
	}
}