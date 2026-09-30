#include <algorithm>
#include <iterator>
#include <iostream>
#include <set>

int main() {
    // the set operations are defined as free functions
    // in the <algorithm> header
    
    std::set<int> evens = {2, 4, 6, 8, 10};
    std::set<int> odds = {1, 3, 5, 7, 9};
    std::set<int> integers;

    // set union
    // 5 parameters
    std::set_union(
        evens.begin(), // start of first set
        evens.end(), // end iterator of the first set
        odds.begin(), // start iterator of second set
        odds.end(), // end iterator of the second set
        std::inserter(integers, integers.begin()) // inserter with set to insert result into
    );

    for (int x: integers) {
        std::cout << x << std::endl;
    }

    std::set<int> evensCopy;
    // set intersection
    std::set_intersection(
        evens.begin(),
        evens.end(),
        integers.begin(),
        integers.end(),
        std::inserter(evensCopy, evensCopy.begin())
    );

    for (int x: evensCopy) {
        std::cout << x << std::endl;
    }

    // std::set_difference() and std::set_symmetric_difference()
    //  have the exact same usage as the other set_ functions

    // subset checking
    // this one will be false
    bool evensSubsetOfOdds = std::includes(
        evens.begin(),
        evens.end(),
        odds.begin(),
        odds.end()
    );

    // this will be true
    bool evensSubsetOfIntegers = std::includes(
        evens.begin(),
        evens.end(),
        integers.begin(),
        integers.end()
    );

    // this one is false
    bool integersSubsetOfEvens = std::includes(
        integers.begin(),
        integers.end(),
        evens.begin(),
        evens.end()
    );

    // this one is true
    bool integersSubsetOfIntegers = std::includes(
        integers.begin(),
        integers.end(),
        integers.begin(),
        integers.end()
    );

    return 0;
}
