#include <iostream>

// in C++, there are two main types of pointers to worry about

int main() {
    // you can declare a pointer that references
    // an existing variable
    int x = 5;
    int *ptr = &x;
    // keep in mind that all pointers are variables
    // that store a memory address

    // if we print out ptr we get the memory address it stores
    std::cout << ptr << std::endl;
    // to get the value at that address, we need 
    // to derereference the pointer
    std::cout << *ptr << std::endl;

    // the other type of pointer is a raw pointer
    // these create new memory on an area called the heap
    int *rawPtr = new int;

    *rawPtr = 10;
    std::cout << rawPtr << std::endl;
    std::cout << *rawPtr << std::endl;

    // raw pointers must be freed using the 
    // delete operator
    delete rawPtr;

    // dynamic arrays
    int *dArray = new int[10];
    for (int i = 0; i < 10; ++i) {
        dArray[i] = i;
    }

    // you have to free the memory of a dynamic array as well
    delete[] dArray;

    return 0;
}