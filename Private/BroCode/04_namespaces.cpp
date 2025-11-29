//
// Created by algorithm on 10/1/25.
//

#include <iostream>

namespace first {
    int xConf = 10;
    int yConf = 20;
}

namespace second {
    int xConf = 11;
    int yConf = 21;
}

int main() {
    // Namespaces: provides a solution for preventing name conflicts in large projects.
    //             Each entity needs a unique name.
    //             A namespace allows for identically named entities as long as the namespaces are different.

    std::cout << first::xConf  << "\n"
              << first::yConf  << "\n"
              << "\n"
              << second::xConf << "\n"
              << second::yConf << "\n";

    return 0;
}