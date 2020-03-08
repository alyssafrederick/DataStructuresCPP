#pragma once

#include <memory>
#include <iostream>
#include <string>

#include "TrieNode.h"

class Trie
{
public:
	Trie();

	void Clear();
	void Insert(std::string word);
	bool Contains(std::string word);
	//std::unordered_set<std::string> GetAllMatchingPrefix(std::string prefix);
	bool Remove(std::string prefix);

private:
	TrieNode SearchNode(std::string word);
	std::unique_ptr<TrieNode> root;
};



Trie::Trie()
{
	root = TrieNode('$');
}

void Trie::Clear()
{
	root = TrieNode('$');
}



void Trie::Insert(std::string word)
{
	auto kids = root.children;

	for (auto i = 0; i < word.length(); i++)
	{
		auto letter = word[i];
		TrieNode tempTrieNode;

		//if letter is in the children
		if (kids.find(letter) != kids.end())
		{
			tempTrieNode = kids[letter];
		}

		else
		{
			tempTrieNode = TrieNode(letter);
			kids.insert(std::pair<char, TrieNode> (letter, tempTrieNode));
		}

		if (i == word.length() - 1)
		{
			tempTrieNode.isWord = true;
		}

		kids = tempTrieNode.children;
	}
}

bool Trie::Contains(std::string word)
{

	return false;
}

//std::unordered_set<std::string> Trie::GetAllMatchingPrefix(std::string prefix)
//{
//	return std::unordered_set<"hi">;
//}

bool Trie::Remove(std::string prefix)
{

	return false;
}

TrieNode Trie::SearchNode(std::string word)
{
	return TrieNode();
}