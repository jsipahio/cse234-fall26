// contains std::set<> and std::multiset<>
#include <set>
// contains std::unordered_set<> and std::unordered_multiset<>
#include <unordered_set>

#include <iostream>

int main() {
    std::set<int> integers;

    integers.insert(1);
    // added in C++20
    // returns true if the element passed is in the set
    bool containsOne = integers.contains(1);

    // prior to C++20, you had to use the find() member
    auto result = integers.find(1);
    // this returns an iterator to the location of that element
    //  or it returns integers.end() if not found
    // if you want to check containment of an element, you have to
    //  compare with the end iterator
    if (integers.find(2) != integers.end()) {
        std::cout << "integers contains 2\n";
    }
    else {
        std::cout << "integers does not contain 2\n";
    }
    // C++20 made this a lot simpler
    if (integers.contains(2)) {
        std::cout << "integers contains 2\n";
    }
    else {
        std::cout << "integers does not contain 2\n";
    }

    // to remove, use the erase member function
    integers.erase(1);

    // can use an initializer list
    std::unordered_set<double> doubles = { 1.2, 2.1, 6.3, 2.5, 8.4 };

    // sets work with range-based for loops
    for (double x: doubles) {
        std::cout << x << std::endl;
    }

    return 0;
}
