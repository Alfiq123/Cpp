//
// Created by algorithm on 10/4/25.
//

// Functions can call functions that call other functions

#include <iostream> // for std::cout

void doB() {
    std::cout << "In doB()\n";
}


void doA() {
    std::cout << "Starting doA()\n";

    doB();

    std::cout << "Ending doA()\n";
}

// Definition of function main()
int main() {
    std::cout << "Starting main()\n";

    doA();

    std::cout << "Ending main()\n";

    return 0;
}