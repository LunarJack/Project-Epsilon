#ifndef PARSER_HPP
#define PARSER_HPP
#include <lexer.hpp>

struct importCommand
{
    std::string file;
};

struct varCommand
{
    std::string type;
    std::string name;
};

struct constCommand
{
    bool hasVar;
    std::string type;
    std::string name;
};

struct funcCommand
{
    std::string name;
    std::vector<Token> args;
    std::vector<Token> contents;
    bool isPrototype;
    Token returnValue;
};

struct staticCommand
{
    std::string name;
    std::vector<Token> args;
    std::vector<Token> contents;
    bool isPrototype;
    Token returnValue;
};

struct ifCommand
{
    std::vector<Token> conditions;
    std::vector<Token> actions;
    
    bool hasElse;
};

struct program
{
    std::vector<importCommand> imports;
    std::vector<varCommand> vars;
    std::vector<constCommand> consts;
    std::vector<funcCommand> funcs;
    std::vector<staticCommand> statics;
};


class Parser 
{
    public:
};
program parse(std::vector<Token> tokens);
#endif // PARSER_HPP
