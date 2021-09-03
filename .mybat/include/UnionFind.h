#ifndef UNIONFIND_H
#define UNIONFIND_H

#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
    vector<int> root;
    vector<int> rank;

    UnionFind(int size)
    {
        root.resize(size);
        rank.resize(size);
        for (int i = 0; i < root.size(); ++i)
        {
            root[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x)
    {
        if (x == root[x])
            return x;
        return root[x] = find(root[x]);
    }
    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            if (rank[rootX] > rank[rootY])
            {
                root[rootY] = rootX;
            }
            else if (rank[rootX] < rank[rootY])
            {
                root[rootX] = rootY;
            }
            else
            {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }
};

#endif
