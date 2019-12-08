#pragma once

#include <memory>
#include <iostream>
#include <vector>
#include <string>

class UnionFind
{
private:


public:
	UnionFind(int size);
	std::vector<int> data;
	int Find(int p);
	void Union(int p, int q);
	bool Connected(int p, int q);
	void QuickFind();
};
//reminder that p&q are indexes


UnionFind::UnionFind(int size)
{
	data = std::vector<int>();

	int i = 0;
	for (i = 0; i < size; i++)
	{
		data.push_back(i);
	}
}

bool UnionFind::Connected(int p, int q)
{
	if (data[p] == data[q])
	{
		return true;
	}
	return false;
}


//QUICK FIND 
int UnionFind::Find(int p)
{
	return data[p];
}

void UnionFind::Union(int p, int q)
{
	//q takes p
	if (Connected(p, q) == true)
	{
		return;
	}
	else
	{
		
		int i = 0;
		for (i = 0; i < data.size(); i++)
		{
			if (data[i] == q)
			{
				data[i] = data[p];
			}
		}
		
		data[q] = data[p];
	}

}

void UnionFind::QuickFind()
{

}