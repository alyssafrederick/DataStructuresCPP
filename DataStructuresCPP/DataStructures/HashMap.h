 #pragma once

#include <memory>
#include <iostream>
#include <vector>
#include <string>

#include "SinglyLinkedList.h"
#include "KeyValuePair.h"

//template <typename T>
class HashMap
{
private:


public:
	HashMap();
	int size;
	SinglyLinkedList<KeyValuePair> buckets[5];
	int HashFunction(std::string Tkey);
	void Add(std::string Tkey, int Tvalue);
	void ReHash();
	void Remove(std::string Tkey, int Tvalue);
};

//template <typename T>
HashMap::HashMap()
{
	size = 5;
}

//template <typename T>
int HashMap::HashFunction(std::string Tkey)
{
	int hash = 0;

	for (int i = 0; i < Tkey.size(); i++)
	{
		hash += 17 + (int)Tkey.at(i);
	}

	std::cout << hash << std::endl;
	hash = hash % size;
	return hash;
}

//template <typename T>
void HashMap::Add(std::string Tkey, int Tvalue)
{
	int hash = HashFunction(Tkey);
	std::cout << hash << std::endl;
	KeyValuePair temp(Tkey, Tvalue);
	buckets[hash].Add(temp);
}

//template <typename T>
void HashMap::ReHash()
{

}

//template <typename T>
void HashMap::Remove(std::string Tkey, int Tvalue)
{
	int hash = HashFunction(Tkey);

	auto temp = buckets[hash].First.get();

	while (temp->nextNode != nullptr)
	{

		if (temp->Value.TValue == Tvalue)
		{
			buckets[hash].Delete(temp->Value);
		}

		temp = temp->nextNode.get();
	}

	//singlyLinkedList has the errors so look at that -> its probably because it is trying to delete a KeyValuePair and there are == in my singlyLinkedList
	//aka my singlyLinkedList really isnt generic...
}