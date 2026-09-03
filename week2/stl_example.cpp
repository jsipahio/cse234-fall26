// the c++ standard library is often called the STL (standard template library)
#include <array>
#include <iostream>
#include <vector>

// we can manually define overloads for all vector type substitutions
void printVector(const std::vector<int>& intVector) {
    //...
}

void printVector(const std::vector<double>& doubleVector) {
    //...
}

// or, we can use a generic function, and let the compiler implement the overloads for us

// declares a generic type alias T
template <typename T>
void printVector(const std::vector<T>& vec) {
    // ...
}

int main() {
    // vector is an automatically resizing dynamic array wrapper 
    //static array
    int array[10];
    // dynamic array
    int *dArray = new int[10];
    delete[] dArray;
    // vector of ints
    // int is passed to vector's generic argument list, denoted by the angle brackets
    std::vector<int> intVector(10);
    // vector of doubles
    std::vector<double> doubleVector;
    // 2d vector of int
    std::vector<std::vector<int>> matrix;

    // provide concrete type as generic argument to the function
    printVector<int>(intVector);

    // std::array
    // array takes two generic arguments, the data type and the size of the array
    std::array<int, 10> intStdArray;
    for (size_t i = 0; i < intStdArray.size(); ++i) {
        std::cout << "Enter a value: ";
        std::cin >> intStdArray[i];
    }
}
