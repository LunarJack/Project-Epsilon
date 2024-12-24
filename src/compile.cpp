#include "headers/lexer.hpp"
#include "headers/parser.hpp"
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
	if (argc != 3) {
        cerr << "Wrong arguments!\nThe proper command is:\nepsilonc <source filename and path> <compiled filename and path>" << endl;
        return EXIT_FAILURE;
    }
        ifstream file(argv[1]);
        if (!file.is_open()) {
            cerr << "File not opened, " << argv[1] << " is not a valid file path\n" << endl;
        }
        else {
            file.close();
        }
        fstream file2(argv[2]);
        if (!file2.is_open()) {
            cerr << "File not opened, " << argv[2] << " is not a valid file path\n" << endl;
        }
        else {
            file2.close();
        }
    lex(argv[1]);
    return 0;
}
