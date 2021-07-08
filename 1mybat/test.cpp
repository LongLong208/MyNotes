#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include <vector>
using namespace std;

template <typename T>
ostream &operator<<(ostream &out, vector<T> v)
{
    out << "[";
    for (int i = 0; i < v.size(); ++i)
    {
        out << v[i];
        if (i < v.size() - 1)
            out << ',';
    }
    out << "]";
    return out;
}

//algorithm
vector<vector<int> > print(int num)
{
    vector<vector<int> > vec;
    vector<int> v;
    v.push_back(num);
    vector<int> v2;
    v2.push_back(num * 10);
    vec.push_back(v);
    vec.push_back(v2);
    return vec;
}

//entry
void solution(stringstream &input)
{
    int num = 0;
    input >> num;
    if (input)
        cout << print(num);
}

int main(int argc, char *argv[])
{

    string instr = "1\n2\n3\n4\n5";

    stringstream input(instr);
    vector<time_t> times;
    while (input)
    {
        time_t begin_t = clock();
        solution(input);
        time_t finish_t = clock();
        times.push_back(finish_t - begin_t);
    }
    time_t aver = 0;
    for (int i = 0; i < times.size(); ++i)
    {
        aver += times[i];
    }
    aver /= times.size();
    cout << endl
         << "average time: " << aver << " ms" << endl;
    return 0;
}
