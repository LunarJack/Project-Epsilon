#include <flagHandler.hpp>
#include <compile.hpp>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
void handle(int argc, char *argv[])
{
    printf("Hi\n");
    vector<string> flags;
    int flagsI = 0;
    for (int argvI = 4; strcmp(argv[argvI], "") == 0; argvI++)
    {
        flags.push_back(argv[argvI]);
        flagsI++;
        cout << flags[flagsI] << "\n";
    }
    printf("Hi\n");
}