#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char *argv[]) {
        if (strcmp(argv[1], "-help") == 0) {
                cout << "HELP!?" << endl;
                return 0;
        } else {
                cout << "Welcome to Epsilon!\nEpsilon is a coding language based on C ++.\nTo see a list of commands type:\nepsilon -help." << endl;
                return 0;
        }
}
