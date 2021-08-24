#include <bits/stdc++.h>
#include "..\\.mybat\\src\\cppalMethod.h"
using namespace std;

template <class... Args>
void plus(Args... args)
{
    cout << (++args, 0)...;
}

int main()
{
    plus(1, 2, 3, 4);
    return 0;
}
