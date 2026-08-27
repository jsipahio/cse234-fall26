// definition for class Example, which is declared in Example.hpp header file

// need to include the header file
// "" tell the compiler to search the current directory for the header
#include "Example.hpp"

// typical function definitions
Example::Example(int x) {
    value = x;
}

int Example::getValue() const {
    return value;
}

void Example::setValue(int x) {
    value = x;
}
