#include <iostream>
#include <cstring>

int main()
{
    // int var = 8;
    // int *ptr = &var;

    // *ptr = 10;

    // std::cout << var;
    // std::cin.get();

    char *buffer = new char[8];
    memset(buffer, 0, 8);

    char **ptr = &buffer;

    delete[] buffer;
    std::cout << buffer;
}
