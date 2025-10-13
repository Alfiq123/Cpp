//
// Created by algorithm on 10/13/25.
//

/* A procedural vs OOP-like example */

#include <iostream>
#include <string_view>

struct Cat {
    std::string_view name{ "Cat" };
    int numLegs{ 4 };
};

struct Chicken {
    std::string_view name{ "Chicken" };
    int numLegs{ 2 };
};

struct Dog {
    std::string_view name{ "Dog" };
    int numLegs{ 4 };
};

struct Snake {
    std::string_view name{ "Snake" };
    int numLegs{ 0 };
};

int main() {
    constexpr Snake animal;
    std::cout << "a " << animal.name << " has " << animal.numLegs << " legs\n";

    return 0;
}