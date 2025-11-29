#include <iostream>
#include <string>

int main() {
    // pointers = variable that stores a memory address of another variable
    //                    sometimes it's easier to work with an address         

    // & address-of operator
    // * dereference operator

    std::string name = "Bro";
    int age = 20;
    std::string freePizza[5] = {"Pizza_1", "Pizza_2", "Pizza_3", "Pizza_4", "Pizza_5"};

    std::string *pName = &name;
    int *pAge = &age;
    std::string *pFreePizza = freePizza;

    std::cout << pName     << "\n";
    std::cout << pAge      << "\n";
    std::cout << freePizza << "\n";

    return 0;
}