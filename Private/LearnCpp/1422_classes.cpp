//
// Created by algorithm on 10/13/25.
//

/* Introduction to classes */

#include <iostream>

class Employee {
    int m_id {};
    int m_age {};
    double m_wage {};
};

class Date {          // we changed struct to class
    public:           // and added this line, which is called an access specifier
        int m_day{};  // and added "m_" prefixes to each of the member names
        int m_month{};
        int m_year{};
};

void printDate(const Date& date) {
    std::cout << date.m_day << "/" << date.m_month << "/" << date.m_year << "\n";
}

int main() {
    Date date{ 4, 10, 2021 }; printDate(date);
    Date date_2{ 20, 10, 2025 }; printDate(date_2);
    Date date_3{ 24, 12, 1950 }; printDate(date_3);

    return 0;
}