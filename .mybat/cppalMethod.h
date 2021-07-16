#ifndef CPPALMETHOD_H
#define CPPALMETHOD_H

#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream &operator<<(ostream &out, vector<T> v)
{
    out << '[';
    for (int i = 0; i < v.size(); ++i)
    {
        out << v[i];
        if (i < v.size() - 1)
            out << ',';
    }
    out << ']';
    return out;
}

template <typename T>
istream &operator>>(istream &in, vector<T> &v)
{
    vector<T> vec;
    char a;
    T temp;
    while (in >> a)
        if (a == '[')
            break;
    while (in >> a)
    {
        stringstream ss;
        while (a != ',' && a != ']')
        {
            ss << a;
            in >> a;
        }
        ss >> temp;
        vec.push_back(temp);
        if (a == ']')
        {
            v = vec;
            break;
        }
    }
    return in;
}

#endif
