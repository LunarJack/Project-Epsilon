#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <unordered_map>
#include <vector>

enum class TokenType {
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
    std::string value;
};

class LexicalAnalyzer {
private:
    std::string input;
    size_t position;
    std::unordered_map<std::string, TokenType> keywords;

    void initKeywords()
    {
        keywords["var"] = TokenType::KEYWORD;
        keywords["if"] = TokenType::KEYWORD;
        keywords["else"] = TokenType::KEYWORD;
        keywords["elif"] = TokenType::KEYWORD;
        keywords["while"] = TokenType::KEYWORD;
        keywords["for"] = TokenType::KEYWORD;
        keywords["return"] = TokenType::KEYWORD;
        keywords["import"] = TokenType::KEYWORD;
        keywords["objectify"] = TokenType::KEYWORD;
        keywords["const"] = TokenType::KEYWORD;
        keywords["func"] = TokenType::KEYWORD;
        keywords["true"] = TokenType::KEYWORD;
        keywords["false"] = TokenType::KEYWORD;
        keywords["NULL"] = TokenType::KEYWORD;
        keywords["typedef"] = TokenType::KEYWORD;
        keywords["static"] = TokenType::KEYWORD;
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
    LexicalAnalyzer(const std::string& source): input(source), position(0)
    {
        initKeywords();
    }

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
                if (keywords.find(word) != keywords.end())
                {
                    tokens.emplace_back(TokenType::KEYWORD, word);
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
                else
                {
                    tokens.emplace_back(TokenType::INTEGER_LITERAL, number);
                }
            }
            
            else if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/' || currentChar == '^' || currentChar == '|' || currentChar == '=' || currentChar == '!' || currentChar == '&')
            {
                tokens.emplace_back(TokenType::OPERATOR, std::string(1, currentChar));
                position++;
            }
            
            else if (currentChar == '(' || currentChar == ')' || currentChar == '{' || currentChar == '}' || currentChar == '[' || currentChar == ']' || currentChar == ';' || currentChar == ':' || currentChar == '\'' || currentChar == '\"' || currentChar == ',' || currentChar == '.') 
            {
                tokens.emplace_back(TokenType::PUNCTUATOR, std::string(1, currentChar));
                position++;
            }
            
            else {
                tokens.emplace_back(TokenType::UNKNOWN, std::string(1, currentChar));
                position++;
            }
        }

        return tokens;
    }
};

std::string getTokenTypeName(TokenType type);

void printTokens(const std::vector<Token>& tokens);

std::vector<Token> lex(char *file);
#endif //LEXER_HPP
