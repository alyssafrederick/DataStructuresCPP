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
		current = Balance(std::move(current));
	}
	//if the new node is to the right of the parent
	else if (current->Value < value)
	{
		current->rightChild = add(value, std::move(current->rightChild));
		current = Balance(std::move(current));
	}

	return current;

	//return std::move(current); ->for bst -> this will be in balance() somewhere
}

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
bool AVLtree<T>::Remove(T value)
{
	int oldCount = Count;
	Root = remove(value, std::move(Root));
	return oldCount != Count;
}

template <typename T>
std::unique_ptr<AVLnode<T>> AVLtree<T>::remove(T value, std::unique_ptr<AVLnode<T>> current)
{
	if (current == nullptr)
	{
		return nullptr;
	}

	//if the value to remove is to the left of the current
	if (current->Value > value)
	{
		current->leftChild = remove(value, std::move(current->leftChild));
		current = Balance(std::move(current));
	}
	//if the value to remove is to the right of the current
	else if (current->Value < value)
	{
		current->rightChild = remove(value, std::move(current->rightChild));
		current = Balance(std::move(current));
	}
	else if (current->Value == value)
	{
		//if current doesn't have a left/right child
		if (current->leftChild == nullptr && current->rightChild == nullptr)
		{
			Count--;
			return nullptr;
		}

		//if current only has a right child
		else if (current->leftChild == nullptr)
		{
			Count--;
			return std::move(current->rightChild);
		}

		//if current only has a left child
		else if (current->rightChild == nullptr)
		{
			Count--;
			return std::move(current->leftChild);
		}

		//if current has both a left and right child
		else
		{
			AVLnode<T>* temp = current->leftChild.get();
			while (temp->rightChild != nullptr)
			{
				temp = temp->rightChild.get();
			}
			T tempVal = temp->Value;
			current = remove(tempVal, std::move(current));
			current->Value = tempVal;
		}
	}
	return current;
}

template <typename T>
std::unique_ptr<AVLnode<T>> AVLtree<T>::RotateRight(std::unique_ptr<AVLnode<T>> node)
{
	std::unique_ptr<AVLnode<T>> pivot = std::move(node->leftChild);
	node->leftChild = std::move(pivot->rightChild);
	pivot->rightChild = std::move(node);
	return pivot;
}

template <typename T>
std::unique_ptr<AVLnode<T>> AVLtree<T>::RotateLeft(std::unique_ptr<AVLnode<T>> node)
{
	std::unique_ptr<AVLnode<T>> pivot = std::move(node->rightChild);
	node->rightChild = std::move(pivot->leftChild);
	pivot->leftChild = std::move(node);
	//UpdateHeight(std::move(node));
	return pivot;
}

template <typename T>
std::unique_ptr<AVLnode<T>> AVLtree<T>::Balance(std::unique_ptr<AVLnode<T>> node)
{
	node = UpdateHeight(std::move(node));

	if (node->Balance() < -1)
	{
		if (node->leftChild->Balance() > 0)
		{
			node->leftChild = RotateLeft(std::move(node->leftChild));
			node->leftChild->rightChild = UpdateHeight(std::move(node->leftChild->rightChild));
			node->leftChild->leftChild = UpdateHeight(std::move(node->leftChild->leftChild));
		}
		node = RotateRight(std::move(node));
		node->rightChild = UpdateHeight(std::move(node->rightChild));
	}
	else if (node->Balance() > 1)
	{
		if (node->rightChild->Balance() < 0)
		{
			node->rightChild = RotateRight(std::move(node->rightChild));
			node->rightChild->rightChild = UpdateHeight(std::move(node->rightChild->rightChild));
			node->rightChild->leftChild = UpdateHeight(std::move(node->rightChild->leftChild));
		}
		node = RotateLeft(std::move(node));
		node->leftChild = UpdateHeight(std::move(node->leftChild));
	}

	return node;//std::move(node);
}

template <typename T>
std::unique_ptr<AVLnode<T>> AVLtree<T>::UpdateHeight(std::unique_ptr<AVLnode<T>> node)
{

	int rightHeight = node->rightChild == nullptr ? 0 : node->rightChild->GetHeight();
	int leftHeight = node->leftChild == nullptr ? 0 : node->leftChild->GetHeight();
	node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
	//std::cout << "Height of node " << node->Value << " is now " << ptr->Height << std::endl;
	node->balance = rightHeight - leftHeight;

	//if (node->leftChild == nullptr && node->rightChild == nullptr)
	//{
	//	//node->Height() = 1;
	//	node->ResetHeight();
	//}
	//else if (node->leftChild == nullptr)
	//{
	//	node->rightChild->IncrementHeight();
	//}
	//else if (node->rightChild == nullptr)
	//{
	//	node->leftChild->IncrementHeight();
	//}
	//else
	//{
	//	//height on the left is greater than height on the right
	//	if (node->leftChild->GetHeight() > node->rightChild->GetHeight())
	//	{
	//		node->leftChild->IncrementHeight();
	//	}
	//	//height on the right is greater than height on the left
	//	else
	//	{
	//		node->rightChild->IncrementHeight();
	//	}
	//}

	return node;
}