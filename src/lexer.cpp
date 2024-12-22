#include "headers/lexer.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>
enum TokenType
{
    Number,
    Identifier,
    Equals,
    OpenParen,
    CloseParen,
    OpenCurlyBracket,
    CloseCurlyBracket,
    QuotationMark,
    BinaryOperator,
    Const,
    Var,
    Int,
    Str,
    Char,
    Float,
    Double,
    Long,
    Byte,
    Short,
    function,
    import,

};
struct Token
{
    std::string value;
    TokenType type;
};
typedef std::map<std::string, TokenType> ReservedIdentMap;
ReservedIdentMap reservedIdent;
void INIT_RESERVED_IDENTIFIER()
{
    reservedIdent["const"] = TokenType::Const;
    reservedIdent["var"] = TokenType::Var;
    reservedIdent["int"] = TokenType::Int;
    reservedIdent["str"] = TokenType::Str;
    reservedIdent["char"] = TokenType::Char;
    reservedIdent["float"] = TokenType::Float;
    reservedIdent["double"] = TokenType::Double;
    reservedIdent["long"] = TokenType::Long;
    reservedIdent["byte"] = TokenType::Byte;
    reservedIdent["short"] = TokenType::Short;
    reservedIdent["func "] = TokenType::Int;
}
std::string shift(std::vector<std::string> &src)
{
    std::string current = src.front();
    src.erase(src.begin());
    return current;
}
Token token(std::string value, TokenType tokentype)
{
    return {value, tokentype};
}
bool isNumber(const std::string &str)
{
    for (char ch : str)
    {
        if (!isdigit(ch))
            return false;
    }
    return true;
}
bool isAlpha(const std::string &str)
{
    for (char ch : str)
    {
        if (!isalpha(ch))
            return false;
    }
    return true;
}
bool isSkippable(char ch)
{
    return ch == ' ' || ch == '\t' || ch == '\n';
}
std::vector<std::string> splitString(const std::string &sourceCode) {
    std::vector<std::string> words;
    std::string word;

    for (char ch : sourceCode) {
        if (ch != ' ') {
            word += ch;
        } else if (!word.empty()) {
            words.push_back(word);
            word.clear();
        }
    }

    if (!word.empty()) {
        words.push_back(word);
    }

    return words;
}
std::vector<Token> tokenize(std::string &sourceCode) {
    std::vector<Token> tokens;
    std::vector<std::string> src = splitString(sourceCode);

    while (!src.empty()) {
    if (src.front() == "(") {
        tokens.push_back(token(shift(src), TokenType::OpenParen));
    }
    else if (src.front() == ")") {
        tokens.push_back(token(shift(src), TokenType::CloseParen));
    }
    else if (src.front() == "+" || src.front() == "-" || src.front() == "*" || src.front() == "/")
    {
        tokens.push_back(token(shift(src), TokenType::BinaryOperator));
    }
    else if (src.front() == "=")
    {
        tokens.push_back(token(shift(src), TokenType::Equals));
    }
    else if (src.front() == "{") {
        tokens.push_back(token(shift(src), TokenType::OpenCurlyBracket));
    }
    else if (src.front() == "}") {
        tokens.push_back(token(shift(src), TokenType::CloseCurlyBracket));
    }
    else if (src.front() == "\"") {
        tokens.push_back(token(shift(src), TokenType::QuotationMark));
    }
    else
    {
        if (isNumber(src.front())) {
            std::string number;
            while (!src.empty() && isNumber(src.front())) {
                number += shift(src);
        }
            tokens.push_back(token(number, TokenType::Number));
        }
        else if (isAlpha(src.front()))
            {
                std::string ident = shift(src);
                // check for reserved tokens like let etc
                ReservedIdentMap::iterator it = reservedIdent.find(ident);
                if (it != reservedIdent.end())
                {
                    tokens.push_back(token(ident, it->second));
                }
                else
                {
                    tokens.push_back(token(ident, TokenType::Identifier));
                }
            }
        else if (isSkippable(src.front()[0]))
        {
            shift(src);
        }
        else
        {
            std::cout << "Unrecognized character found! " << std::endl;
            exit(1);
        }
    }
    // Handle other token types
    // ...
}
    return tokens;
}

int lex(char *filepath) {
    char ext[] = ".ep";
    size_t xlen = strlen(ext);
    size_t slen = strlen(filepath);
    int found = strcmp(filepath + slen - xlen, ext) == 0;
    if (found == 0)
        {
            std::cerr << "Invalid code file" << std::endl;
            return EXIT_FAILURE;
        }
    INIT_RESERVED_IDENTIFIER();
    std::string sourceCode;
    {
        std::stringstream contents_stream;
        std::fstream input(filepath, std::ios::in);
        contents_stream << input.rdbuf();
        sourceCode = contents_stream.str();
    }

    std::vector<Token> tokens = tokenize(sourceCode);
    for (int i = 0; i < tokens.size(); ++i)
    {
        std::cout << "Value: " << tokens[i].value << "\n";
    }
    return true;
}
long long SHIFT_CURR = 0;
