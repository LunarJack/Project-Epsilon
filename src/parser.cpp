#include "headers/parser.hpp"
#include "headers/lexer.hpp"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Parser 
{
    private:
        string AST;
    public:
        int parse(vector<string> stringsAndIdentifiers)
        {
            cout << AST;
            return 0;
        }
};