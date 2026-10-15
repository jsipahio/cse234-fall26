#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
// pretty much every algorithm
// expects at least two iterators
// as arguments

void for_each_example() {
    // std::for_each() applies a unary function
    // to every element in the collection it is passed
    std::vector<int> integers;

    for (int i = 0; i < 10; ++i) {
        integers.push_back(i);
    }

    // so, now the vector has integers from 0 to 9 in it
    // we could use it to print every value
    std::for_each(integers.begin(), integers.end(), [](int x) {
        std::cout << x << std::endl;
    });
    // we can also modify the values of a range by passing the parameter
    // by reference - in this case we double every element of the vector
    std::for_each(integers.begin(), integers.end(), [](int &x) {
        x *= 2;
    });
    std::for_each(integers.begin(), integers.end(), [](int x) {
        std::cout << x << std::endl;
    });
    int total = 0;
    std::for_each(integers.begin(), integers.end(), [&total](int x) mutable {
        total += x;
    });
    std::cout << "total = " << total << std::endl;
    // the range does not need to be the whole container
    std::for_each(integers.begin() + 4, integers.end(), [](int x) {
        std::cout << x << std::endl;
    });
}

void any_all_none_example() {  
    std::vector<int> integers;

    for (int i = 0; i < 10; ++i) {
        integers.push_back(i);
    }

    // the std::any_of() function checks if any element
    // of a range meets the unary predicate it is passed
    bool containsTen = std::any_of(integers.begin(), integers.end(), [](int x) {
        return x == 10;
    });
    if (containsTen) {
        std::cout << "vector integers contains 10\n";
    }
    else {
        std::cout << "vector integers does not contain 10\n";
    }

    bool containsEven = std::any_of(integers.begin(), integers.end(), [](int x) {
        std::cout << x << std::endl;
        return x % 2 == 0;
    });
    // in this case, it will be true
    if (containsEven) {
        std::cout << "vector integers contains an even number\n";
    }
    else {
        std::cout << "vector integers does not contain an even number\n";
    }

    // the std::all_of() function checks that every element in a range
    // meets the binary predicate it is passed
    bool allEven = std::all_of(integers.begin(), integers.end(), [](int x) {
        std::cout << x << std::endl;
        return x % 2 == 0;
    });

    if (allEven) {
        std::cout << "all numbers in vector integers are even\n";
    }
    else {
        std::cout << "some numbers in vector integers are not even\n";
    }
    // make all numbers even
    std::for_each(integers.begin(), integers.end(), [](int &x) {
        x *= 2;
    });
    allEven = std::all_of(integers.begin(), integers.end(), [](int x) {
        std::cout << x << std::endl;
        return x % 2 == 0;
    });
    if (allEven) {
        std::cout << "all numbers in vector integers are even\n";
    }
    else {
        std::cout << "some numbers in vector integers are not even\n";
    }
    // the std::none_of() function returns true
    // if no elements in the range cause the binary predicate
    // to return true
    bool noEvens = std::none_of(integers.begin(), integers.end(), [](int x) {
        std::cout << x << std::endl;
        return x % 2 == 0;
    });
    if (noEvens) {
        std::cout << "no numbers in vector integers are even\n";
    }
    else {
        std::cout << "all numbers in vector integers odd\n";
    }
    // make all numbers even
    std::for_each(integers.begin(), integers.end(), [](int &x) {
        x += 1;
    });
    noEvens = std::none_of(integers.begin(), integers.end(), [](int x) {
        std::cout << x << std::endl;
        return x % 2 == 0;
    });
    if (noEvens) {
        std::cout << "no numbers in vector integers are even\n";
    }
    else {
        std::cout << "all numbers in vector integers odd\n";
    }
}

void find_examples() {
    std::vector<int> integers;

    for (int i = 0; i < 10; ++i) {
        integers.push_back(i);
    }

    // std::find() - this function takes an element, and searches the range for it
    // returns an iterator to that element in the container
    // this always finds the first occurance of an element in the container
    // if it doesn't find a matching element, it will return the end() iterator
    auto x = std::find(integers.begin(), integers.end(), 5);
    if (x != integers.end()) {
        std::cout << "found 5\n";
    }
    else {
        std::cout << "did not find 5\n";
    }
    // need to use a reverse iterator to search from end of range
    auto y = std::find(integers.rbegin(), integers.rend(), 5);

    // we can use std::find_if() to find an element that meets
    // a particular criteria, which is provided by a unary predicate
    // let's find a number that is divisble by both 3 and 2
    auto z = std::find_if(integers.begin() + 1, integers.end(), [](int x) {
        return (x % 2 == 0) && (x % 3 == 0); 
    });
    if (z != integers.end()) {
        std::cout << "Found a number that is divisble by 3 and 2\n";
        std::cout << "That number is " << *z << std::endl;
    }
    else {
        std::cout << "The vector integers does not contain a number divisble by 3 and 2\n";
    }

    // there is also the std::find_if_not(), which returns the first element
    // that returns false for the provided unary predicate
    auto firstNegative = std::find_if_not(integers.begin(), integers.end(), [](int x) {
        return x > 0;
    });
    if (firstNegative != integers.begin()) {
        std::cout << "vector integers contains a negative value\n";
        std::cout << "The first value is " << *firstNegative << std::endl; 
    }
    else {
        std::cout << "there are no negatives in the vector integers\n";
    }

    // if we wanted to find all evens, we would need to use a loop
    auto even = std::find_if(integers.begin(), integers.end(), [](int x) {
        return x % 2 == 0;
    });
    while (even != integers.end()) {
        std::cout << *even << std::endl;
        even = std::find_if(even, integers.end(), [](int x) {
            return x % 2 == 0;
        });
    }
}

void find_first_of_example() {
    // std::string has a function called find_first_of()
    // this method takes another string as a paremter,
    // and finds the first instance of any character from that paremter in another string
    std::string greeting = "Hello World!";
    std::string punctuation = ".?!,:;";
    std::size_t index = greeting.find_first_of(punctuation);
    if (index != std::string::npos) {
        std::cout << "We found punctuation\n";
        std::cout << "The character is " << greeting[index] << std::endl;
    }

    // the algorithm version of find_first_of() works similarly,
    // but it is a free function, and of course uses iterators
    // we can do the same thing using string iterators
    auto punct = std::find_first_of(greeting.begin(), greeting.end(), punctuation.begin(), punctuation.end());
    if (punct != greeting.end()) {
        std::cout << "Found punctuation using std::find_first_of()\n";
        std::cout << "The character is " << *punct << std::endl;
    }

    // this version of find_first_of() works for any STL container
    std::vector<int> integers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> evens = {2, 4, 6, 8, 10};
    auto firstEven = std::find_first_of(integers.begin(), integers.end(), evens.begin(), evens.end());
    // we expect this to find 2, which is the second element of the integers vector
    auto lastEven = std::find_first_of(integers.rbegin(), integers.rend(), evens.begin(), evens.end());
    // in this case, it will find 10
}

void count_examples() {
    // the std::count function counts the number of times a specific element occurs in a container
    // this returns an integer type
    std::string greeting = "Hello World\n";
    int numberOfLs = std::count(greeting.begin(), greeting.end(), 'l');
    std::cout << "there are " << numberOfLs << " 'l's in the string\n";

    // the std::count_if() does the same thing, but instead of a specific element
    // it is passed a unary predicate that counts elements that return true for that predicate
    int numberOfCapitalLetters = std::count_if(greeting.begin(), greeting.end(), [](char c) {
        return (c >= 'A') && (c <= 'Z');
    });
    std::cout << "the string contains " << numberOfCapitalLetters << " capital letters\n"; 
}

int main() {
    // for_each_example();
    // any_all_none_example();
    // find_examples();
    // find_first_of_example();
    count_examples();
    
    return 0;
}
