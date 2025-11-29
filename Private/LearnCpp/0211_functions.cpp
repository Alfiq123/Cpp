//
// Created by algorithm on 10/4/25.
//

#include <iostream>  // for std::cout

// An example of a user-defined function

// Definition of user-defined function doPrint()
// doPrint() is the called function in this example
void doPrint()
{
    std::cout << "In doPrint()\n";
}

// Definition of user-defined function main()
int main()
{
    std::cout << "Starting main()\n";

    doPrint();                        // Interrupt main() by making a function call to doPrint().  main() is the caller.

    std::cout << "Ending main()\n";   // This statement is executed after doPrint() ends

    return 0;
}