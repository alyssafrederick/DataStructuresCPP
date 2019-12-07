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
	SinglyLinkedList<KeyValuePair> buckets[17];
	int HashFunction(std::string Tkey);
	void Add(std::string Tkey, int Tvalue);
	void ReHash();
	void Remove(std::string Tkey, int Tvalue);
};

//template <typename T>
HashMap::HashMap()
{
	size = 17;
}

//template <typename T>
int HashMap::HashFunction(std::string Tkey)
{
	//Horner's formulation: apply mod at each step in calculation to avoid overflow
	int hash = 1;

	for (int i = 0; i < Tkey.size(); i++)
	{
		hash = (hash * 3 + (int)Tkey.at(i))%size;
	}

	std::cout << hash << std::endl;
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

	//fix while 
}