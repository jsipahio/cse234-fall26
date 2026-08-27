#include "Example.hpp"

Example::Example(int x) {
    value = x;
}

int Example::getValue() const {
    return value;
}

void Example::setValue(int x) {
    value = x;
}
