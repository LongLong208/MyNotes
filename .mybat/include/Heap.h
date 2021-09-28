#ifndef HEAP_H
#define HEAP_H

#include <bits/stdc++.h>
#include "vector.h"
using namespace std;

template <class Type, class Compare = std::less<Type>>
class Heap
{
protected:
    vector<Type> data;
    int end;
    Compare com;

    void adjust(int i)
    {
        if (i >= end)
            return;
        while (i > 0 && com(data[i], data[(i - 1) / 2]))
        {
            swap(data[i], data[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

public:
    Heap() : end(0) {}
    Heap(Compare compare) : end(0), com(compare) {}
    inline bool empty() { return end == 0; }
    inline int size() { return end; }
    void insert(Type x)
    {
        if (end < data.size())
            data[end] = x;
        else
            data.push_back(x);
        ++end;
        adjust(end - 1);
    }
    void push(Type x) { insert(x); }
    Type top()
    {
        return data[0];
    }
    void pop()
    {
        --end;
        swap(data[0], data[end]);
        int i = 0;
        while (i < end)
        {
            int left = i * 2 + 1;
            int right = i * 2 + 2;
            if (left < end && com(data[left], data[i]) || right < end && com(data[right], data[i]))
            {
                int min_d;
                if (right < end && com(data[right], data[left]))
                {
                    min_d = right;
                }
                else
                {
                    min_d = left;
                }
                swap(data[i], data[min_d]);
                i = min_d;
            }
            else
            {
                break;
            }
        }
    }
};

template <class Type, class Compare>
istream &operator>>(istream &in, Heap<Type, Compare> &heap)
{
    vector<Type> v;
    Heap<Type, Compare> h;
    in >> v;
    for (int i = 0; i < v.size(); ++i)
    {
        h.push(v[i]);
    }
    heap = h;
    return in;
}

template <class Type, class Compare>
ostream &operator<<(ostream &out, Heap<Type, Compare> heap)
{
    vector<Type> v;
    while (!heap.empty())
    {
        v.push_back(heap.top());
        heap.pop();
    }
    out << v;
    return out;
}

#endif
