// include preprocessor directives
#include <iostream>
#include <string>

// function declaration - returns an integer
// primitives like integers are passed-by-value most of the time
int add(int x, int y);

// function definition, void so it returns nothing
void printGreeting() {
    std::cout << "Hello world!\n";
}

// pass objects by const reference if the function 
// does not modify them
void printMessage(const std::string& msg) {
    std::cout << msg;
}

// use pass-by-reference if the function does modify its parameters
void readValues(int& x, int& y) {
    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter y: ";
    std::cin >> y;
}

// structs have public access by default
struct Person {
    // default public
    std::string firstName;
    std::string lastName;
private:
    std::string socialSecurityNumber;
};

// classes have private access by default
class BankAccount {
public:
    Person accountHolder;
};

// otherwise, classes and structs can do the exact same things in C++ and are mostly interchangeable
// stylistically, most C++ programmers use structs for pure data types and classes for abstract data types

// all C++ executables use "int main() {}" as an entry point
int main() {
    // variable declaration with initialization
    int x = 0;
    // variable declaration without init
    std::string name;

    // struct variable decl
    Person person;
    // setting public fields of the struct
    person.firstName = "John";
    person.lastName = "Doe";

    // class variable decl
    BankAccount account;
    // setting public field of the class
    account.accountHolder.firstName = "John";

    // std::cout is used to output text to the screen
    // the << operator is called the insertion operator
    std::cout << "Enter name: ";
    // std::cin reads text from the console
    // the >> operator is called the extraction operator
    std::cin >> name;
    // std::endl prints a new line character
    std::cout << name << std::endl;

    // arrays that have initial values do not need the size explicitly stated
    int array[] = { 1, 2, 3, 4, 5 };
    // arrays that do not have values need a size
    int empty[10];

    // conditions are placed in parenthesis
    // if - else if - else chain
    if (name == "John") {
        std::cout << "name is john\n";
    }
    else if (name == "Jane") {
        std::cout << "name is Jane\n";
    }
    else {
        std::cout << "Unknown name\n";
    }

    // while loops execute as long as their condition is true
    while (true) {
        // break will exit a loop immediately
        break;
    }

    // for a do-while loop, the control var must be declared before the loop
    char answer;
    do {
        std::cout << "Again?: ";
        std::cin >> answer;
    } while (answer == 'y'); // semicolon after the while ()
    
    // for loops have an init, condition, and increment (or decrement) expression
    // each are separated by a semicolon
    for (int i = 0; i < 10; ++i) {

    }

    // the operating system expects a successful program to return the code 0
    return 0;
}

// definition of the add function declared at the top of the file
int add(int x, int y) {
    return x + y;
}
