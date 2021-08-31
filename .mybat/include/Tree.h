#ifndef TREE_H
#define TREE_H

#include <bits/stdc++.h>
#include "customMethod.h"
using namespace std;

template <class Type>
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
};

template <class Type>
string TreeNode<Type>::toMermaid()
{
    queue<pair<char, TreeNode<Type> *> > q;
    stringstream res("");
    char id = 'a';
    res << "```mermaid \n";
    res << "graph TD; \n";
    res << id << "[" << this->val << "] \n";

    if (this->left)
        q.push(pair<char, TreeNode<Type> *>(id, this->left));
    if (this->right)
        q.push(pair<char, TreeNode<Type> *>(id, this->right));
    ++id;

    while (!q.empty())
    {
        pair<char, TreeNode<Type> *> temp = q.front();
        q.pop();
        res << id << "[" << temp.second->val << "] \n";
        res << temp.first << " --- " << id << "\n";
        if (temp.second->left)
            q.push(pair<char, TreeNode<Type> *>(id, temp.second->left));
        if (temp.second->right)
            q.push(pair<char, TreeNode<Type> *>(id, temp.second->right));
        ++id;
    }

    res << "``` \n";
    return res.str();
}

template <class Type>
ostream &operator<<(ostream &out, TreeNode<Type> *root)
{
    return out;
}

template <class Type>
istream &operator>>(istream &in, TreeNode<Type> *&root)
{
    vector<string> v;
    queue<TreeNode<Type> *> q;

    in >> v;
    q.push(root);
    int i = 0;
    while (!q.empty())
    {
        TreeNode<Type> *cur = q.front();
        q.pop();

        /* 建左子树 */
        if (i < v.size())
        {
            stringstream ss(v[i++]);
            if (ss.str() != "null")
            {
                Type temp;
                ss >> temp;
                cur->left = new TreeNode<Type>(temp);
                q.push(cur->left);
            }
        }

        /* 建右子树 */
        if (i < v.size())
        {
            stringstream ss(v[i++]);
            if (ss.str() != "null")
            {
                Type temp;
                ss >> temp;
                cur->right = new TreeNode<Type>(temp);
                q.push(cur->right);
            }
        }
    }

    return in;
}

#endif
