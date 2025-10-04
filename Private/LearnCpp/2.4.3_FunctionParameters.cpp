//
// Created by algorithm on 10/4/25.
//

// Fixing our challenge program

#include <iostream>

int get_value_from_user()
{
    std::cout << "Enter an integer: ";
    int input{};
    std::cin >> input;

    return input;
}

void print_double(int value) // This function now has an integer parameter
{
    std::cout << value << " doubled is: " << value * 2 << '\n';
}

int main()
{
    int num { get_value_from_user() };

    print_double(num);

    return 0;
}