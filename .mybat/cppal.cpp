#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <time.h>

using namespace std;

int main(int argc, char *argv[])
{
    ifstream ifile;
    ofstream ofile;
    char temp[100] = {0};
    ifile.open(argv[1]);
    if (!ifile)
        return 0;
    string a = "#include <bits/stdc++.h> \n";
    a += "#include \"D:/1Notes/.mybat/cppalMethod.h\"\n";
    a += "using namespace std; \n";

    while (ifile)
    {
        ifile.getline(temp, 100);
        if (string(temp) == "//algorithm")
            continue;
        if (string(temp) == "//entry")
            break;
        a += temp;
        a += '\n';
    }

    a += "void solution(stringstream &input){ \n";
    while (ifile)
    {
        ifile.getline(temp, 100);
        if (string(temp) == "//entry")
            continue;
        if (string(temp) == "//test")
            break;
        a += '\t';
        a += temp;
        a += '\n';
    }
    a += "}\n";

    a += "int main(){ \n";
    a += "\tstring instr =\"";
    while (ifile)
    {
        ifile.getline(temp, 100);
        if (string(temp) == "//entry")
            continue;
        if (string(temp) == "//test")
            break;
        a += temp;
        a += "\\n";
    }
    a += "\";";
    a += "\n\tif (instr == \"\")\n\treturn 0;";
    a += "\n\tstringstream input(instr);\n\tvector<time_t> times;\n\twhile (input){\n\t\ttime_t begin_t = clock();\n\t\tsolution(input);\n\t\ttime_t finish_t = clock();\n\t\ttimes.push_back(finish_t - begin_t);\n\t\tcout << endl;\n\t}\n\ttime_t aver = 0;\n\tfor (int i = 0; i < times.size(); ++i){\n\t\taver += times[i];}\n\taver /= times.size();\n\tcout <<\"-------------------\"<< endl<< \"average time: \" << aver << \" ms\" << endl;\n";
    a += "\treturn 0;\n}";
    ifile.close();
    system((string("del ") + argv[1]).c_str());
    ofile.open(string(argv[1]));
    if (!ofile)
        return 0;
    ofile << a << endl;
    ofile.close();
    system((string("cppmd.bat ") + argv[1]).c_str());
    return 0;
}
