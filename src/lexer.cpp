#include "headers/lexer.hpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <map>
using namespace std;
enum TokenType {
    KEYWORD,
    IDENTIFIER,
    INTEGER_LITERAL,
    FLOAT_LITERAL,
    OPERATOR,
    PUNCTUATOR,
    UNKNOWN
};
struct Token {
    TokenType type;
    string value;

    Token(TokenType t, const string& v)
        : type(t)
        , value(v)
    {
    }
};

class LexicalAnalyzer {
private:
    string input;
    size_t position;
    unordered_map<string, TokenType> keywords;

    void initKeywords()
    {
        keywords["var"] = TokenType::KEYWORD;
        keywords["const"] = TokenType::KEYWORD;
        keywords["int"] = TokenType::KEYWORD;
        keywords["float"] = TokenType::KEYWORD;
        keywords["double"] = TokenType::KEYWORD;
        keywords["char"] = TokenType::KEYWORD;
        keywords["string"] = TokenType::KEYWORD;
        keywords["long"] = TokenType::KEYWORD;
        keywords["short"] = TokenType::KEYWORD;
        keywords["byte"] = TokenType::KEYWORD;
        keywords["if"] = TokenType::KEYWORD;
        keywords["else"] = TokenType::KEYWORD;
        keywords["while"] = TokenType::KEYWORD;
        keywords["return"] = TokenType::KEYWORD;
        keywords["func"] = TokenType::KEYWORD;
        keywords["import"] = TokenType::KEYWORD;
    }

    bool isWhitespace(char c)
    {
        return c == ' ' || c == '\t' || c == '\n'
            || c == '\r';
    }

    bool isAlpha(char c)
    {
        return (c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z');
    }

    bool isDigit(char c) { return c >= '0' && c <= '9'; }

    bool isAlphaNumeric(char c)
    {
        return isAlpha(c) || isDigit(c);
    }

    string getNextWord()
    {
        size_t start = position;
        while (position < input.length()
            && isAlphaNumeric(input[position])) {
            position++;
        }
        return input.substr(start, position - start);
    }

    string getNextNumber()
    {
        size_t start = position;
        bool hasDecimal = false;
        while (position < input.length()
            && (isDigit(input[position])
                || input[position] == '.')) {
            if (input[position] == '.') {
                if (hasDecimal)
                    break;
                hasDecimal = true;
            }
            position++;
        }
        return input.substr(start, position - start);
    }

public:
    LexicalAnalyzer(const string& source)
        : input(source)
        , position(0)
    {
        initKeywords();
    }

    vector<Token> tokenize()
    {
        vector<Token> tokens;

        while (position < input.length()) {
            char currentChar = input[position];
            if (isWhitespace(currentChar)) {
                position++;
                continue;
            }
            if (isAlpha(currentChar)) {
                string word = getNextWord();
                if (keywords.find(word) != keywords.end()) {
                    tokens.emplace_back(TokenType::KEYWORD,
                                        word);
                }
                else {
                    tokens.emplace_back(
                        TokenType::IDENTIFIER, word);
                }
            }
            else if (isDigit(currentChar)) {
                string number = getNextNumber();
                if (number.find('.') != string::npos) {
                    tokens.emplace_back(
                        TokenType::FLOAT_LITERAL, number);
                }
                else {
                    tokens.emplace_back(
                        TokenType::INTEGER_LITERAL, number);
                }
            }
            else if (currentChar == '+'
                || currentChar == '-'
                || currentChar == '*'
                || currentChar == '/'
                || currentChar == '=') {
                tokens.emplace_back(TokenType::OPERATOR,
                                    string(1, currentChar));
                position++;
            }
            else if (currentChar == '('
                || currentChar == ')'
                || currentChar == '{'
                || currentChar == '}'
                || currentChar == '\"'
                || currentChar == '\''
                || currentChar == ';') {
                tokens.emplace_back(TokenType::PUNCTUATOR,
                string(1, currentChar));
                position++;
            }
            else {
                tokens.emplace_back(TokenType::UNKNOWN,
                                    string(1, currentChar));
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
    case TokenType::IDENTIFIER:
        return "IDENTIFIER";
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
    for (const auto& token : tokens) {
        cout << "Type: " << getTokenTypeName(token.type)
            << ", Value: " << token.value << endl;
    }
}

int lex(const string& filenameAndPath)
{
    string ex = ".ep";
    if (!strstr(filenameAndPath.c_str(), ex.c_str())) {
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
