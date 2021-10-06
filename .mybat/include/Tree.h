#ifndef TREE_H
#define TREE_H

#include <bits/stdc++.h>
#include "vector.h"
using namespace std;

template <class Type = int>
class TreeNode
{
public:
    Type val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : left(nullptr), right(nullptr) {}
    TreeNode(Type value) : val(value), left(nullptr), right(nullptr) {}
    TreeNode(Type value, TreeNode *l, TreeNode *r) : val(value), left(l), right(r) {}

    string toMermaid();
    //todo Graph<Type, direct, weight> toGraph();
};

template <class Type>
string TreeNode<Type>::toMermaid()
{
    queue<pair<char, TreeNode<Type> *>> q;
    stringstream res("");
    char id = 'a';
    res << "```mermaid \n";
    res << "graph TD; \n";
    res << id;
    res << "[ ";
    res << val;
    res << " ] \n";

    /* left */
    if (this->left)
        q.push(pair<char, TreeNode<Type> *>(id, this->left));

    /* !left, right*/
    if (!this->left && this->right)
        q.push(pair<char, TreeNode<Type> *>(id, nullptr));

    /* right*/
    if (this->right)
        q.push(pair<char, TreeNode<Type> *>(id, this->right));

    /* left, !right*/
    if (this->left && !this->right)
        q.push(pair<char, TreeNode<Type> *>(id, nullptr));

    ++id;

    while (!q.empty())
    {
        pair<char, TreeNode<Type> *> temp = q.front();
        q.pop();
        res << id << "[ ";
        if (temp.second)
            res << temp.second->val;
        res << " ] \n";
        res << temp.first << " --- " << id << "\n";

        /* left */
        if (temp.second && temp.second->left)
            q.push(pair<char, TreeNode<Type> *>(id, temp.second->left));

        /* !left, right*/
        if (temp.second && !temp.second->left && temp.second->right)
            q.push(pair<char, TreeNode<Type> *>(id, nullptr));

        /* right*/
        if (temp.second && temp.second->right)
            q.push(pair<char, TreeNode<Type> *>(id, temp.second->right));

        /* left, !right*/
        if (temp.second && temp.second->left && !temp.second->right)
            q.push(pair<char, TreeNode<Type> *>(id, nullptr));

        ++id;
    }

    res << "``` \n";
    return res.str();
}

template <class Type>
ostream &operator<<(ostream &out, TreeNode<Type> *root)
{
    vector<Type> v;
    queue<TreeNode<Type> *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        root = q.front();
        q.pop();
        v.push_back(root->val);
        if (root->left)
            q.push(root->left);
        if (root->right)
            q.push(root->right);
    }
    out << v;
    return out;
}

template <class Type>
istream &operator>>(istream &in, TreeNode<Type> *&root)
{
    vector<string> v;
    queue<TreeNode<Type> **> q;

    in >> v;

    q.push(&root);
    int i = 0;
    while (!q.empty())
    {
        TreeNode<Type> **cur = q.front();
        q.pop();
        if (i < v.size())
        {
            stringstream ss(v[i++]);
            if (ss.str() != "null")
            {
                Type temp;
                ss >> temp;
                *cur = new TreeNode<Type>(temp);
                q.push(&(*cur)->left);
                q.push(&(*cur)->right);
            }
        }
    }

    return in;
}

#endif
