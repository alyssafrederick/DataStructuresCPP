#include <memory>
#include <iostream>

#include "SinglyLinkedList.cpp"
#include "DoublyLinkedList.cpp"
#include "CircularlyDoublyLinkedList.cpp"

void Thingy();

int main()
{
	SinglyLinkedList<int> linkedList;
	DoublyLinkedList<int> dll;
	CircularlyDoublyLinkedList<int> cdll;


	cdll.AddAtHead(8);
	cdll.AddAtHead(4);
	cdll.AddAtTail(10);
	// 4 8 10
	cdll.AddAt(6, 1);
	// 4 6 8 10
	cdll.DeleteAtTail();

	/*
	dll.AddAtEnd(1);
	dll.AddAtEnd(2);
	dll.AddAtEnd(3);
	dll.AddAtEnd(4);
	dll.AddAtStart(0);
	dll.GetAllForward();
	dll.DeleteValue(2);
	dll.GetAllForward();
	dll.AddAt(7, 2);
	dll.GetAllForward();
	dll.DeleteAtEnd();
	dll.GetAllForward();
	dll.DeleteAtStart();
	dll.GetAllForward();
	dll.DeleteAt(1);
	dll.GetAllForward();
	*/
	
	//Thingy();

	/*
	linkedList.Add(1);
	linkedList.Add(2);
	linkedList.Add(3);
	linkedList.Add(4);
	linkedList.Add(5);
	linkedList.Add(6);
	linkedList.GetAll();
	linkedList.Found(6); //true
	linkedList.Found(66); //false
	linkedList.Delete(6);
	linkedList.GetAll();
	*/
	
 	system("pause");
	return 0;
}
void Thingy()
{
	DoublyLinkedList<int> linkedList;

	for (size_t i = 0; i < 10000; i++)
	{
		linkedList.AddAtEnd(i);
	}
	

	
}