//
// Created by algorithm on 10/4/25.
//

// Calling functions more than once

#include <iostream> // for std::cout

void doPrint()
{
    std::cout << "In doPrint()\n";
}

// Definition of function main()
int main()
{
    std::cout << "Starting main()\n";
    doPrint(); // doPrint() called for the first time
    doPrint(); // doPrint() called for the second time
    std::cout << "Ending main()\n";

    return 0;
}