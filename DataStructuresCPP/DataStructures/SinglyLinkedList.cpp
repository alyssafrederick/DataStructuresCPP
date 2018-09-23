#include "SinglyLinkedList.h"
#include <memory>


SinglyLinkedList::SinglyLinkedList()
{
	First = nullptr;
	Size = 0;
}

 void SinglyLinkedList:: Add(int value)
{
	//when linkedList is empty (first is null)
	if (First == nullptr)
	{
		First = std::make_unique<SinglyLinkedNode>(value);
	}

	//when there are already things in the linkedList
	else if (First != nullptr)
	{
		SinglyLinkedNode* temp;
		temp = First.get();

		while (temp->nextNode != nullptr)
		{
			temp = temp->nextNode.get();
		}

		temp->nextNode = std::make_unique<SinglyLinkedNode>(value);
	}
}

void Delete(int value)
{

}

void Clear()
{

}

bool Found(int value)
{
	return true;
}

SinglyLinkedList::~SinglyLinkedList()
{
}
