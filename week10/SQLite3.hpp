#ifndef SQLITE3_HPP
#define SQLITE3_HPP

#include <vector>
#include <string>
#include <exception>

namespace sqlite3 {
    #include <sqlite3.h>
}

struct SQLPair {
    std::string name;
    std::string dataType;
};

template <typename R>
concept Row = requires (R r, std::string s) {
    { R::columns() } -> std::same_as<std::vector<SQLPair>>;
    { R::tableName() } -> std::same_as<std::string>;
    { r.get(s) } -> std::same_as<std::string>;
    r.set(s, s);
};

class SQLite3 {
public:
    // default constructor
    SQLite3();
    // destructor - should check the database is closed
    // and close it if it is not
    ~SQLite3();
    // you should not be able to copy a SQLite3 object
    SQLite3(const SQLite3& other) = delete;
    // you should not be able to copy a SQLite3 object
    SQLite3& operator=(SQLite3 rhs) = delete;

    // these will open the specified database file
    // there is a C string and std::string version
    // throw an exception if a database is already opened
    void open(const std::string& database);
    void open(const char* database);
    // this function checks if there is an open database
    bool isOpen() const;
    // this function closes the database, if it is open
    void close();

    // will create a table based on the specification of a row
    template <Row R>
    void createTable();

    // this will insert a row into the table
    template <Row R>
    void insert(const R& row);

    // this deletes a row from the table
    template <Row R>
    void deleteFrom(const std::string& predicate);

    // this selects all rows from the table
    template <Row R>
    std::vector<R> select();

    // this will take a predicate, and update whatever rows match it
    // to the values specified by the Row passed
    template <Row R>
    void update(const std::string& predicate, const R& row);
private:
    sqlite3::sqlite3 *database;
};

#endif
