#pragma once

#include <memory>
#include <iostream>
#include <vector>
#include <string>

class UnionFind
{
private:
	std::vector<int> Size;

public:
	UnionFind(int size);
	std::vector<int> data;
	bool Connected(int p, int q);
	//quick find
	int QuickFind(int p);
	void Union(int p, int q);
	//quick union
	int Find(int p);
	void QuickUnion(int p, int q);
	//weighted quick union
	void WeightedQuickUnion(int p, int q);
	//weighted quick union with path compression
	void WQuickUnionWPC(int p, int q);
};
//reminder that p&q are indexes


UnionFind::UnionFind(int size)
{
	data = std::vector<int>();
	Size = std::vector<int>();

	int i = 0;
	for (i = 0; i < size; i++)
	{
		data.push_back(i);
		Size.push_back(1);
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
int UnionFind::QuickFind(int p)
{
	return data[p];
}

void UnionFind::Union(int p, int q)
{
	if (Connected(p, q) == true)
	{
		return;
	}
	else
	{
		int i = 0;
		for (i = 0; i < data.size(); i++)
		{
			if (data[i] == p)
			{
				data[i] = data[q];
			}
		}

		data[p] = data[q];
	}
}

//QUICK UNION
int UnionFind::Find(int p)
{
	while (data[p] != p)
	{
		p = data[p];
	}
	return p;
}

void UnionFind::QuickUnion(int p, int q)
{
	data[Find(p)] = Find(q);
}

//WEIGHTED QUICK UNION
void UnionFind::WeightedQuickUnion(int p, int q)
{
	int rootp = Find(p);
	int rootq = Find(q);

	if (Size[rootp] < Size[rootq])
	{
		data[rootp] = rootq;
		Size[rootq] += Size[rootp];
	}
	else
	{
		data[rootq] = rootp;
		Size[rootp] += Size[rootq];
	}

}

//WEIGHTED QUICK UNION W PATH COMPRESSION
void UnionFind::WQuickUnionWPC(int p, int q)
{
	int rootp = Find(p);
	int rootq = Find(q);

	if (Size[])
}