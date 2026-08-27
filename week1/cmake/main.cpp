// driver code that contains the main() function to demonstrate the class Example

#include <iostream>
// include the Example.hpp header
#include "Example.hpp"

// we do not include the Example.cpp file
// it gets compiled and then linked instead

int main() {
    Example ex(4);
    std::cout << "ex.getValue() = " << ex.getValue() << std::endl;

    return 0;
}

// to compile:
/*

# compiles the Example.cpp file
g++ -c Example.cpp -o Example.o
# compiles the main.cpp file
g++ -c main.cpp -o main.o
# links main.o and Example.o into a single executable
g++ main.o Example.o -o example

*/
