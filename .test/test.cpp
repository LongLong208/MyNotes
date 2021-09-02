#include <bits/stdc++.h>
#include "..\\.mybat\\include\\header.h"
using namespace std;

string DepthFirstSearch(vector<string> V, vector<vector<int> > E)
{
    vector<bool> visit(V.size(), false);
    stack<int> S;
    stringstream res("");
    S.push(0);
    while (!S.empty())
    {
        int i = S.top();
        S.pop();
        if (visit[i])
            continue;
        res << V[i] << ' ';
        visit[i] = true;
        for (int j = 0; j < E[i].size(); ++j)
        {
            if (E[i][j])
            {
                S.push(j);
            }
        }
    }
    return res.str();
}

int main()
{
    // vector<string> V;
    // vector<vector<int> > E;

    // cin >> V >> E;
    // if (cin)
    //     cout << DepthFirstSearch(V, E);

    vector<vector<int> > a;
    cin >> a;
    cout << a;

    return 0;
}
