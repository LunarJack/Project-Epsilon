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
                        cout << "HELP!?" << endl;
                        return 0;
                }
        }
        else if (argc == 4)
        {
                if (strcmp(argv[1], "-c") == 0)
                {
                        string f1, f2;
                        f1 = argv[2];
                        f2 = argv[3];
                        compile(argv[2], argv[3]);
                }
        }
        else
        {
                cout << "Welcome to Epsilon!\nEpsilon is a coding language based on C ++.\nTo see a list of commands type:\nepsilon -h.\nTo run compiled code type:\nepsilon -r " << endl;
                return 0;
        }
}
