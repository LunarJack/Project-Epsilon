#include <parser.hpp>
#include <iostream>
#include <compile.hpp>
#include <preprocessor.hpp>
#include <fstream>

using namespace std;
int compile(char *file1NameAndPath, char *file2NameAndPath)
{
    ifstream file(file1NameAndPath);
    if (!file.is_open())
    {
        cerr << "File not opened, " << file1NameAndPath << " is not a valid file path\n" << endl;
        return EXIT_FAILURE;
    }
    file.close();
    fstream file2(file2NameAndPath);
    if (!file2.is_open())
    {
        cerr << "File not opened, " << file2NameAndPath << " is not a valid file path\n" << endl;
        return EXIT_FAILURE;
    }
    file2.close();
    vector<Token> tokens = lex(file1NameAndPath);
    parse(tokens);
    return 0;
}
