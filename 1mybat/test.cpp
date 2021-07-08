#include <iostream>
#include <string>
#include <sstream>
#include <time.h>
#include <vector>
using namespace std;

//algorithm
int print(int num)
{
    for (int i = 0; i < 10000; ++i)
    {
        for (int j = 0; j < 10000; ++j)
        {
        }
    }
    return num;
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
