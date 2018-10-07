#include <memory>
#include <iostream>

#include "SinglyLinkedList.cpp"
#include "DoublyLinkedList.cpp"

int main()
{
	SinglyLinkedList<int> linkedList;
	DoublyLinkedList<int> dll;
	
	dll.Add(1);
	dll.Add(2);
	dll.Add(3);
	dll.Add(4);
	dll.GetAllForward();

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