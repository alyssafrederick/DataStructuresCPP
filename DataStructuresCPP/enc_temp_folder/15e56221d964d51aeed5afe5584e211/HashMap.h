 #pragma once

#include <memory>
#include <iostream>
#include <vector>
#include <string>

#include "SinglyLinkedList.h"
#include "KeyValuePair.h"

template <typename T>
class HashMap
{
private:

public:
	HashMap();
	SinglyLinkedList < KeyValuePair < T >> buckets[5] = {};
	int HashFunction(std::string Tkey);
	void Add(std::string Tkey, T Tvalue);
	void ReHash();
	void Remove();
};

template <typename T>
HashMap<T>::HashMap()
{

}

template <typename T>
int HashMap<T>::HashFunction(std::string Tkey)
{
	int hash = 0;

	for (size_t i = 0; i < Tkey.size(); i++)
	{
		hash += i + 97 + (int)Tkey.at(i);
	}

	std::cout << hash << std::endl;
	return hash%buckets->Size;
}

template <typename T>
void HashMap<T>::Add(std::string Tkey, T Tvalue)
{

}

template <typename T>
void HashMap<T>::ReHash()
{

}

template <typename T>
void HashMap<T>::Remove()
{

}