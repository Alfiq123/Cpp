//
// Created by algorithm on 10/13/25.
//

/* Introduction to classes */

#include <iostream>

struct Date {
    int day{};
    int month{};
    int year{};
};

void printDate(const Date& date) {
    std::cout << date.day << "/" << date.month << "/" << date.year << "\n";  // assume DMY format
}

int main() {
    Date date{ 4, 10, 2021 };  // initialize using aggregate initialization
    printDate(date);                         // can pass entire struct to function

    Date date_2{ 20, 10, 2003}; printDate(date_2);
    Date date_3{ 15, 6, 2025}; printDate(date_3);

    return 0;
}