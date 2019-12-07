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
	bool operator==(const KeyValuePair& other);
	bool operator!=(const KeyValuePair& other);
};

//template <typename T>
KeyValuePair::KeyValuePair(std::string Tkey, int Tvalue)
{
	TKey = Tkey;
	TValue = Tvalue;
}

inline bool KeyValuePair::operator==(const KeyValuePair& other)
{
	return TKey == other.TKey && TValue == other.TValue;
}

inline bool KeyValuePair::operator!=(const KeyValuePair& other)
{
	return TKey != other.TKey || TValue != other.TValue;
}