#include <parser.hpp>
#include <iostream>

using namespace std;

program parse(vector<Token> tokens)
{
    string currentToken;
    TokenType currentTokenType;
    std::vector<Token> tempTokens1;
    std::vector<Token> tempTokens2;
    std::vector<std::string> order;
    Token tempToken;
    program currentProgram;
    string tempString;
    bool tempBool;
    cout << "This is a test." << endl;
    for(int i = 0; i < tokens.size(); i++)
    {
        currentToken = tokens[i].value;
        currentTokenType = tokens[i].type;
        switch(currentTokenType)
        {
            case TokenType::KEYWORD:
                if(currentToken.compare("import"))
                {
                    i++;
                    currentToken = tokens[i].value;
                    currentProgram.imports.emplace_back(currentToken.append(".ehd"));
                    order.push_back("Ki");
                }
                else if(currentToken.compare("var"))
                {
                    i++;
                    currentToken = tokens[i].value;
                    tempString = currentToken;
                    i++;
                    currentToken = tokens[i].value;
                    currentProgram.vars.emplace_back(tempString, currentToken);
                    order.push_back("Kv");
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
                        break;
                    }
                    i++;
                    currentToken = tokens[i].value;
                    tempString = currentToken;
                    i++;
                    currentToken = tokens[i].value;
                    currentProgram.consts.emplace_back(tempBool, tempString, currentToken);
                    order.push_back("Kc");
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
                            if(currentToken.compare("const"))
                            {
                                
                            }
                            else if()
                            {

                            }
                            else
                            {
                                tempTokens1.push_back(tokens[i]);
                            }
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
                    while(!currentToken.compare("return"))
                    {
                        i++;
                        currentToken = tokens[i].value;
                        tempTokens2.push_back(tokens[i]);
                    }
                    i++;
                    currentProgram.statics.emplace_back(tempString, tempTokens1, tempTokens2, tempBool, tokens[i]);
                    order.push_back("Ks");
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