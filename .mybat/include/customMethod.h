#ifndef CUSTOMMETHOD_H
#define CUSTOMMETHOD_H

#include <bits/stdc++.h>
using namespace std;

/* 
 * ��ӡ vector
 *
 * ���ӣ�
 * vector<int> v;
 * cout << v;
 * 
 **/
template <typename T>
ostream &operator<<(ostream &out, vector<T> v);

/*
 * ����һ�� vector
 * 
 * ���磺
 * [1,2,3,4,5,6]
 * [abc,bca,cab]
 * ����ȡ���ڶ���� vector ��ģ��
 * 
 * ���磺
 * vector<int> vector<string>
 * 
 * ���ӣ�
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
 *      ����ʵ��
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

ostream &begin_out(ostream &out, string cla = "code-output")
{
    out << ("<div class=" + cla + "> \n\n");
    return out;
}

ostream &end_out(ostream &out)
{
    out << "</div> \n\n";
    return out;
}

#endif
