#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

string headerFilePath("");

class Mode
{
protected:
    vector<string> code;

    void front(string &str)
    {
        str += "#include <bits/stdc++.h> \n";
        if (headerFilePath != "")
            str += "#include \"" + headerFilePath + "\" \n";
        str += "using namespace std; \n";
    }

    void main1(string &str)
    {
        str += "int main() \n";
        str += "{ \n";
    }
    void main2(string &str)
    {
        str += "\treturn 0; \n";
        str += "} \n";
        str += "\n";
    }

public:
    Mode(const vector<string> &input) : code(input) {}
    virtual string getCode() = 0;
};

class ClassMode : public Mode
{
public:
    ClassMode(const vector<string> &input) : Mode(input) {}
    virtual string getCode()
    {
        string res("");
        front(res);
        int i = 0;
        while (i < code.size() && code[i] != "//use")
        {
            res += code[i] + "\n";
            ++i;
        }
        main1(res);
        while (i < code.size())
        {
            res += "\t" + code[i] + "\n";
            ++i;
        }
        main2(res);
        return res;
    }
};

class AGMode : public Mode
{
public:
    AGMode(const vector<string> &input) : Mode(input) {}
    virtual string getCode()
    {
        //todo implement
        string res("");
        front(res);
        int i = 0;
        while (i < code.size() && code[i] != "//entry")
        {
            res += code[i] + "\n";
            ++i;
        }
        res += "#define end_out \"</div>\" \n";
        res += "void algorthmTestEntry(istream &input, ostream &output, string &info) \n";
        res += "{ \n";
        while (i < code.size() && code[i] != "//test")
        {
            res += "\t" + code[i] + "\n";
            ++i;
        }
        ++i;
        res += "} \n";
        res += "\n";
        main1(res);
        res += "\tstring instr = \"";
        while (i < code.size())
        {
            res += code[i] + "\\n";
            ++i;
        }
        res += "\";";
        res += "\n\tif (instr == \"\")\n\t\treturn 0;";
        res += "\n\tstringstream input(instr);\n\tvector<time_t> times;\n\tstring info(\"\");\n\twhile (input){\n\t\ttime_t begin_t = clock();\n\t\talgorthmTestEntry(input, cout, info);\n\t\ttime_t finish_t = clock();\n\t\ttimes.push_back(finish_t - begin_t);\n\t\tcout << endl;\n\t}\n\ttime_t aver = 0;\n\tfor (int i = 0; i < times.size(); ++i){\n\t\taver += times[i];}\n\taver /= times.size();\n\tcout <<\"<hr class=code-hr>\"<< \"average time: \" << aver << \" ms\" << endl << info;\n";
        main2(res);
        return res;
    }
};

class ALLMode : public Mode
{
public:
    ALLMode(const vector<string> &input) : Mode(input) {}
    virtual string getCode()
    {
        string res("");
        for (int i = 0; i < code.size(); ++i)
        {
            res += code[i] + "\n";
        }
        return res;
    }
};

class SLMode : public Mode
{
public:
    SLMode(const vector<string> &input) : Mode(input) {}
    virtual string getCode()
    {
        string res("");
        front(res);
        main1(res);
        for (int i = 0; i < code.size(); ++i)
        {
            res += "\t";
            res += code[i];
            res += "\n";
        }
        main2(res);
        return res;
    }
};

class CodeRunner
{
    Mode *mode;
    bool ok;
    char *file;

    void runBat()
    {
        system((string("cppmd.bat ") + file).c_str());
    }

public:
    CodeRunner(char *filename) : file(filename)
    {
        mode = nullptr;
        ok = true;
        ifstream includeFile;
        char *pathvar;
        pathvar = getenv("MDCPP");
        string headerPath(string(pathvar) + "/include/header.h");
        includeFile.open(headerPath);
        if (includeFile)
        {
            headerFilePath = headerPath;
        }
        includeFile.close();

        ifstream ifile;
        ifile.open(filename);
        if (!ifile)
        {
            ok = false;
            ifile.close();
            return;
        }

        vector<string> code;
        char temp[255] = {0};
        while (ifile)
        {
            ifile.getline(temp, 255);
            code.push_back(temp);
        }
        ifile.close();
        system((string("del ") + filename).c_str());

        ofstream ofile;
        ofile.open(filename);

        if (!ofile)
        {
            ok = false;
            ofile.close();
            return;
        }

        if (code[0] == "//class" || code[0] == "//CLASS")
        {
            mode = new ClassMode(code);
        }
        else if (code[0] == "//sf" || code[0] == "//SF")
        {
            mode = new AGMode(code);
        }
        else if (code[0] == "//all" || code[0] == "//ALL")
        {
            mode = new ALLMode(code);
        }
        else
        {
            mode = new SLMode(code);
        }

        string newcode = mode->getCode();
        ofile << newcode << endl;
        ofile.close();
    }

    inline explicit operator bool() { return ok; }

    inline bool operator!() { return !ok; }

    virtual void run()
    {
        if (ok)
            runBat();
    }
};

int main(int argc, char *argv[])
{
    CodeRunner cr(argv[1]);
    if (!cr)
    {
        cout << "File did not opened!" << endl;
        return 0;
    }
    cr.run();
    return 0;
}
