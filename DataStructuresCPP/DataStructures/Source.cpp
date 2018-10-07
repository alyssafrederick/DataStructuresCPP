#include <memory>
#include <iostream>

#include "SinglyLinkedList.cpp"
#include "DoublyLinkedList.cpp"

void Thingy();

int main()
{
	SinglyLinkedList<int> linkedList;
	DoublyLinkedList<int> dll;
	
	dll.AddAtEnd(1);
	dll.AddAtEnd(2);
	dll.AddAtEnd(3);
	dll.AddAtEnd(4);
	dll.AddAtStart(0);
	dll.GetAllForward();
	dll.DeleteValue(2);

	
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
	
	//*/
	
	system("pause");
	return 0;
}
void Thingy()
{
	SinglyLinkedList<int> linkedList;

	for (size_t i = 0; i < 10000; i++)
	{
		linkedList.Add(i);
	}

	
}