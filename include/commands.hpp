#pragma once
#ifndef COMMANDS_HPP
#define COMMANDS_HPP
#include <lexer.hpp>

struct varCommand
{
    std::string type;
    std::string name;
    std::vector<Token> value;
};

struct constCommand
{
    bool hasVar;
    std::string type;
    std::string name;
    std::vector<Token> value;
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

struct program
{
    std::vector<varCommand> vars;
    std::vector<constCommand> consts;
    std::vector<funcCommand> funcs;
    std::vector<staticCommand> statics;
};
#endif //COMMANDS_HPP