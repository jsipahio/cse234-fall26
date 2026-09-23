#include <iostream>

#include <array>
#include <vector>
#include <list>
#include <deque>

// Array
/*
std::array<int, 5> myArray;
 - generic argument: data type of the values stored
 - generic argument: capacity of the array
Equivalent C Array:
int myArray[5];

- size() - returns the max size of the array
- at() - throws an std::out_of_range exception if the provided index is out of the array's bounds
myArray.at(6) -> throws std::out_of_range
- at() can be used just like the subscript

std::cout << myArray.at(0) << std::endl;
myArray.at(0) = 5;

- at() is more expensive than subscript, but allows you to handle out of bounds access attempts
*/
void useArray() {
    // simple declaration
    std::array<int, 5> integers;
    // in C++17 and later, these can be deduced
    std::array integerCopy = integers;
    // you can use initializer list
    std::array<double, 3> doubles = { 1.0, 2.0, 3.0 };

    // keep in mind C-strings are the default
    std::array strings = {"hello", "world" };
    // this creates std::array<const char*, 2>

    // if you want to handle std::out_of_range, 
    // you need to use a try-catch block
    try {
        for (size_t i = 0; i < 4; ++i) {
            std::cout << doubles.at(i) << std::endl;
        }
    }
    // these go in order of most to least specific
    catch (std::out_of_range &ex) {
        // all std::exception subclasses have the .what() member
        std::cout << ex.what() << std::endl;
        std::cout << "Handled std::out_of_range\n";
    }
    catch (std::exception &ex) {
        std::cout << ex.what() << std::endl;
        std::cout << "Handled std::exception\n";
    }
    // the ... option must always go last
    catch (...) {
        std::cout << "Unknown exception type\n";
    }
}

// Vector
/*
- std::vector is an automatically resizing, dynamically allocated array
- most implementations double the size of the vector each time it runs out of space
- only needs the data type passed as a generic argument

std::vector<int> myVector; -> vector of integers
std::vector<int> myVector(5); -> vector of 5 integers

- vector also has size() -> returns the currently *used* elements
- to get the current capactity, use the capacity() member
- shrink_to_fit() to automatically trim extra elements off the vector
- reserve(size_t) is used to change the capacity of the vector
- push_back() -> adds elements to the end of the vector
- pop_back() -> removes an element from the end of the vector
- no direct access to the front of the vector
    - addding/removing elements from the front is expensive due to shifts
- at() and [] just like std::array
*/
// Iterators
/*
- an iterator, is a abstraction for accessing elements of containers
- for arrays, where everything is stored sequentially, indices make sense
- all STL containers have a begin() and end() member function
    - begin() returns an iterator which points to the first element of the container
    - end() returns an iterator which points past the end of the container


index: | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 
value: | 4 | 6 | 2 | 7 | 8 | 2 | 6 | 1 |
begin() returns a pointer to index 0 of the array
end() returns a pointer to index 8 of the array
- end() is used to check that you have reached the end of the container

std::vector<int> integers;
// pretend some values are added
std::vector<int>::iterator it = integers.begin();
// using auto data type instead
auto it = integers.begin();

std::cout << *it << std::endl;
// equivilent to doing
std::cout << integers[0] << std::endl;
// iterators support the ++ operator
++it;
std::cout << *it << std::endl;
// same as
std::cout << integers[1] << std::endl;

// advances it by 2 elements
auto it3 = it + 2;
std::cout << *it3 << std::endl;
// same as
std::cout << integers[3] << std::endl;
*/
// Vector Continued:
/*
to insert at front:
myVector.insert(3, myVector.begin());
to insert at third element
myVector.insert(3, myVector.begin() + 3);

same thing for removal:
myVector.erase(myVector.begin());
*/

// List
/*
front <-> element1 <-> element2 <-> element4 <-> element3 <-> back

A list consists of nodes, which are connected to each other via pointers
- you don't need to know the size of a list ahead of time
- with a list, it only uses the space needed to store the current number of elements
- however, each element of the list uses more space since it has to store pointers
    - STL list is doubly linked (has a previous and next pointer)
    - On a 64-bit, each pointer is 8 bytes
    - therefore, there is an overhead of 16 bytes for each list element

std::list<std::string> myList;
- one generic argument, the data type of the elements

- unlike array and vector, lists do not support [] and at() to access elements
- accessing a random element via iterator is a lot more expensive
    - on an array or vector, just add a byte offset
    - to access a random iterator, each element of list must be visited to find the next node
- it does support push_back() and pop_back() like vector does
- also supports push_front() and pop_front(), unlike vector
- adding elements to any point in a list is relatively cheap
    - assuming you know the location ahead of time, adding an element anywhere is basically free

- also supports the erase() and insert() members, operation is the same as vector
- list has a couple of unique functions
    - splice()
        - used to hook two lists together, or insert one list into the middle of another
    - merge()
        - if you have two sorted lists, merge will combine them into one sorted list efficiently
*/

// Deque
/*
- from a computer science point of view, a deque is a doubly-ended queue
    - a queue is a container where you add elements to the end, and remove them from the front
    - a deque basically allows entry and exit from the front and end

- it is a list of arrays
- it has most of the list member functions, but also allows random access
    - i.e., it has [] and at() members
- deque has the highest memory cost of any of the STL containers
- it allows cheap insertion and removal at any location, without losing access to random access members
*/

// container adaptors
/*
Stack:
- access to elements is last-in, first-out
- have utility when you need to add and remove data in reverse orders
- a C++ vector is already basically a stack
std::list<int> myList;
// insert elements
std::stack myStack(myList);
// create a raw stack
std::stack<int, std::forward_list> listStack;

Queue:
- access to elements is first-in, first-out
- have utility when you need to access data in the order it is inserted
- usage is exactly the same as stack

Both:
- use push() to add an element, and pop() to remove an element
*/


int main() {
    useArray();
    std::cout << "Done\n";
    return 0;
}
