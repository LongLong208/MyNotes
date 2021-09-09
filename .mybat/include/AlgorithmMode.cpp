#ifndef AlgorithmMode
#define AlgorithmMode

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(string &instr, ostream &out, function<void(istream &, ostream &)> algorthmTestEntry, bool &modify_source)
{
    stringstream input(instr);
    vector<time_t> times;
    stringstream output("");
    while (input)
    {
        time_t begin_t = clock();
        algorthmTestEntry(input, output);
        time_t finish_t = clock();
        times.push_back(finish_t - begin_t);
        output << endl;
    }
    time_t aver = 0;
    for (int i = 0; i < times.size(); ++i)
    {
        aver += times[i];
    }
    aver /= times.size();
    output << "<hr class=code-hr> average time: " << aver << " ms" << endl;
    if (modify_source)
        out << "<div class=code-output> \n\n"
            << output.str() << "\n\n</div> \n\n";
    else
        out << output.str();
}
#endif
