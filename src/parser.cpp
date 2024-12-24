#include "headers/parser.hpp"
#include "headers/lexer.hpp"
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Expr {
public:
    class Binary {
    public:
        Binary(std::shared_ptr<Expr> left, std::shared_ptr<Token> operatorToken, std::shared_ptr<Expr> right)
            : left(left), operatorToken(operatorToken), right(right) {}

        std::shared_ptr<Expr> left;
        std::shared_ptr<Token> operatorToken;
        std::shared_ptr<Expr> right;
    };

    // Other expressions...
};
class parser
{
    private:
        vector<Token> tokens;
        int current = 0;
        Expr equality() {
            Expr expr = comparison();
        }
        Expr expression()
        {
            return equality();
        }
    parser(vector<Token> tokens)
    {
        this->tokens = tokens ;
    }
};