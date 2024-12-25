#ifndef LEXER_HPP
#define LEXER_HPP
#include <string>
enum TokenType
{
    KEYWORD,
    IDENTIFIER,
    INTEGER_LITERAL,
    FLOAT_LITERAL,
    OPERATOR,
    PUNCTUATOR,
    UNKNOWN,
    DECLARATION,
    FUNCTIONAL,
    VAR_TYPE,
};


struct Token
{
    TokenType type;
    std::string value;
    Token(TokenType t, const std::string& v)
        : type(t)
        , value(v)
    {
    }
};
int lex(const std::string& filenameAndPath);

#endif // LEXER_HPP
