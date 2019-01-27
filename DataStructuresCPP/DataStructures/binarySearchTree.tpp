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
		bstNode<T>* temp = Root;   //ERROR
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
					return;
				}
				//

			}
			//if value is less than, traverse left
			else if (value < temp->Value)
			{
				//if there is no left child, add it
				if (temp->leftChild == nullptr)
				{
					temp->leftChild = std::make_unique<bstNode<T>>(value);
					temp->leftChild->parent = temp;
					return;
				}
				//

			}
		}

		Size++;
	}

}

template <typename T>
bool binarySearchTree<T>::Remove(T value)
{

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