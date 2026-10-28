#include <sqlite3.h>
#include <string>
#include <vector>
#include <exception>

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

