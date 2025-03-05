#include <cstdlib>
#include <iostream>
#include <cstring>
#include <compile.hpp>
#include <run.hpp>
#include <flagHandler.hpp>

using namespace std;

int main(int argc, char *argv[])
{
        if (argc >= 2)
        {
                if (strcmp(argv[1], "-h") == 0)
                {
                        cout << "To compile code type\nepsilon -c <Input file> <Compiled code file> <Options>\nTo run compiled code type:\nepsilon -r <Compiled code file>" << endl;
                        return 0;
                }
                else if (strcmp(argv[1], "-c") == 0)
                {
                        if (argc < 4)
                        {
                                cout << "ERROR, Too few compiller args." << endl;
                                return EXIT_FAILURE;
                        }
                        else if (argc > 4)
                        {
                                handle(argc, argv);
                        }
                        else
                        {
                                compile(argv[2], argv[3]);
                        }
                }
                else if (strcmp(argv[1], "-r") == 0)
                {
                        if (argc < 3)
                        {
                                cout << "ERROR, File not specified" << endl;
                                return EXIT_FAILURE;
                        }
                        run(argv[2]);
                }
        }
        else
        {
                cout << "Welcome to Epsilon!\nEpsilon is a coding language based on C ++.\nTo see a list of commands type:\nepsilon -h" << endl;
                return 0;
        }
        return 0;
}
