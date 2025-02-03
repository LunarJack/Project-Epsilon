#include <iostream>
#include <string>
#include <cstring>
#include <compile.hpp>

using namespace std;

int main(int argc, char *argv[])
{
        if (argc == 2)
        {
                if (strcmp(argv[1], "-h") == 0)
                {
                        cout << "To compile code type\nepsilon -c <Input file> <Compiled code file> <Options>\nTo run compiled code type:\nepsilon -r <Compiled code file>" << endl;
                        return 0;
                }
        }
        else if (argc >= 4)
        {
                if (strcmp(argv[1], "-c") == 0)
                {
                        compile(argv[2], argv[3]);
                }
        }
        else
        {
                cout << "Welcome to Epsilon!\nEpsilon is a coding language based on C ++.\nTo see a list of commands type:\nepsilon -h" << endl;
                return 0;
        }
}
