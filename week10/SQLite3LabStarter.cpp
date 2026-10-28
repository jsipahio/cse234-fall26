#include "SQLite3.hpp"
#include <iostream>

class InvalidColumnError : std::exception {
public:
    InvalidColumnError() : message("Invalid Column Error") {}
    InvalidColumnError(const std::string& msg) : message(msg) {}
    InvalidColumnError(const char* msg) : message(msg) {}
    ~InvalidColumnError() override = default;
    const char * what() const noexcept override { return message.c_str(); }
private:
    std::string message;
};

struct Item {
    int id;
    double price;
    std::string name;

    static std::string tableName() { return std::string("items"); }

    static std::vector<SQLPair> columns() {
        return {
            {"id", "INTEGER"},
            {"price", "REAL"},
            {"name", "VARCHAR(255)"}
        };
    }

  std::string get(const std::string& column) {
        if (column == "id") {
            return std::to_string(id);
        }
        else if (column == "price") {
            return std::to_string(price);
        }
        else if (column == "name") {
            return name;
        }
        else {
            throw InvalidColumnError("Unexpected column name");
        }
    }

    void set(const std::string& column, const std::string& value) {
        if (column == "id") {
            id = std::stoi(value);
        }
        else if (column == "price") {
            price = std::stod(value);
        }
        else if (column == "name") {
            name = value;
        }
        else {
            throw InvalidColumnError("Unexpected column name");
        }
    }
};

int main() {
    SQLite3 database;
    database.open("items.db");

    if (database.isOpen()) {
        database.createTable<Item>();

        std::vector<Item> items = {
            {1, 3.45, "Chips"},
            {2, 1.99, "Soda"},
            {3, 1.45, "Candy"}
        };

        for (const Item& item : items) {
            database.insert(item);
        }

        database.deleteFrom<Item>("id = 1");

        database.update<Item>("id = 2", {2, 2.10, "Chips"});

        auto itemsInDb = database.select<Item>();

        for (const Item& item: itemsInDb) {
            std::cout << "Item " << item.id << " - $" << item.price << " - " << item.name << std::endl;
        }

        database.close();
    }
    else {
        std::cerr << "Database did not open\nAbort\n";
        return 1;
    }

    return 0;
}
