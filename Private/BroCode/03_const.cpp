//
// Created by algorithm on 10/1/25.
//

#include <iostream>

int main() {
    // Const: The const keyword specifies that a variable's value is constant.
    //        Tells the compiler to prevent anything from modifying it.
    //        (read-only)

    const double PI       = 3.14159;
    const int LIGHT_SPEED = 299792458;
    const int WIDTH       = 1920;
    const int HEIGHT      = 1080;

    std::cout << PI          << "\n"
              << LIGHT_SPEED << "\n"
              << WIDTH       << "\n"
              << HEIGHT      << "\n";

    return 0;
}