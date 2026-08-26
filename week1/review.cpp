#include <iostream>
#include <string>

int add(int x, int y);

void printGreeting() {
    std::cout << "Hello world!\n";
}

void printMessage(const std::string& msg) {
    std::cout << msg;
}

void readValues(int& x, int& y) {
    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << "Enter y: ";
    std::cin >> y;
}

struct Person {
    // default public
    std::string firstName;
    std::string lastName;
private:
    std::string socialSecurityNumber;
}

class BankAccount {
public:
    Person accountHolder;
}

int main() {
    int x = 0;
    std::string name;

    Person person;
    person.firstName = "John";
    person.lastName = "Doe";

    BankAccount account;
    account.accountHolder.firstName = "John";

    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << name << std::endl;

    int array[] = { 1, 2, 3, 4, 5 };
    int empty[10];

    if (name == "John") {
        std::cout << "name is john\n";
    }
    else if (name == "Prince") {
        std::cout << "name is Prince\n";
    }
    else {
        std::cout << "Unknown name\n";
    }

    char answer;
    do {

    } while (answer == 'y');\
    
    for (int i = 0; i < 10; ++i) {

    }


    return 0;
}

int add(int x, int y) {
    return x + y;
}
