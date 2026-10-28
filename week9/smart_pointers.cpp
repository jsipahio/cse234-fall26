// using pointers is an easy way to get yourself in a lot of trouble

#include <memory>

class Example {
public:
    Example() : x(new int) {}
private:
    std::unique_ptr<int> x;
};

int main() {
    // there are three types of smart pointers in
    // modern C++

    // std::unique_ptr<>
    // this stores a unique (meaning other entities cannot have a pointer to this)
    // pointer to a value on the heap
    // meant to prevent memory leaks

    // std::shared_ptr<>
    // this allows multiple objects to reference
    // the same memory location, and keeps that 
    // memory location safe from being deleted
    // before all objects are done with it
    // meant to prevent dangling pointers
    // shared_ptr keeps a count of how many objects
    // are currently referencing a memory location
    // and will delete the object only once the 
    // reference count gets to 0

    // std::weak_ptr<>
    // this is like a shared_ptr but
    // without reference counting


}
