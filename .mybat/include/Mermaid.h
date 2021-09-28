#ifndef MERMAID_H
#define MERMAID_H

#include "header.h"

class Mermaid
{
    Mermaid();

protected:
    static const string charmap;
    static size_t id;
    static string nextName();

public:
    template <class Type, bool direct, bool weight, class CostType>
    static string print(Graph<Type, direct, weight, CostType>);

    template <class Type>
    static string print(vector<Type>);
};

const string Mermaid::charmap = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
size_t Mermaid::id = 0;

string Mermaid::nextName()
{
    string res("");
    size_t cur_id = id++;
    size_t mapsize = charmap.size();
    do
    {
        res += charmap[cur_id % mapsize];
        cur_id /= mapsize;
    } while (cur_id);
    return res;
}

template <class Type, bool direct, bool weight, class CostType>
string Mermaid::print(Graph<Type, direct, weight, CostType> graph)
{
    stringstream res;
    res << "```mermaid \n";
    res << "graph LR; \n";

    vector<string> name(graph.vSize());

    for (int i = 0; i < name.size(); ++i)
        name[i] = nextName();

    for (int i = 0; i < graph.vertex.size(); ++i)
    {
        res << name[i] << "[ " << graph.vertex[i] << " ] \n";
    }
    for (int i = 0; i < graph.edge.size(); ++i)
    {
        int j = direct ? 0 : i + 1;
        for (; j < graph.edge[i].size(); ++j)
        {
            if (graph.edge[i][j] != graph.maximum && i != j)
            {
                res << name[i] << " ---";
                if (direct)
                    res << '>';
                if (weight)
                    res << "|" << graph.edge[i][j] << "|";

                res << " " << name[j] << " \n";
            }
        }
    }
    res << "```\n";
    return res.str();
}

template <class Type>
string Mermaid::print(vector<Type> v)
{
    Graph<Type> graph(v);
    return print(graph);
}

#endif
