#include <lexer.hpp>
#include <sstream>
#include <iostream>
#include <fstream>

std::string getTokenTypeName(TokenType type)
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

void printTokens(const std::vector<Token>& tokens)
{
    for (const auto& token : tokens)
    {
        std::cout << "Type: " << getTokenTypeName(token.type) << ", Value: " << token.value << std::endl;
    }
}

std::vector<Token> lex(char *file)
{
    std::ifstream originalFile(file);
    std::stringstream buffer;
    buffer << originalFile.rdbuf();
    std::string sourceCode = buffer.str();
    LexicalAnalyzer lexer(sourceCode);
    std::vector<Token> tokens = lexer.tokenize();
    std::cout << "Source code: " << sourceCode << std::endl << std::endl;
    std::cout << "Tokens Generate by Lexical Analyzer:" << std::endl;
    printTokens(tokens);
    return tokens;
}
