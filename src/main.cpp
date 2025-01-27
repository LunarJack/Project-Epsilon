#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
        if (argc == 2) {
                if (strcmp(argv[1], "-h") == 0) {
                        cout << "HELP!?" << endl;
                        return 0;
                }
        } else {
                cout << "Welcome to Epsilon!\nEpsilon is a coding language based on C ++.\nTo see a list of commands type:\nepsilon -h." << endl;
                return 0;
        }
}
