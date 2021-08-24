#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
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
    a += "using namespace std; \n";

    while (ifile)
    {
        ifile.getline(temp, 100);
        if (string(temp) == "//define")
            continue;
        if (string(temp) == "//use")
            break;
        a += temp;
        a += '\n';
    }

    a += "int main(){ \n";
    while (ifile)
    {
        ifile.getline(temp, 100);
        a += '\t';
        a += temp;
        a += '\n';
    }
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
