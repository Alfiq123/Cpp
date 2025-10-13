//
// Created by algorithm on 10/13/25.
//

/* A procedural vs OOP-like example */

#include <iostream>
#include <string_view>

enum AnimalType {
    cat, dog, chicken, snake
};

constexpr std::string_view animalName(AnimalType type) {
    switch (type) {
        case cat: return "Cat";
        case dog: return "Dog";
        case chicken: return "Chicken";
        case snake: return "Snake";

        default: return "";
    }
}

constexpr int numLegs(AnimalType type) {
    switch (type) {
        case cat: return 4;
        case dog: return 4;
        case chicken: return 2;
        case snake: return 0;

        default:  return 0;
    }
}

int main() {
    constexpr AnimalType animal{ snake };
    std::cout << "A " << animalName(animal) << " has " << numLegs(animal) << " legs" << "\n";

    return 0;
}