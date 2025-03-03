#ifndef LEXER_HPP
#define LEXER_HPP
#include <unordered_map>
#include <string>
enum class TokenType
{
    Int,
    Float,
    Char,
    String,
    Type,
    Function,
    Keyword,
    Addition,
    Subtraction,
    Increment,
    Decrement,
    BoolTrue,
    BoolFalse,
    OpenParenthesis,
    CloseParenthesis,
    OpenCurlyBracket,
    CloseCurlyBracket,
    OpenSquareBracket,
    CloseSquareBracket,
    Equals,
    BoolEquals,
    GreaterThan,
    LessThan,
    Comma,
    Identifier,
    Semicolon,
    Undefined,
};
struct Token
{
    TokenType type;
    std::string value;
    Token(TokenType t, const std::string& v)
        :type(t)
        ,value(v)
        {
        }
};
class LexicalAnalyzer
{
    private:
        std::string input;
        std::size_t position;
        std::unordered_map<std::string, TokenType>keywords;
        void intiKeywords()
        {
            keywords["if"] = TokenType::Keyword;
            keywords["else"] = TokenType::Keyword;
            keywords["elif"] = TokenType::Keyword;
            keywords["for"] = TokenType::Keyword;
            keywords["while"] = TokenType::Keyword;
            keywords["return"] = TokenType::Keyword;
            keywords["from"] = TokenType::Keyword;
            keywords["import"] = TokenType::Keyword;
        }
        bool isWhitespace(char c)
        {
            return c == ' ' || c == '\t' || c == '\n' || c == '\r';
        }
        bool isAlpha(char c)
        {
            return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
        }
        bool isDigit(char c)
        {
            return c >= '0' && c <= '9';
        }
        bool isAlphaNumeric(char c)
        {
            return isAlpha(c) || isDigit(c);
        }
        std::string getNextWord()
        {
            size_t start = position;
            while (position < input.length()
                   && isAlphaNumeric(input[position])) {
                position++;
            }
            return input.substr(start, position - start);
        }
        std::string getNextNumber()
        {
            size_t start = position;
            bool hasDecimal = false;
            while(position < input.length() && (isDigit(input[position]) || input[position == '.']))
        }
};
#endif //LEXER_HPP