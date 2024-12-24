#include "headers/lexer.hpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>

using namespace std;

class LexicalAnalyzer
{
    private:
        string input;
        size_t position;
        unordered_map<string, TokenType> keywords;
        unordered_map<string, TokenType> bitwise;
        unordered_map<string, TokenType> declarations;
        unordered_map<string, TokenType> token_types;
        unordered_map<string, TokenType> functions;
        unordered_map<string, TokenType> operators;
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
            bitwise["&&"] = TokenType::BITWISE_OPERATOR;
            bitwise["||"] = TokenType::BITWISE_OPERATOR;
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
        string getNextWord()
        {
            size_t start = position;
            while (position < input.length() && isAlphaNumeric(input[position]))
            {
                position++;
            }
            return input.substr(start, position - start);
        }
        string getNextNumber()
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
    string nextWord = getNextWord();
    LexicalAnalyzer(const string& source)
        : input(source)
        , position(0)
    {
        initKeywords();
    }
    string quote;
    vector<Token> tokenize()
    {
        vector<Token> tokens;
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
                string word = getNextWord();
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
                string number = getNextNumber();
                if (number.find('.') != string::npos)
                {
                    tokens.emplace_back(TokenType::FLOAT_LITERAL, number);
                }
                else {
                    tokens.emplace_back(TokenType::INTEGER_LITERAL, number);
                }
            }
            else if (bitwise.find(nextWord) != bitwise.end())
            {
                tokens.emplace_back(TokenType::BITWISE_OPERATOR, nextWord);
                position++;
            }
            else if (currentChar == '=')
            {
                tokens.emplace_back(TokenType::OPERATOR, string(1, currentChar));
                position++;
            }
            else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/' || currentChar == '<' || currentChar == '>' || currentChar == '!' || currentChar == '^')
            {
                tokens.emplace_back(TokenType::OPERATOR, string(1, currentChar));
                position++;
            }
            else if (currentChar == '(' || currentChar == ')' || currentChar == '{' || currentChar == '}' || currentChar == '\"' || currentChar == '\'' || currentChar == ';')
            {
                tokens.emplace_back(TokenType::PUNCTUATOR, string(1, currentChar));
                position++;
            }
            else
            {
                tokens.emplace_back(TokenType::UNKNOWN, string(1, currentChar));
                position++;
            }
        }

        return tokens;
    }
};

string getTokenTypeName(TokenType type)
{
    switch (type) {
    case TokenType::KEYWORD:
        return "KEYWORD";
    case TokenType::DECLARATION:
        return "DECLARATION";
    case TokenType::FUNCTIONAL:
        return "FUNCTIONAL";
    case TokenType::IDENTIFIER:
        return "IDENTIFIER";
    case TokenType::VAR_TYPE:
        return "VAR_TYPE";
    case TokenType::BITWISE_OPERATOR:
        return "BITWISE_OPERATOR";
    case TokenType::EQUALS_OPERATOR:
        return "EQUALS_OPERATOR";
    case TokenType::INTEGER_LITERAL:
        return "INTEGER_LITERAL";
    case TokenType::FLOAT_LITERAL:
        return "FLOAT_LITERAL";
    case TokenType::OPERATOR:
        return "OPERATOR";
    case TokenType::PUNCTUATOR:
        return "PUNCTUATOR";
    case TokenType::UNKNOWN:
        return "UNKNOWN";
    default:
        return "UNDEFINED";
    }
}

void printTokens(const vector<Token>& tokens)
{
    for (const auto& token : tokens)
    {
        cout << "Type: " << getTokenTypeName(token.type) << ", Value: " << token.value << endl;
    }
}

int lex(const string& filenameAndPath)
{
    string ex = ".ep";
    if (!strstr(filenameAndPath.c_str(), ex.c_str()))
    {
        cout << "Incorrect file extension!" << endl;
        EXIT_FAILURE;
    }
    ifstream file(filenameAndPath);
    string line;
    string sourceCode;
    while (getline(file, line))
    {
        sourceCode = sourceCode + line;
    }
    LexicalAnalyzer lexer(sourceCode);
    vector<Token> tokens = lexer.tokenize();
    printTokens(tokens);
    return 0;
}
