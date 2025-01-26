#include "include/lexer.hpp"

using namespace std;

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
int lex(const char* filenameAndPath, vector<Token> &AST)
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
    AST = lexer.tokenize();
    printTokens(AST);
    return 0;
}
