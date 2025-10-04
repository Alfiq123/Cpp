//
// Created by algorithm on 10/4/25.
//

#include <iostream>

// Function asks user to enter a value
// Return value is the integer entered by the user from the keyboard
int getValueFromUser() // this function now returns an integer value
{
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;

    return input; // return the value the user entered back to the caller
}

int main()
{
    int num { getValueFromUser() }; // initialize num with the return value of getValueFromUser()

    std::cout << num << " doubled is: " << num * 2 << '\n';

    return 0;
}