//
// Created by algorithm on 10/2/25.
//

#include <iostream>

int main() {
    // cin  << (Insertion Operator)
    // cout >> (Extraction Operator)

    std::string name;
    int age;

    std::cout << "What's your name?: ";
    // std::cin >> name;                            // Ignore text after spaces
    std::getline(std::cin >> std::ws, name);  // Allow Spaces

    std::cout << "What's your age?: ";
    std::cin >> age;

    std::cout << "Hello " << name << "\n";
    std::cout << "You are " << age << " years old";

    return 0;
}