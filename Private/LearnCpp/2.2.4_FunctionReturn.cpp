//
// Created by algorithm on 10/4/25.
//

// REUSING FUNCTIONS

#include <iostream>

int getValueFromUser()
{
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;

    return input;
}

int main()
{
    // int x{ getValueFromUser() }; // first call to getValueFromUser
    // int y{ getValueFromUser() }; // second call to getValueFromUser

    int x = getValueFromUser();
    int y = getValueFromUser();

    std::cout << x << " + " << y << " = " << x + y << '\n';

    return 0;
}