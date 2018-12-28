#include <memory>
#include <iostream>

#include "SinglyLinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularlyDoublyLinkedList.h"
#include "Stack.h"

void Thingy();

int main()
{
	SinglyLinkedList<int> linkedList;
	DoublyLinkedList<int> dll;
	CircularlyDoublyLinkedList<int> cdll;
	Stack<int> stk;


	// 4. stack
	stk.Push(3);


	// 3. circularly doubly linked list
	/*
	cdll.AddAtHead(8);    // 8
	cdll.AddAtHead(4);    // 4 8
	cdll.AddAtTail(10);   // 4 8 10
	cdll.AddAt(6, 1);     // 4 6 8 10
	cdll.DeleteAtTail();  // 4 6 8
	cdll.DeleteAt(2);     // 4 6
	cdll.DeleteAt(0);     // 6
	cdll.AddAtTail(7);
	cdll.AddAtTail(8);
	cdll.AddAtTail(9);
	cdll.AddAtTail(10);   // 6 7 8 9 10
	cdll.DeleteValue(8);  // 6 7 9 10
	*/

	// 2. doubly linked list
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

	// 1. singly linked list
	/*
	linkedList.Add(1);
	linkedList.Add(2);
	linkedList.Add(3);
	linkedList.Add(4);
	linkedList.Add(5);
	linkedList.Add(6);
	linkedList.GetAll();
	linkedList.Found(6);  //true
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