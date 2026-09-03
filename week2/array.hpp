#ifndef INCLUDED_ARRAY_HPP
#define INCLUDED_ARRAY_HPP

// because the compiler needs to generate and compile Array<T,SIZE> each time
// it is used, the implementation needs to be provided in the header file
// that way, the compiler can substitute the actual type and size when
// an Array object is created and compile the code for that version of the Array

#include <iostream>
// for size_t
#include <sys/types.h>

// in modern C++, class T and typename T are interchangeable
// although typename is now preferred

// template parameter list
template <typename T, size_t SIZE>
class Array {
public:
    Array();

    // subscript operators
    // readonly subscript
    const T& operator[](size_t index) const;
    // write/read: myArray[0] = 10;
    T& operator[](size_t index);

    // safe accessor
    const T& at(size_t index) const;
    T& at(size_t index);

    // size accessor
    size_t size() const { return capacity; }
private:
    T data[SIZE];
    size_t capacity;
};

// insertion operator overloaded as free function
template <typename T, size_t SIZE>
std::ostream& operator<<(std::ostream& out, const Array<T, SIZE>& arr) {
    bool printComma = false;
    for (size_t i = 0; i < arr.size(); ++i) {
        if (printComma) out << ", ";
        out << arr[i];
        printComma = true;
    }
    return out;
}

// to define methods outside the class body
// the template parameter list must be provided for each of them
template <typename T, size_t SIZE>
// template parameters are passed to the type name when scoping
Array<T, SIZE>::Array(): capacity(SIZE) {}

template <typename T, size_t SIZE>
const T& Array<T, SIZE>::operator[](size_t index) const {
    return data[index];
}

template <typename T, size_t SIZE>
T& Array<T, SIZE>::operator[](size_t index) {
    return data[index];
}

template <typename T, size_t SIZE>
const T& Array<T, SIZE>::at(size_t index) const {
    if (index < capacity) {
        return data[index];
    }
    else {
        throw "Invalid index: index greater than capacity";
    }
}

template <typename T, size_t SIZE>
T& Array<T, SIZE>::at(size_t index) {
    if (index < capacity) {
        return data[index];
    }
    else {
        throw "Invalid index: index greater than capacity";
    }
}

#endif

