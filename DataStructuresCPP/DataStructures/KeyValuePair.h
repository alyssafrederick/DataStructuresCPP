#pragma once

#include <memory>
#include <iostream>
#include <string>

//template <typename T>
class KeyValuePair
{
private:

public:
	KeyValuePair(std::string Tkey, int Tvalue);
	std::string TKey;
	int TValue;
};

//template <typename T>
KeyValuePair::KeyValuePair(std::string Tkey, int Tvalue)
{
	TKey = Tkey;
	TValue = Tvalue;
}