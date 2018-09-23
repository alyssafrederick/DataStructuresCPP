#include <memory>
#include <iostream>

#include "SinglyLinkedList.h"

int main()
{
	SinglyLinkedList linkedList;
	linkedList.Add(8);

	std::cout << linkedList.First->Value << std::endl;

	system("pause");
	return 0;
}