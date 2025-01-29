#include <iostream>
#include <string>
#include <cstring>
#include "include/compile.h"

using namespace std;

int main(int argc, char *argv[])
{
        if (argc == 2)
        {
                if (strcmp(argv[1], "-h") == 0)
                {
                        cout << "To compile code type\n" << argv[0] << "-c <Input file> <Compiled code file>\nTo run compiled code type:\n" << argv[0] << "-r <Compiled code file>" << endl;
                        return 0;
                }
        }
        else if (argc == 4)
        {
                if (strcmp(argv[1], "-c") == 0)
                {
                        compile(&argv[2], &argv[3]);
                }
        }
        else
        {
                cout << "Welcome to Epsilon!\nEpsilon is a coding language based on C ++.\nTo see a list of commands type:\n " << argv[0] << " -h" << endl;
                return 0;
        }
}
