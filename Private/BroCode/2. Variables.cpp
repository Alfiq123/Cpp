//
// Created by algorithm on 10/1/25.
//

#include <iostream>

int main() {
    // int x = 128;
    // int y = 64;
    // int xy = x + y;

    // std::cout << x << "\n";
    // std::cout << y << "\n";
    // std::cout << xy << "\n";

    // Integer
    int age  = 20;
    int year = 2020;
    int days = 5;

    // Double
    double price       = 10.99;
    double gpa         = 3.25;
    double temperature = 12.55;

    // Single Character
    char grade      = 'A';
    char initial    = 'B';
    char dollarSign = '$';

    // Boolean
    bool student    = true;
    bool notStudent = false;
    bool power      = true;
    bool noPower    = false;



    // String
    std::string name    = "Izuaf";
    std::string day     = "Sunday";
    std::string food    = "Burger";
    std::string address = "FK Street 205. ";

    std::cout << "Integer:" << "\n"
              << age        << "\n"
              << year       << "\n"
              << days       << "\n"
              << "\n";

    std::cout << "Double:"   << "\n"
              << price       << "\n"
              << gpa         << "\n"
              << temperature << "\n"
              << "\n";

    std::cout << "Single Character:" << "\n"
              << grade               << "\n"
              << initial             << "\n"
              << dollarSign          << "\n"
              << "\n";

    std::cout << "Boolean:" << "\n"
              << student    << "\n"
              << notStudent << "\n"
              << power      << "\n"
              << noPower    << "\n"
              << "\n";

    std::cout << "String:" << "\n"
              << name      << "\n"
              << day       << "\n"
              << food      << "\n"
              << address   << "\n"
              << "\n";

    std::cout << "Hello "                  << name    << "\n"
              << "You like "               << day     << "\n"
              << "Your favourite food is " << food    << "\n"
              << "Your address in "        << address << "\n";

    return 0;
}