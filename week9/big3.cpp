#include <iostream>

// the big 3 in C++ are a set of functoins that must
// be implemented when a class uses memory allocated on
// the heap
// 1. Destructor - runs when an object goes out of scope, and handles deleting pointers
// 2. Copy Constructor - runs when an object is copied
// 3. Assignment operator - may or may not work based on the compiler

class UsesDynamicMemory {
public:
    UsesDynamicMemory() {
        x = new int;
    }
    UsesDynamicMemory(int val) {
        x = new int;
        *x = val;
    }

    int getXValue() const {
        return *x;
    }

    void setXValue(int val) {
        *x = val;
    }

    // copy constructor
    UsesDynamicMemory(const UsesDynamicMemory& other) {
        x = new int;
        *x = *(other.x);
    }

    // move constructor
    UsesDynamicMemory(UsesDynamicMemory&& other) {
        x = other.x;
        other.x = nullptr;
    }

    UsesDynamicMemory& operator=(UsesDynamicMemory rhs) {
        swap(rhs);
        return *this;
    }

    void swap(UsesDynamicMemory& other) {
        int *temp = x;
        x = other.x;
        other.x = temp;
    }

    ~UsesDynamicMemory() {
        std::cout << "Destructor called\n";
        delete x;
    }
private:
    int *x;
};

void foo() {
    UsesDynamicMemory u;
}

int main() {
    UsesDynamicMemory u(4);
    UsesDynamicMemory v(u);
    UsesDynamicMemory t = u;

    t = u = v;

    std::cout << u.getXValue() << std::endl;
    std::cout << v.getXValue() << std::endl;
    std::cout << t.getXValue() << std::endl;

    v.setXValue(10);
    t.setXValue(16);

    std::cout << u.getXValue() << std::endl;
    std::cout << v.getXValue() << std::endl;
    std::cout << t.getXValue() << std::endl;

    return 0;
}
