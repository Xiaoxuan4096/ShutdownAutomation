// ShutdownAutomation - Simple shutdown program on Windows.
// Written by Xiaoxuan4096.

// This program is distributed under MIT License.
// See LICENSE.txt for details.

#include <iostream>
#include <string>

#include <cstdlib>

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "No argument provided, canceling shutdown by default." << std::endl;
        system("shutdown -a");
    }

    if (argc == 2) {
        if (std::string(argv[1])== "--shutdown") {
            std::cout << "Received shutdown argument, proceeding shutdown." << std::endl;
            system("shutdown -s -t 60");
        }
        else {
            std::cout << "Haven't receive shutdown argument, canceling shutdown by default." << std::endl;
            system("shutdown -a");
        }
    }

    if (argc > 2) {
        std::cout << "Too many arguments provided, canceling shutdown by default." << std::endl;
        system("shutdown -a");
    }
    return 0;
}