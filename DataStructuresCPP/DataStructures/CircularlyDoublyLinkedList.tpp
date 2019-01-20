
template <typename T>
CircularlyDoublyLinkedList<T>::CircularlyDoublyLinkedList()
{
	Head = nullptr;
	Size = 0;
}

template <typename T>
void CircularlyDoublyLinkedList<T>::AddAt(T value, int index)
{
	if (IsEmpty())
	{
		AddAtHead(value);
		return;
	}

	//when there already things in the list
	else if (!IsEmpty() && 0 <= index && index <= Size)
	{
		std::shared_ptr<CircularlyDoublyLinkedNode<T>> temp = Head;
		int count = 0;
		while (count < index - 1)
		{
			temp = temp->nextNode;
			count++;
		}

		std::shared_ptr<CircularlyDoublyLinkedNode<T>> save = temp->nextNode;
		temp->nextNode = std::make_shared<CircularlyDoublyLinkedNode<T>>(value);
		temp->nextNode->lastNode = temp;
		temp->nextNode->nextNode = save;
		save->lastNode = temp->nextNode;
	}

	else
	{
		return;
	}

	Size++;
}

template <typename T>
void CircularlyDoublyLinkedList<T>::AddAtHead(T value)
{
	if (IsEmpty())
	{
		Head = std::make_shared<CircularlyDoublyLinkedNode<T>>(value);
		Head.get()->nextNode = Head;
		Head->lastNode = Head;
	}

	//when there are already things in the linked list
	else if (!IsEmpty())
	{
		std::shared_ptr<CircularlyDoublyLinkedNode<T>> end;
		end = Head->lastNode;

		end->nextNode = std::make_shared<CircularlyDoublyLinkedNode<T>>(value);
		end->nextNode->lastNode = end;
		end->nextNode.get()->nextNode = Head;
		Head->lastNode = end->nextNode;
		Head = end->nextNode;
	}

	Size++;
}

template <typename T>
void CircularlyDoublyLinkedList<T>::AddAtTail(T value)
{
	if (IsEmpty())
	{
		AddAtHead(value);
		return;
	}
	else
	{
		std::shared_ptr<CircularlyDoublyLinkedNode<T>> temp = Head;
		while (temp->nextNode != Head)
		{
			temp = temp->nextNode;
		}

		temp->nextNode = std::make_shared<CircularlyDoublyLinkedNode<T>>(value);
		temp->nextNode->lastNode = temp;
		temp->nextNode.get()->nextNode = Head;
		Head->lastNode = temp->nextNode;
	}

	Size++;
}

template <typename T>
void CircularlyDoublyLinkedList<T>::Clear()
{
	Head->lastNode->nextNode = nullptr; //cuts off circularity
	Head = nullptr; //calls destructor on the head node which will delete the following nodes NON RECURSIVELY
	Size = 0;
}

template <typename T>
void CircularlyDoublyLinkedList<T>::DeleteAt(int index)
{
	if (IsEmpty())
	{
		return;
	}

	else if (Head->lastNode->lastNode == Head)
	{
		if (index == 1)
		{
			DeleteAtTail();
		}
		else
		{
			Head = Head->nextNode;
			Head->lastNode = Head;
			Head->nextNode = Head;
		}
	}

	else if (0 <= index && index <= Size)
	{
		std::shared_ptr<CircularlyDoublyLinkedNode<T>> temp = Head;
		int count = 0;
		while (count < index - 1)
		{
			temp = temp->nextNode;
			count++;
		}
		// at node in front of what is being deleted

		temp->nextNode = temp->nextNode->nextNode;
		temp->nextNode->lastNode = temp;
	}

	else { return; }

	Size--;
}

template <typename T>
void CircularlyDoublyLinkedList<T>::DeleteAtTail()
{
	//if there is nothing in the list
	if (IsEmpty())
	{
		return;
	}

	//if the head is the only node in the list
	else if (Head->nextNode == Head)
	{
		Clear();
	}

	//if there are two items in the list
	else if (Head->lastNode->lastNode == Head)
	{
		Head->lastNode = Head;
		Head->nextNode = Head;
	}

	//if there are three/more items in the list
	else  
	{
		Head->lastNode->lastNode->nextNode = Head;
		Head->lastNode->nextNode = nullptr;
		Head->lastNode = Head->lastNode->lastNode;

	}

	Size--;
}

template <typename T>
void CircularlyDoublyLinkedList<T>::DeleteValue(T value)
{
	if (Found(value))
	{
		std::shared_ptr<CircularlyDoublyLinkedNode<T>> temp = Head;
		while (temp->nextNode != Head && temp->Value != value)
		{
			temp = temp->nextNode;
		}
		//temp is the one to delete
		temp = temp->lastNode;
		//temp->nextNode is the one to delete

		temp->nextNode = temp->nextNode->nextNode;
		temp->nextNode->lastNode = temp;

		Size--;
	}
	else
	{
		return;
	}
}

template <typename T>
bool CircularlyDoublyLinkedList<T>::Found(T value)
{
	std::shared_ptr<CircularlyDoublyLinkedNode<T>> temp = Head;
	while (temp->nextNode != Head && temp->Value != value)
	{
		temp = temp->nextNode;
	}

	if (temp->Value == value)
	{
		std::cout << "true" << std::endl;
		return true;
	}
	if (temp->nextNode == Head)
	{
		std::cout << "false" << std::endl;
		return false;
	}
}

template <typename T>
void CircularlyDoublyLinkedList<T>::GetAllForward()
{
	CircularlyDoublyLinkedNode<T>* temp;
	temp = Head.get();
	while (temp != nullptr)
	{
		std::cout << temp->Value << " ";
		temp = temp->nextNode.get();
	}
	std::cout << " " << std::endl;
}

template <typename T>
bool CircularlyDoublyLinkedList<T>::IsEmpty()
{
	if (Head == nullptr)
	{
		return true;
	}
	else { return false; }
}

template <typename T>
CircularlyDoublyLinkedList<T>::~CircularlyDoublyLinkedList()
{
	Clear();
}
