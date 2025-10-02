//
// Created by algorithm on 10/1/25.
//

#include <iostream>
// #include <vector>

// typedef std::vector < std::pair < std::string, int > > pairlist_t;
// typedef std::string text_t;
// typedef int integer_i;

using str     = std::string;
using integer = int;

int main() {

    // typedef: reserved keyword used to create an additional name (alias) for another data type.
    //          New identifier for an existing type.
    //          Helps with readability and reduces typos.

    //          Use when there is a clear benefit
    //          Replaced with "using" (Work better with templates)

    // pairlist_t pairlist;

    str nama = "Hello Fellow Bro";
    int age  = 20;

    std::cout << nama << "\n"
              << age  << "\n";

    return 0;
}