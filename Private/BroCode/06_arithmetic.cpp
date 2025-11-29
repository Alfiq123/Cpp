//
// Created by algorithm on 10/2/25.
//

#include <iostream>

int main() {
    // Arithmetic Operators: Return the result of a specific
    //                       arithmetic operation ( + -* / )

    // P.E.M.D.A.S

    int students = 20;
    int students_2 = 6 + 5 - 4 * 3 / 2;

    students += 1;
    students ++;  // Increment Operator

    students = students - 1;
    students -= 1;
    students --;  // Decrement Operator

    students = students * 2;
    students *= 2;

    students = students / 2;
    students /= 2;

    int remainder = students % 2;

    std::cout << students << "\n";
    std::cout << students_2 << "\n";
    std::cout << remainder << "\n";

    return 0;
}