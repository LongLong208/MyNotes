#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <time.h>

using namespace std;

/* 
class Mode
{
public:
    void
};

class CppCodeForMD
{
    Mode *mode;

public:
}
;
 */

int main(int argc, char *argv[])
{
    ifstream ifile;
    vector<string> code;
    ifile.open(argv[1]);

    if (!ifile)
    {
        return 0;
    }
    for (string n; ifile >> n;)
    {
        code.push_back(n);
    }
    std::cout << '\n';
    return 0;
}
