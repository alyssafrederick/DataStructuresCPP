#include "Stack.h"

template <typename T>
AVLtree<T>::AVLtree()
{
	Root = nullptr;
	Count = 0;
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
	//USE std::move	
	Root = add(value, std::move(Root));
	Count++;
}

template <typename T>
std::unique_ptr<AVLnode<T>> AVLtree<T>::add(T value, std::unique_ptr<AVLnode<T>> current)
{
	//placing the new node
	if (current == nullptr)
	{
		return std::make_unique<AVLnode<T>>(value);
	}

	//if the new node is to the left of the parent
	if (value < current->Value)
	{
		current->leftChild = add(value, std::move(current->leftChild));
	}

	//if the new node is to the right of the parent
	else if (current->Value < value)
	{
		current->rightChild = add(value, std::move(current->rightChild));
	}

	/*UpdateHeight(parent);
	return Balance(parent);*/
	return std::move(current);
};

template <typename T>
bool AVLtree<T>::Removeold(T value)
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
bool Remove(T value)
{
	return true;
	/*
	int oldCount = Count;
	Root = Remove(value, Root);
	return oldCount != Count;
	*/
}

template <typename T>
AVLnode<T> AVLtree<T>::remove(T value, AVLnode<T> parent)
{

}

template <typename T>
std::unique_ptr<AVLnode<T>> AVLtree<T>::RotateRight(AVLnode<T> node)
{
	T pivot = node->rightChild;
	node->leftChild = pivot->rightChild;
	pivot->righttChild = node;
	UpdateHeight(node);
	return pivot;
}

template <typename T>
std::unique_ptr<AVLnode<T>> AVLtree<T>::RotateLeft(AVLnode<T> node)
{
	T pivot = node->rightChild;
	node->rightChild = pivot->leftChild;
	pivot->leftChild = node;
	UpdateHeight(node);
	return pivot;
}

template <typename T>
std::unique_ptr<AVLnode<T>> AVLtree<T>::Balance(AVLnode<T> node)
{
	if (node.Balance < -1)
	{
		if (node->leftChild.Balance() > 0)
		{
			node.leftChild = RotateLeft(node->leftChild);
		}
		node = RotateRight(node);
	}
	else if (node.Balance > 1)
	{
		if (node->rightChild.balace() < 0)
		{
			node.rightChild = RotateRight(node->rightChild);
		}
		node = RotateLeft(node);
	}


	return node;
}

template <typename T>
void AVLtree<T>::UpdateHeight(AVLnode<T> node)
{
	if (node->leftChild == nullptr && node->rightChild == nullptr)
	{
		return 1;
	}
	else
	{
		if (node->leftChild.Height() > node->rightChild.Height())
		{
			return node->leftChild.Height() + 1;
		}
		else
		{
			return node->rightChild.Height() + 1;
		}
	}
}