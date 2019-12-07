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
	std::unique_ptr<SinglyLinkedList<KeyValuePair>[]> buckets;
	int HashFunction(std::string Tkey);
	void Add(std::string Tkey, int Tvalue);
	void ReHash();
	void Remove(std::string Tkey, int Tvalue);
	void Display();
};

//template <typename T>
HashMap::HashMap()
{
	size = 17;

	buckets = std::make_unique<SinglyLinkedList<KeyValuePair>[]>(size);
}

//template <typename T>
int HashMap::HashFunction(std::string Tkey)
{
	//Horner's formulation: apply mod at each step in calculation to avoid overflow
	int hash = 1;

	for (int i = 0; i < Tkey.size(); i++)
	{
		hash = (hash * 3 + (int)Tkey.at(i)) % size;
	}

	//std::cout << hash << std::endl;
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
	int oldSize = size;
	int newSize = size * 2;
	size = newSize;

	auto newbuckets = std::make_unique<SinglyLinkedList<KeyValuePair>[]>(size);

	int i = 0;
	for (i = 0; i < oldSize; i++)
	{
		auto temp = buckets[i].First.get();
		if (temp != nullptr)
		{
			while (temp != nullptr)
			{
				// rehash and add to newbucket
				int newhash = HashFunction(temp->Value.TKey);
				newbuckets[newhash].Add(temp->Value);
				temp = temp->nextNode.get();
			}
		}
		return;
	}

	buckets = std::move(newbuckets);
}

//template <typename T>
void HashMap::Remove(std::string Tkey, int Tvalue)
{
	int hash = HashFunction(Tkey);
	auto temp = buckets[hash].First.get();

	while (temp != nullptr)
	{
		if (temp->Value.TValue == Tvalue)
		{
			buckets[hash].Delete(temp->Value);
			return;
		}

		temp = temp->nextNode.get();
	}
}

void HashMap::Display()
{
	//figure out a way to display tkey and bucket to see if rehash worked
	int i = 0;
	for (i = 0; i < size; i++)
	{
		auto temp = buckets[i].First.get();
		if (temp != nullptr)
		{
			while (temp != nullptr)
			{
				std::cout << i << " ," << temp->Value.TKey << ", " << temp->Value.TValue << std::endl;
				temp = temp->nextNode.get();
			}
		}
		else
		{
			std::cout << i << ", nothing" << std::endl;
		}
	}
}