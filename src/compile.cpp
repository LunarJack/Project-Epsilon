#include <lexer.hpp>
#include <parser.hpp>
#include <compile.hpp>

using namespace std;
int compile(char *file1NameAndPath, char *file2NameAndPath)
{
    vector<Token> AST;
    ifstream file(file1NameAndPath);
    if (!file.is_open())
    {
        cerr << "File not opened, " << file1NameAndPath << " is not a valid file path\n" << endl;
        return EXIT_FAILURE;
    }
    else
    {
        file.close();
    }
    fstream file2(file2NameAndPath);
    if (!file2.is_open())
    {
        cerr << "File not opened, " << file2NameAndPath << " is not a valid file path\n" << endl;
        return EXIT_FAILURE;
    }
    else 
    {
        file2.close();
    }
    lex(file1NameAndPath, AST);
    return 0;
}
