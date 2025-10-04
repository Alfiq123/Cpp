//
// Created by algorithm on 10/4/25.
//

// Function parameters and arguments

#include <iostream>

// This function takes no parameters
// It does not rely on the caller for anything
void doPrint() {
    std::cout << "In doPrint()\n";
}

// This function takes one integer parameter named x
// The caller will supply the value of x
void printValue(int x) {
    std::cout << x << '\n';
}

// This function has two integer parameters, one named x, and one named y
// The caller will supply the value of both x and y
int add(int x, int y) {
    return x + y;
}

int get_value_from_user() {
    std::cout << "Enter an integer: ";
    int input;
    std::cin >> input;
    return input;
}

int main() {
    int num = get_value_from_user();

    doPrint();       // this call has no arguments
    printValue(6); // 6 is the argument passed to function printValue()
    add(2, 3);   // 2 and 3 are the arguments passed to function add()

    std::cout << num << " double is: " << num * 2 << "\n";

    return 0;
}