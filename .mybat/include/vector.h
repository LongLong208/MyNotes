#ifndef VECTOR_H
#define VECTOR_H

#include <bits/stdc++.h>
#include "Graph.h"
using namespace std;

/* 
 * 打印 vector
 *
 * 例子：
 * vector<int> v;
 * cout << v;
 * 
 **/
template <typename T>
ostream &operator<<(ostream &out, vector<T> v);

/*
 * 输入一个 vector
 * 
 * 形如：
 * [1,2,3,4,5,6]
 * [abc,bca,cab]
 * 类型取决于定义的 vector 的模板
 * 
 * 例如：
 * vector<int> vector<string>
 * 
 * 例子：
 * vector<int> v;
 * cout >> v;
 * 
 **/
template <typename T>
istream &operator>>(istream &in, vector<T> &v);

/* 
 * 
 * 
 * 
 * 
 * 
 * 
 *      函数实现
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 **/

template <typename T>
ostream &operator<<(ostream &out, vector<T> v)
{
    out << ' ' << '[';
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
        if (a == '[')
        {
            int l = 0;
            stringstream ss("");
            while (a != ']' || l > 0)
            {
                if (a == ']')
                    --l;
                ss << a;
                in >> a;
                if (a == '[')
                    ++l;
            }
            ss << a;
            ss >> temp;
            vec.push_back(temp);
        }
        else if (a == ',')
        {
            continue;
        }
        else if (a == ']')
        {
            break;
        }
        else
        {
            stringstream ss("");
            while (a != ',' && a != ']')
            {
                ss << a;
                in >> a;
            }
            ss >> temp;
            vec.push_back(temp);
            if (a == ']')
                break;
        }
    }
    v = vec;
    return in;
}

istream &operator>>(istream &in, vector<string> &v)
{
    vector<string> vec;
    char a;
    while (in.get(a))
        if (a == '[')
            break;
    while (in.get(a))
    {
        if (a == '[')
        {
            int l = 0;
            string ss("");
            while (a != ']' || l > 0)
            {
                if (a == ']')
                    --l;
                ss += a;
                in.get(a);
                if (a == '[')
                    ++l;
            }
            ss += a;
            vec.push_back(ss);
        }
        else if (a == ',')
        {
            continue;
        }
        else if (a == ']')
        {
            break;
        }
        else
        {
            string ss("");
            while (a != ',' && a != ']')
            {
                ss += a;
                in.get(a);
            }
            vec.push_back(ss);
            if (a == ']')
                break;
        }
    }
    v = vec;
    return in;
}

/* 
ostream &begin_out(ostream &out, string cla = "code-output")
{
    out << ("<div class=" + cla + "> \n\n");
    return out;
}

ostream &end_out(ostream &out)
{
    out << "</div> \n\n";
    return out;
} */

#endif
