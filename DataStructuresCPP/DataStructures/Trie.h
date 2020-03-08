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
	std::unordered_set<std::string> GetAllMatchingPrefix(std::string prefix);
	bool Remove(std::string prefix);

private:
	TrieNode SearchNode(std::string word);
	TrieNode root;
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
	auto children = root.children;

	for (auto i = 0; i < word.length(); i++)
	{
		auto letter = word[i];
		TrieNode tempTrieNode;

		//if letter is in the children
		if (children.find(letter) != children.end())
		{
			tempTrieNode = children[letter];
		}
		else
		{
			tempTrieNode = TrieNode(letter);
			children.insert(std::pair<char, TrieNode> (letter, tempTrieNode));
		}

		children = tempTrieNode.children;


	}
}

bool Trie::Contains(std::string word)
{

}

std::unordered_set<std::string> Trie::GetAllMatchingPrefix(std::string prefix)
{

}

bool Trie::Remove(std::string prefix)
{

}

TrieNode Trie::SearchNode(std::string word)
{

}