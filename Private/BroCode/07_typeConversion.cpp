//
// Created by algorithm on 10/2/25.
//

#include <iostream>

int main() {

    // Type Conversion: Conversion a value of one data type to another
    //                  Implicit: Automatic
    //                  Explicit: Precede value with new data type (int)

    int    number  = 16.32;
    double decimal = 32.64;
    double convert = (int) 32.64;

    int    correct  = 8;
    int    question = 10;
    double score    = correct / (double) question * 100;

    std::cout << number     << "\n"
              << decimal    << "\n"
              << convert    << "\n"
              << (char) 101 << "\n";

    std::cout << score << "%";

    return 0;
}