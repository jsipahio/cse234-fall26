#include "DateTime.hpp"

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

struct Book {
  std::string title;
  std::string author;
  std::string isbn;
  std::string genre;
  DateTime dateStocked;
  DateTime datePublished;
  double price;
  std::size_t stockId;
};

class Inventory {
public:
    Inventory() {}
    // adds a book to the Inventory
    // must assign a unique ID to the book
    void addBook(const Book&);
    // removes a book from the Inventory based on its stockId
    void removeBook(std::size_t stockId);
    // modifies (i.e., replaces) a book in the inventory based on its stockId
    void modifyBook(std::size_t stockId, const Book& modifiedBook);
    // returns a single book based on it's stockId
    const Book& findBook(std::size_t stockId) const;
    // returns a vector of books that match the predicate passed
    std::vector<Book> findBooks(std::function<bool(const Book&)> predicate) const;
    // removes all books that match the predicate passed
    void removeBooks(std::function<bool(const Book&)> predicate);
    // applies the bookModifier function to all books that match the predicate passed
    void modifyBooks(std::function<bool(const Book&)> predicate, std::function<void(Book&)> bookModifier);
    // prints out all books in the inventory
    // format the details of the book as shown on the following lines
    // Title - Author - Genre - ISBN - Price
    void printInventory() const;
    // applies discounts based on the passed functions (the functions determine if the book should have a discount and applies it)
    void printInventory(std::vector<std::function<void(Book&)>> discounts) const;
    // reduces price of all inventory items by 5% if they are more than one year old
    void discountOldInventory();
private:
    std::vector<Book> books;
};

int main() {
    // populate the inventory with some books
    // demonstrate all functions in the Inventory class
}
