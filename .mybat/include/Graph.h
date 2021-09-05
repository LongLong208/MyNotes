#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>
#include "stream.h"
using namespace std;

template <class Type, bool direct = 0, bool weight = 0>
class Graph
{
public:
    vector<Type> vertex;
    vector<vector<double> > edge;
    Graph() {}
    Graph(vector<Type> v) : vertex(v) {}
    Graph(vector<vector<double> > e) : edge(e) {}
    Graph(vector<Type> v, vector<vector<double> > e) : vertex(v), edge(e) {}
    string toMermaid();
};

template <class Type, bool direct, bool weight>
string Graph<Type, direct, weight>::toMermaid()
{
    stringstream res;

    res << "```mermaid \n";
    res << "graph LR; \n";

    for (int i = 0; i < vertex.size(); ++i)
    {
        res << (char)(i + 'a') << "[ " << vertex[i] << " ] \n";
    }
    for (int i = 0; i < edge.size(); ++i)
    {
        int j = direct ? 0 : i + 1;
        for (; j < edge[i].size(); ++j)
        {
            if (edge[i][j] != 0)
            {
                res << (char)(i + 'a') << " ---";
                if (direct)
                    res << '>';
                if (weight)
                    res << "|" << edge[i][j] << "|";

                res << " " << (char)(j + 'a') << " \n";
            }
        }
    }
    res << "```\n";
    return res.str();
}

template <class Type, bool direct, bool weight>
istream &operator>>(istream &in, Graph<Type, direct, weight> &graph)
{
    vector<Type> v;
    vector<vector<double> > e;
    in >> v >> e;
    Graph<Type, direct, weight> temp(v, e);
    graph = temp;
    return in;
}

template <class Type, bool direct, bool weight>
ostream &operator<<(ostream &out, Graph<Type, direct, weight> graph)
{
    out << graph.toMermaid();
    return out;
}

#endif
