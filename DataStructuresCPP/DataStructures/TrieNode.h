#pragma once

#include <memory>
#include <iostream>
#include <unordered_set>
#include <map>


class TrieNode
{
public:
	TrieNode(char c);
	TrieNode();
	std::unique_ptr<std::map<char, std::unique_ptr<TrieNode>>> children;
	char Letter;
	bool isWord;
};

TrieNode::TrieNode()
{
	children = {};
	Letter = {};
	isWord = false;
}

TrieNode::TrieNode(char c)
{
	children = std::make_unique<std::map<char, std::unique_ptr<TrieNode>>>();
	Letter = c;
	isWord = false;
}

