#include <parser.hpp>
#include <iostream>

using namespace std;

program parse(vector<Token> tokens)
{
    string currentToken;
    TokenType currentTokenType;
    vector<Token> tempTokens1;
    vector<Token> tempTokens2;
    vector<string> order;
    Token tempToken;
    program currentProgram;
    string tempString;
    string tempString2;
    bool tempBool;
    cout << "This is a test." << endl;
    for(int i = 0; i < tokens.size(); i++)
    {
        currentToken = tokens[i].value;
        currentTokenType = tokens[i].type;
        switch(currentTokenType)
        {
            case TokenType::KEYWORD:
                if(currentToken.compare("var"))
                {
                    i++;
                    currentToken = tokens[i].value;
                    tempString = currentToken;
                    i++;
                    tempString2 = tokens[i].value;
                    i++;
                    currentToken = tokens[i].value;
                    if(currentToken.compare(";"))
                    {
                    }
                    else if(currentToken.compare("="))
                    {
                        while(!currentToken.compare(";"))
                        {
                            i++;
                            tempTokens1.push_back(tokens[i]);
                        }
                    }
                    else
                    {
                        tempTokens1.clear();
                        break; //Error
                    }
                    currentProgram.vars.emplace_back(tempString, currentToken, tempTokens1);
                    order.push_back("Kv");
                    tempTokens1.clear();
                }
                else if(currentToken.compare("const"))
                {
                    i++;
                    currentToken = tokens[i].value;
                    if(currentToken.compare("var"))
                    {
                        tempBool = true;
                    }
                    else
                    {
                        tempBool = false;
                        break; //Error
                    }
                    i++;
                    tempString =  tokens[i].value;
                    i++;
                    currentToken = tokens[i].value;
                    i++;
                    currentToken = tokens[i].value;
                    if(currentToken.compare(";"))
                    {
                        tempTokens1.clear();
                        break; //Error
                    }
                    else if(currentToken.compare("="))
                    {
                        while(!currentToken.compare(";"))
                        {
                            i++;
                            tempTokens1.push_back(tokens[i]);
                        }
                    }
                    else
                    {
                        tempTokens1.clear();
                        break; //Error
                    }
                    currentProgram.consts.emplace_back(tempBool, tempString, currentToken, tempTokens1);
                    order.push_back("Kc");
                    tempTokens1.clear();
                }
                else if(currentToken.compare("func"))
                {
                    i++;
                    currentToken = tokens[i].value;
                    tempString = currentToken;
                    i++;
                    i++;
                    currentToken = tokens[i].value;
                    tempTokens1.push_back(tokens[i]);
                    while(!currentToken.compare(")"))
                    {
                        i++;
                        currentToken = tokens[i].value;
                        if(!currentToken.compare(","))
                        {
                            tempTokens1.push_back(tokens[i]);
                        }
                    }
                    i++;
                    currentToken = tokens[i].value;
                    if(currentToken.compare(";"))
                    {
                        tempBool = true;
                        break;
                    }
                    else
                    {
                        tempBool = false;
                    }
                    i++;
                    currentToken = tokens[i].value;
                    tempTokens2.push_back(tokens[i]);
                    while(!currentToken.compare("return"))
                    {
                        i++;
                        currentToken = tokens[i].value;
                        tempTokens2.push_back(tokens[i]);
                    }
                    i++;
                    currentProgram.funcs.emplace_back(tempString, tempTokens1, tempTokens2, tempBool, tokens[i]);
                    order.push_back("Kf");
                    tempTokens1.clear();
                    tempTokens2.clear();
                }
                else if(currentToken.compare("static"))
                {
                    i++;
                    i++;
                    currentToken = tokens[i].value;
                    tempString = currentToken;
                    i++;
                    i++;
                    currentToken = tokens[i].value;
                    tempTokens1.push_back(tokens[i]);
                    while(!currentToken.compare(")"))
                    {
                        i++;
                        if(!currentToken.compare(","))
                        {
                            currentToken = tokens[i].value;
                            tempTokens1.push_back(tokens[i]);
                        }
                    }
                    i++;
                    currentToken = tokens[i].value;
                    if(currentToken.compare(";"))
                    {
                        tempBool = true;
                        break;
                    }
                    else
                    {
                        tempBool = false;
                    }
                    i++;
                    currentToken = tokens[i].value;
                    tempTokens2.push_back(tokens[i]);
                    while(!currentToken.compare("end"))
                    {
                        i++;
                        currentToken = tokens[i].value;
                        tempTokens2.push_back(tokens[i]);
                    }
                    i++;
                    currentProgram.statics.emplace_back(tempString, tempTokens1, tempTokens2, tempBool, tokens[i]);
                    order.push_back("Ks");
                    tempTokens1.clear();
                    tempTokens2.clear();
                }
            case TokenType::IDENTIFIER:
                
            case TokenType::INTEGER_LITERAL:
                
            case TokenType::FLOAT_LITERAL:
                
            case TokenType::OPERATOR:
                
            case TokenType::PUNCTUATOR:

            case TokenType::UNKNOWN:
        }
    }
    return currentProgram;
}