#ifndef LEXER_H
#define LEXER_H
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
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
class LexicalAnalyzer
{
    private:
        std::string input;
        size_t position;
        std::unordered_map<std::string, TokenType> keywords;
        std::unordered_map<std::string, TokenType> declarations;
        std::unordered_map<std::string, TokenType> token_types;
        std::unordered_map<std::string, TokenType> functions;
        std::unordered_map<std::string, TokenType> operators;
        void initKeywords()
        {
            declarations["var"] = TokenType::DECLARATION;
            declarations["const"] = TokenType::DECLARATION;
            token_types["int"] = TokenType::VAR_TYPE;
            token_types["float"] = TokenType::VAR_TYPE;
            token_types["double"] = TokenType::VAR_TYPE;
            token_types["char"] = TokenType::VAR_TYPE;
            token_types["string"] = TokenType::VAR_TYPE;
            token_types["long"] = TokenType::VAR_TYPE;
            token_types["short"] = TokenType::VAR_TYPE;
            token_types["byte"] = TokenType::VAR_TYPE;
            functions["if"] = TokenType::FUNCTIONAL;
            functions["else"] = TokenType::FUNCTIONAL;
            functions["while"] = TokenType::FUNCTIONAL;
            functions["return"] = TokenType::FUNCTIONAL;
            declarations["func"] = TokenType::DECLARATION;
            functions["import"] = TokenType::FUNCTIONAL;
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
            while (position < input.length() && isAlphaNumeric(input[position]))
            {
                position++;
            }
            return input.substr(start, position - start);
        }
        std::string getNextNumber()
        {
            size_t start = position;
            bool hasDecimal = false;
            while (position < input.length() && (isDigit(input[position]) || input[position] == '.'))
            {
                if (input[position] == '.')
                {
                    if (hasDecimal)
                        break;
                    hasDecimal = true;
                }
                position++;
            }
            return input.substr(start, position - start);
        }
    public:
    std::string nextWord = getNextWord();
    LexicalAnalyzer(const std::string& source)
        : input(source)
        , position(0)
    {
        initKeywords();
    }
    std::string quote;
    std::vector<Token> tokenize()
    {
        std::vector<Token> tokens;
        while (position < input.length())
        {
            char currentChar = input[position];
            if (isWhitespace(currentChar))
            {
                position++;
                continue;
            }
            if (isAlpha(currentChar))
            {
                std::string word = getNextWord();
                if (declarations.find(word) != declarations.end())
                {
                    tokens.emplace_back(TokenType::DECLARATION, word);
                }
                else if (token_types.find(word) != token_types.end())
                {
                    tokens.emplace_back(TokenType::VAR_TYPE, word);
                }
                else if (functions.find(word) != functions.end())
                {
                    tokens.emplace_back(TokenType::FUNCTIONAL, word);
                }
                else
                {
                    tokens.emplace_back(TokenType::IDENTIFIER, word);
                }
            }
            else if (isDigit(currentChar))
            {
                std::string number = getNextNumber();
                if (number.find('.') != std::string::npos)
                {
                    tokens.emplace_back(TokenType::FLOAT_LITERAL, number);
                }
                else {
                    tokens.emplace_back(TokenType::INTEGER_LITERAL, number);
                }
            }
            else if (currentChar == '=')
            {
                tokens.emplace_back(TokenType::OPERATOR, std::string(1, currentChar));
                position++;
            }
            else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/' || currentChar == '<' || currentChar == '>' || currentChar == '!' || currentChar == '^')
            {
                tokens.emplace_back(TokenType::OPERATOR, std::string(1, currentChar));
                position++;
            }
            else if (currentChar == '(' || currentChar == ')' || currentChar == '{' || currentChar == '}' || currentChar == '\"' || currentChar == '\'' || currentChar == ';' || currentChar == ',' || currentChar == '.' || currentChar == '&')
            {
                tokens.emplace_back(TokenType::PUNCTUATOR, std::string(1, currentChar));
                position++;
            }
            else
            {
                tokens.emplace_back(TokenType::UNKNOWN, std::string(1, currentChar));
                position++;
            }
        }

        return tokens;
    }
};
int lex(const std::string& filenameAndPath, std::vector<Token>& AST);

#endif // LEXER_H
