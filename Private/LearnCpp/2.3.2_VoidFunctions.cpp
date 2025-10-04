//
// Created by algorithm on 10/4/25.
//

// VOID FUNCTIONS DON’T NEED A RETURN STATEMENT

#include <iostream>

// void means the function does not return a value to the caller
void printHi()
{
    std::cout << "Hi" << '\n';

    // return; // tell compiler to return to the caller -- this is redundant since the return will happen at the end of the function anyway!
} // function will return to caller here

int main()
{
    printHi();

    return 0;
}