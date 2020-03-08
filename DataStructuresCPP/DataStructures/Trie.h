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
	root = std::make_unique<TrieNode>('$');
}

void Trie::Clear()
{
	root = std::make_unique<TrieNode>('$');
}



void Trie::Insert(std::string word)
{
	auto kids = root->children;

	for (auto i = 0; i < word.length(); i++)
	{
		auto letter = word[i];
		std::unique_ptr<TrieNode> tempTrieNode = std::make_unique<TrieNode>();

		//if letter is in the children
		if (kids.find(letter) != kids.end())
		{
			tempTrieNode = std::make_unique<TrieNode>(kids[letter]);
		}

		else
		{
			tempTrieNode = std::make_unique<TrieNode>(letter);
			kids[i] = tempTrieNode;
		}

		if (i == word.length() - 1)
		{
			tempTrieNode->isWord = true;
		}

		kids = tempTrieNode->children;
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
	auto tempKids = root->children;
	std::unique_ptr<TrieNode> tempTrieNode = std::make_unique<TrieNode>();

	for (auto current : word)
	{
		if (tempKids.find(current) != tempKids.end)
		{

		}
	}

	return TrieNode();
}