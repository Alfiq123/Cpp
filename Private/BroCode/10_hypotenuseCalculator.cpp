//
// Created by algorithm on 10/2/25.
//

#include <iostream>
#include <cmath>

int main() {

    double a;
    double b;

    std::cout << "Enter One Leg (A): ";       std::cin  >> a;
    std::cout << "Enter The Other Leg (B): "; std::cin  >> b;

    double c = sqrt(pow(a, 2) + pow(b, 2));

    std::cout << c;

    return 0;
}
