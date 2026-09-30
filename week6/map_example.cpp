#include <iostream>
#include <string>
#include <unordered_map>

/*
Here, we'll implement a rudimentary ordering system using a map. 
Since the order of the elements is not important for this application 
(we are only looking up item numbers), an unordered_map will be used.

A second map will be used to keep track of the items added to the order. 
Note that I am using a try-catch here to handle invalid item number entries. 
*/

int main() {
    std::unordered_map<std::string, int> items {
        {"Pepsi", 1000},
        {"Diet Pepsi", 1001},
        {"Coke", 1005},
        {"Coke Zero", 1006},
        {"Lays", 1010},
        {"BBQ Lays", 1011}
    };

    std::unordered_map<int, int> orders;

    std::cout << "Items: " << std::endl;
    for (const auto& item: items) {
        std::cout << "Item Name: " << item.first;
        std::cout << " - Number: " << item.second << std::endl;
    }
    // loop for customer to add items
    while (true) {
        int input;
        std::cout << "Enter an item number: ";
        std::cin >> input;
        // check if the input is valid
        while (!items.contains(input)) {
            std::cout << "Invalid input. Enter again: ";
            std::cin >> input;
        }

        // get quantity
        unsigned quantity;
        std::cout << "Enter quantity: ";
        std::cin >> quantity;

        auto result = orders.insert(std::make_pair(input, quantity));
        // in this case, the item was not in the order
        //  we add it to the orders with the requested quantity
        if (result.second) {
            std::cout << "Added item to order\n";
        }
        else {
            std::cout << "Item already added to order\n";
            std::cout << "Do you want to increase the quantity? [y/n] >> ";
            char response;
            std::cin >> response;
            if (response == 'y' || response == 'Y') {
                orders[input] += quantity;
            }
        }

        std::cout << "Do you want to add more items [y/n]? >> ";
        char addMore;
        std::cin >> addMore;

        if (addMore == 'n' || addMore == 'N') {
            break;
        }
    }

    std::cout << "Summary: " << std::endl;
    for (const auto& order: orders) {
        std::cout << "Item " << order.first << std::endl;
        std::cout << "Quantity " << order.second << std::endl;
        std:: cout << std::endl;
    }

    return 0;
}
