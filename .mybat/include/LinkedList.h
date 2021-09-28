#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <bits/stdc++.h>
#include "vector.h"
using namespace std;

template <class Type>
class ListNode
{
public:
    Type val;
    ListNode *next;

    ListNode() : next(nullptr) {}
    ListNode(Type value) : val(value), next(nullptr) {}
    ListNode(Type value, ListNode *n) : val(value), next(n) {}
};

template <class Type>
istream &operator>>(istream &in, ListNode<Type> *&head)
{
    vector<Type> v;
    in >> v;
    if (in)
    {
        ListNode<Type> *cur = head = new ListNode<Type>();
        for (int i = 0; i < v.size(); ++i)
        {
            cur->val = v[i];
            if (i < v.size() - 1)
            {
                cur->next = new ListNode<Type>();
                cur = cur->next;
            }
        }
    }
    return in;
}

template <class Type>
ostream &operator<<(ostream &out, ListNode<Type> *head)
{
    vector<Type> v;
    while (head)
    {
        v.push_back(head->val);
        head = head->next;
    }
    out << v;
    return out;
}

#endif
