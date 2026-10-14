#include <iostream>
// A callback is a function that is called by another function that was passed as a paramter

// originally, C had function pointers

int performOperation(int x, int y, int (*operation)(int, int)) {
    return operation(x, y);
}

int add(int x, int y) {
    return x + y;
}

int sub(int x, int y) {
    return x - y;
}

// in C++11, they added function types to the STL to
// make function parameters more consistent, and to eliminate the need for 
// the function pointer syntax
// defined in the <functional> header
#include <functional>

int performOperationWithSTDFunction(int x, int y, std::function<int(int,int)> operation) {
    return operation(x, y);
}

// C++ added objects called functors
// these are structs or classes that define the call operator
// the call operator is operator()()
// these can be passed for a function pointer
struct Adder {
    int operator()(int x, int y) {
        return x + y;
    }
};

void addToSum(int x, std::function<void(int)> sum) {
    sum(x);
}

struct Summer {
    Summer() : sum(0) {}

    void operator()(int x) {
        sum += x;
    }

    int getSum() const { return sum; }
private:
    int sum;
};

int main() {
    performOperation(1, 2, add);
    // the & to pass the address is optional,
    // but may make it clearer that a reference is being passed here
    performOperation(2, 1, &sub);

    // usage with std::function is the same as with a normal function pointer
    performOperationWithSTDFunction(1, 2, add);
    performOperationWithSTDFunction(2, 1, &sub);

    // for simple functors, we can pass an instance of the object directly
    performOperationWithSTDFunction(1, 2, Adder());

    Summer sum;
    for (int i = 0; i < 10; ++i) {
        addToSum(i, sum);
        // could also call the functor directly
        // sum(i);
    }

    std::cout << sum.getSum() << std::endl;

    // the main callback mechnism used now are lambda expressions
    // these were added in C++11
    // lambda consists of 3 parts
    //  [] - capture
    //  () - parameter list
    //  {} - body
    // optionally, there is a return type
    // -> type placed after the parameter list
    std::function<int(int, int)> addLambda = [](int x, int y) -> int {
        return x + y;
    };

    performOperationWithSTDFunction(1, 2, addLambda);

    // a lot of times, the type of a lambda is automatically deduced
    auto lambda = []() {};

    // lambdas can also be defined inline
    // in this case, we define a lambda to subtract two integers
    // directly in the argument of the function
    performOperationWithSTDFunction(2, 1, [](int x, int y) { return x - y; });
}


