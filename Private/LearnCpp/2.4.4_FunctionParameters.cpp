//
// Created by algorithm on 10/4/25.
//

// Using return values as arguments

#include <iostream>

int get_value_from_user() {
    std::cout << "Enter an integer: ";
    int input; std::cin >> input;

    return input;
}

void print_double(int value) {
    std::cout << value << " doubled is: " << value * 2 << "\n";
}

int main() {
    print_double( get_value_from_user() );

    return 0;
}