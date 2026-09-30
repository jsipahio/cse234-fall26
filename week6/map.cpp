// a map is basically an associative array
// if you know Python, it's basically a dict
// if you know C#, it's basically a Dictionary

/*
in a normal array, we index using positive integers
int numbers[7] = {5, 2, 6 ,2 , 1, 2, 1};
std::cout << "The first element is " << numbers[0] << std::endl;
numbers[0] == 5;

With an associative array, we use whatever we want as the keys
stealing a bit from python syntax

items = {"book": 5, "pepsi": 20, "coke": 19, "chips": 15}
print("We have " + items["book"] + " books")

to do this in c++, we have the std::map (and similar) type
std::map<std::string, int> items = {
    {"book", 5},
    {"pepsi", 20},
    {"coke", 19},
    {"chips", 15}
};

C++ has the std::pair data type for storing the key,value pairs of maps
namespace std {
    template <typename T, typename U>
    struct pair {
        T first;
        U second;
    };
}
*/

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

struct Foo {
    int x;
    // needed to use as a key for a std::map
    bool operator<(const Foo& other) const {
        return x < other.x;
    }
};

int main() {
    // on std::map, the first generic argument is used
    //  as the key, and it must be sortable (i.e., operator < is defined)
    std::map<std::string, std::string> books {
        {"It", "Stephen King"},
        {"Dungeon Crawler", "Mat Denimen"},
        {"Lord of the Rings", "J.R.R. Tolkein"}
    };

    for (const auto& book: books) {
        std::cout << book.first << " is written by " << book.second << std::endl;
    }

    // to insert
    // the insert function performs a "safe" insertion
    // it will return an std::pair<std::map::iterator, bool>
    // the bool indicates if the element was actually inserted
    // the iterator points to the element that was inserted, or already existed
    auto result = books.insert(std::make_pair("The Shining", "Stephen King"));

    // in this case, result.first will be true
    if (result.second) {
        std::cout << "Book was inserted\n";
    }

    // this time, result.second will be false, because we already inserted this
    // this insertion will not occur, even though the value is different
    result = books.insert(std::make_pair("The Shining", "John Doe"));

    // you can perform an unsafe insertion with the subscript operators
    books["Carrie"] = "Stephen King";
    // if the key already exists, it's value will be updated
    books["It"] = "John Doe";

    // we can pass a key to the erase function to remove an element
    books.erase("It");

    // like std::set, we saw that the std::map is ordered
    // if you don't need ordering, the std::unordered_map is better
    

    return 0;

}
