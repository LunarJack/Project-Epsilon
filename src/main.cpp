#include <iostream>
#include <string>
#include <cstring>

int main(int argc, char *argv[]) {
        if (strcmp(argv[1], "-help") == 0) {
                std::cout << "HELP!?" << std::endl;
                return 0;
        } else {
                std::cout << "Welcome to Epsilon!\nEpsilon is a coding language based on C ++.\nTo see a list of commands type:\nepsilon -help." << std::endl;
                return 0;
        }
}
