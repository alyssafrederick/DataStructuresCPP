#pragma once

template <typename T>
binarySearchTree<T>::binarySearchTree()
{
	Root = nullptr;
	Size = 0;
	order = new Stack<T>();
}

template <typename T>
bool binarySearchTree<T>::isEmpty()
{
	if (Root == nullptr)
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
		bstNode<T>* toRemove = nullptr;

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
				toRemove->parent->leftChild = std::move(toRemove->rightChild);
			}

			//if toRemove only has a left child
			else if (toRemove->rightChild == nullptr)
			{
				toRemove->leftChild->parent = toRemove->parent;
				toRemove->parent->rightChild = std::move(toRemove->leftChild);
			}

			//if toRemove has both a left and right child
			else
			{
				//stepping left once
				bool movedRight = false;
				temp = toRemove->leftChild.get();

				//stepping right until we have found the greatest node on the left subtree
				if (temp->rightChild != nullptr)
				{
					temp = Maximum(temp);
					movedRight = true;
				}


				toRemove->Value = std::move(temp->Value);

				//deleting temp because we just swapped it with toRemove
					//if temp is a left child, then delete the parent's connection to it
				if (temp->parent->leftChild.get() == temp)
				{
					temp->parent->leftChild = nullptr;
				}
				//if temp is a right child, then delete the parent's connection to it
				else if (temp->parent->rightChild.get() == temp)
				{
					temp->parent->rightChild = nullptr;
				}

				temp->parent = nullptr;
			}

			Size--;
			return true;
		}
	}

	return false;
}

template <typename T>
bstNode<T>* binarySearchTree<T>::Search(T value)
{
	bstNode<T>* temp = Root.get();

	while (temp != nullptr)
	{
		if (temp->Value > value)
		{
			temp = temp->leftChild.get();
		}
		if (temp->Value < value)
		{
			temp = temp->rightChild.get();
		}
		if (temp->Value == value)
		{
			return temp;
		}
	}
}

template <typename T>
bstNode<T>* binarySearchTree<T>::Maximum(bstNode<T>* node)
{
	bstNode<T>* temp = node;
	while (temp->rightChild != nullptr)
	{
		temp = temp->rightChild.get();
	}
	return temp;
}

template <typename T>
bstNode<T>* binarySearchTree<T>::Minimun(bstNode<T>* node)
{
	bstNode<T>* temp = node;
	while (temp->leftChild != nullptr)
	{
		temp = temp->leftChild.get();
	}
	return temp;
}

template <typename T>
void binarySearchTree<T>::TraverseInOrder(bstNode<T>* node)
{
	if (node->leftChild != nullptr)
	{
		TraversePreOrder(node->leftChild.get());
	}

	order->Push(node->Value);

	if (node->rightChild != nullptr)
	{
		TraversePreOrder(node->rightChild.get());
	}
}

template <typename T>
void binarySearchTree<T>::TraversePostOrder(bstNode<T>* node)
{
	if (node->leftChild != nullptr)
	{
		TraversePreOrder(node->leftChild.get());
	}

	if (node->rightChild != nullptr)
	{
		TraversePreOrder(node->rightChild.get());
	}

	order->Push(node->Value);

	//another implementation
	//https://www.geeksforgeeks.org/iterative-postorder-traversal-using-stack/
}

template <typename T>
void binarySearchTree<T>::TraversePreOrder(bstNode<T>* node)
{
	order->Push(node->Value);

	if (node->leftChild != nullptr)
	{
		TraversePreOrder(node->leftChild.get());
	}

	if (node->rightChild != nullptr)
	{
		TraversePreOrder(node->rightChild.get());
	}
}

template <typename T>
void binarySearchTree<T>::TraverseLevelOrder()
{
	if (Root == nullptr)
	{
		return;
	}
	Queue<T>* q = new Queue<T>();

	Search(Root.Value);
	q.Enqueue(Root.Value.get());

	while (q.isEmpty == false)
	{
		T temp = q.Dequeue();
		order->Push(temp->value);
		bstNode<T>* node = Search(temp);

		if (node.leftChild != nullptr)
		{
			q.Enqueue(node.leftChild.Value.get());
		}
		if (node.rightChild != nullptr)
		{
			q.Enqueue(node.rightChild.Value.get());
		}
	}
}

template <typename T>
binarySearchTree<T>::~binarySearchTree()
{

}