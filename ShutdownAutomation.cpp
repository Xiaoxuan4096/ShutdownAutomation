#include <iostream>
#include <cstdlib>
int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "No argument supplied, canceling shutdown by default." << std::endl;
        system("shutdown -a");
    }
    if (argc == 2) {
        std::cout << argv[1] << std::endl;
        if (argv[1] == "-shutdown") {
            std::cout << "Received shutdown argument, proceeding shutdown." << std::endl;
            system("shutdown -s -t 60");
        }
        else {
            std::cout << "Not received shutdown argument, canceling shutdown by default." << std::endl;
            system("shutdown -a");
        }
    }
    if (argc > 2) {
        std::cout << "Too many arguments supplied, canceling shutdown by default." << std::endl;
        system("shutdown -a");
    }
    return 0;
}