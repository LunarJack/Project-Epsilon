#include <flagHandler.hpp>
#include <compile.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int handle(int argc, char *argv[])
{
    cout << "hi\n";
    vector<string> flags;
    size_t flagsI = 0;
    for (size_t argvI = 4; strcmp(argv[argvI], "") == 0; argvI++)
    {
        flags.push_back(argv[argvI]);
        flagsI++;
        cout << flags[flagsI] << endl;
    }
    return 0;
}