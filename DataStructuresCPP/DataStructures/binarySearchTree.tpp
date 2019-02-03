#pragma once

template <typename T>
binarySearchTree<T>::binarySearchTree()
{
	Root = nullptr;
	int Size = 0;
}

template <typename T>
bool binarySearchTree<T>::isEmpty()
{
	if(Root == nullptr)
	{
		return true;
	}
	return false;
}

template <typename T>
void binarySearchTree<T>::Add(T value)
{
	//when there is no root, insert T at root
	if (isEmpty())
	{
		Root = std::make_unique<bstNode<T>>(value);
		Size++;
		return;
	}

	//when there is already a root 
	else
	{
		bstNode<T>* temp = Root.get();
		while (temp != nullptr)
		{
			//if value is greater than/equal, traverse right
			if (value >= temp->Value)
			{
				//if there is no right child, add it
				if (temp->rightChild == nullptr)
				{
					temp->rightChild = std::make_unique<bstNode<T>>(value);
					temp->rightChild->parent = temp;
					Size++;
					return;
				}

				//continue looking where to put this new node
				temp = temp->rightChild.get();
			}

			//if value is less than, traverse left
			else if (value < temp->Value)
			{
				//if there is no left child, add it
				if (temp->leftChild == nullptr)
				{
					temp->leftChild = std::make_unique<bstNode<T>>(value);
					temp->leftChild->parent = temp;
					Size++;
					return;
				}

				//continue looking where to put this new node
				temp = temp->leftChild.get();
			}
		}

	}

}

template <typename T>
bool binarySearchTree<T>::Remove(T value)
{
	//when there is no root, there is nothing to remove -> return false
	if (isEmpty())
	{
		return false;
	}

	//when there is already a root
	else
	{
		bstNode<T>* temp = Root.get();
		bstNode<T>* toRemove;

		//find where the value to remove is
		while (temp != nullptr)
		{
			//if value is greater than, traverse right
			if (value >= temp->Value)
			{
				if (value == temp->Value)
				{
					toRemove = temp;
				}
				temp = temp->rightChild.get();
			}

			//if value is less than, traverse left
			else if (value < temp->Value)
			{
				temp = temp->leftChild.get();
			}
		}

		if (toRemove != nullptr)
		{
			//if toRemove doesn't have a left or right child
			if (toRemove->leftChild == nullptr && toRemove->rightChild == nullptr)
			{
				//if toRemove is a left child, then delete the parent's connection to it
				if (toRemove->parent->leftChild.get() == toRemove)
				{
					toRemove->parent->leftChild = nullptr;
				}

				//if toRemove is a right child, then delete the parent's connection to it
				else if (toRemove->parent->rightChild.get() == toRemove)
				{
					toRemove->parent->rightChild = nullptr;
				}

				toRemove->parent = nullptr;
			}

			//if toRemove only has a right child
			else if (toRemove->leftChild == nullptr)
			{
				toRemove->rightChild->parent = toRemove->parent;
				toRemove->parent->leftChild = toRemove->rightChild;
			}

			//if toRemove only has a left child
			else if (toRemove->rightChild == nullptr)
			{
				toRemove->leftChild->parent = toRemove->parent;
				toRemove->parent->rightChild = toRemove->leftChild;
			}

			//if toRemove has both a left and right child
			else
			{
				bool movedRight = false;
				temp = toRemove->leftChild.get();

				while (temp->rightChild != nullptr)
				{
					temp = temp->rightChild.get();
					movedRight = true;
				}

				if (movedRight == true)
				{
					temp->leftChild = toRemove->leftChild;
					temp->leftChild->parent = temp;
				}

				//if the node is a left child
				if (toRemove->parent->leftChild.get() == toRemove)
				{
					temp->parent = toRemove->parent;
					toRemove->parent->leftChild = std::move(temp);   //FIX
				}

				//if the node is a right child
				else if (toRemove->parent->rightChild.get() == toRemove)
				{
					temp->parent = toRemove->parent;
					toRemove->parent->rightChild = temp;
				}

				temp->rightChild = toRemove->rightChild;
				temp->rightChild->parent = temp;                     //FIX
			}

			return true;
		}
	}

	return false;
}

template <typename T>
bstNode<T>* binarySearchTree<T>::Search(T value)
{

}

template <typename T>
bstNode<T>* binarySearchTree<T>::Maximum(bstNode<T>* node)
{

}

template <typename T>
bstNode<T>* binarySearchTree<T>::Minimun(bstNode<T>* node)
{

}

template <typename T>
void binarySearchTree<T>::TraverseInOrder()
{

}

template <typename T>
void binarySearchTree<T>::TraversePostOrder()
{

}

template <typename T>
void binarySearchTree<T>::TraversePreOrder()
{

}

template <typename T>
void binarySearchTree<T>::TraverseLevelOrder()
{

}

template <typename T>
binarySearchTree<T>::~binarySearchTree()
{

}