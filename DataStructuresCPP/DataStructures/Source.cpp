#include <memory>
#include <iostream>

#include "SinglyLinkedList.cpp"

int main()
{
	
	SinglyLinkedList<int> linkedList;
	
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
	
	system("pause");
	return 0;
}