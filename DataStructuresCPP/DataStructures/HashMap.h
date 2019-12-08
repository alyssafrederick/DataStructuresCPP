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
	int size;  //size of buckets
	int count; //how many keyValue pairs there are 
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
	size = 7;
	count = 0;
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

	std::cout << "hash of " << Tkey << " = " << hash << std::endl;
	return hash;
}

//template <typename T>
void HashMap::Add(std::string Tkey, int Tvalue)
{
	int hash = HashFunction(Tkey);
	//std::cout << hash << std::endl;
	KeyValuePair temp(Tkey, Tvalue);
	buckets[hash].Add(temp);

	count++;

	if (count >= size * 0.5)
	{
		ReHash();
	}
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

	count--;
}

void HashMap::Display()
{
	//a way to display tkey and bucket to see if rehash worked
	//since it is hard to see into buckets bc it is now a unique pointer, display will output the tKey and bucket number so we can see it

	std::cout << "" << std::endl;
	std::cout << "buckets for size " << size << std::endl;

	int i = 0;
	for (i = 0; i < size; i++)
	{
		auto temp = buckets[i].First.get();
		if (temp != nullptr)
		{
			while (temp != nullptr)
			{
				std::cout << i << ", " << temp->Value.TKey << ", " << temp->Value.TValue << std::endl;
				temp = temp->nextNode.get();
			}
		}
		else
		{
			std::cout << i << ", nothing" << std::endl;
		}
	}

	std::cout << "" << std::endl;
}