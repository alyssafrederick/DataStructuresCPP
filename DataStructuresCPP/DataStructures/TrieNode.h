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
	std::map<char, TrieNode> children;
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
	children = std::map<char, TrieNode>();
	Letter = c;
	isWord = false;
}

