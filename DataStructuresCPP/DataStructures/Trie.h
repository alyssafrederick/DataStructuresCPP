#pragma once

#include <memory>
#include <iostream>
#include <string>

#include "TrieNode.h"

class Trie
{
public:
	Trie();
	~Trie();

	void Clear();
	void Insert(std::string word);
	bool Contains(std::string word);
	//std::unordered_set<std::string> GetAllMatchingPrefix(std::string prefix);
	bool Remove(std::string word);
	TrieNode* SearchNode(std::string word);

private:
	std::unique_ptr<TrieNode> root;
};



Trie::Trie()
{
	Clear();
}

Trie::~Trie()
{
	Clear();
}

void Trie::Clear()
{
	root = std::make_unique<TrieNode>('$');
}



void Trie::Insert(std::string word)
{
	auto kids = root->children.get();

	for (auto i = 0; i < word.length(); i++)
	{
		auto letter = word[i];
		auto itr = kids->find(letter);

		TrieNode* tempTrieNode = nullptr;

		//if letter is in the children already, 
		if (itr != kids->end())
		{
			tempTrieNode = itr->second.get();
		}

		//if letter is not already there, add it to the root's children
		else
		{
			kids->insert({ letter, std::make_unique<TrieNode>(letter) });
			tempTrieNode = kids->find(letter)->second.get();
		}

		if (i == word.length() - 1)
		{
			tempTrieNode->isWord = true;
		}

		kids = kids->find(letter)->second->children.get();
	}
}

bool Trie::Contains(std::string word)
{
	
	return false;
}

//std::unordered_set<std::string> Trie::GetAllMatchingPrefix(std::string prefix)
//{
//	return std::unordegit red_set<"hi">;
//}

bool Trie::Remove(std::string word)
{
	if (SearchNode(word) != nullptr)
	{
		return false;
	}
	else
	{

	}
}

TrieNode* Trie::SearchNode(std::string word)
{
	auto tempKids = root->children.get();
	TrieNode* tempTrieNode = nullptr;
	int letterCount = 0;

	for (auto current : word)
	{
		//if the letter is in the trie
		if (tempKids->find(current) != tempKids->end())
		{
			if (letterCount == word.length() - 1)
			{
				tempTrieNode = tempKids->find(current)->second.get();
			}
		}

		else
		{
			return tempTrieNode;
		}

		tempKids = tempKids->find(current)->second->children.get();

		letterCount++;
	}
	
	return tempTrieNode;
}