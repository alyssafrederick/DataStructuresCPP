#pragma once

#include <memory>
#include <iostream>
#include <string>

template <typename T>
class KeyValuePair
{
private:

public:
	KeyValuePair(std::string TKey, T TValue);
	std::string TKey;
	T TValue;
};

template <typename T>
KeyValuePair<T>::KeyValuePair(std::string Tkey, T Tvalue)
{
	TKey = Tkey;
	TValue = Tvalue;
}