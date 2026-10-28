#include <iostream>
#include <string>
#include <vector>
#include <sqlite3.h>

// CRUD operations
// - CREATE corresponds to the INSERT INTO SQL statement
// - READ corresponds to the SELECT SQL Statement
// - UPDATE corresponds to the UPDATE SQL Statement
// - DELETE corresponds to the DELETE FROM SQL Statement

int main() {
    // Representative struct for table rows
    struct User {
        int id;
        std::string name;
        int age;
        double balance;
    };

    sqlite3* db = nullptr;
    char* errMsg = nullptr;

    // 1. Open an in-memory database (use "test.db" for a persistent file)
    // sqlite3_open() opens a database
    // first argument is the database file
    // second is the database object reference
    // C Functions typically return an integer which is an error code
    // since C does not have the ability to throw an exception
    if (sqlite3_open(":memory:", &db) != SQLITE_OK) {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << "\n";
        return 1;
    }

    // 2. CREATE TABLE
    const char* createTableSQL = 
        "CREATE TABLE IF NOT EXISTS Users ("
        "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
        "NAME TEXT NOT NULL, "
        "AGE INT NOT NULL, "
        "BALANCE REAL NOT NULL);";

    // sqlite3_exec()
    // this is a convenience function for executing SQL statments with SQLite3
    // first argument is the database object pointer
    // the second argument is the SQL statement (as a C-string) that is to be executed
    // the last (5th) argument is a pointer to a C string to store the error message
    if (sqlite3_exec(db, createTableSQL, nullptr, nullptr, &errMsg) != SQLITE_OK) {
        std::cerr << "CREATE TABLE failed: " << errMsg << "\n";
        // this function frees the memory used by the errMsg string
        sqlite3_free(errMsg);
        // this function closes the database connection
        sqlite3_close(db);
        return 1;
    }

    // 3. INSERT (Create)
    std::vector<User> newUsers = {
        {0, "Alice", 30, 1500.50},
        {0, "Bob", 25, 800.00},
        {0, "Charlie", 35, 2300.75}
    };

    const char* insertSQL = "INSERT INTO Users (NAME, AGE, BALANCE) VALUES (?, ?, ?);";
    sqlite3_stmt* stmt = nullptr;

    for (const auto& u : newUsers) {
        // so, the first thing to do is to create the prepared statement
        // the first argument is the database
        // the second argument is the C-string with the statement to be executed
        // the third argument is always -1 for our usage
        // the fourth arugment is your sqlite3_stmt pointer
        // the fifth argument we won't worry about today
        sqlite3_prepare_v2(db, insertSQL, -1, &stmt, nullptr);
        // the first argument is the statement we are binding a value
        // the second argument is the position (1 -indexed) of the argument being bound
        // the third argument is the value being bound
        // the others just copy
        sqlite3_bind_text(stmt, 1, u.name.c_str(), -1, SQLITE_TRANSIENT);
        // bind age to the 2nd question mark
        sqlite3_bind_int(stmt, 2, u.age);
        // bind the balance to the 3rd question mark
        sqlite3_bind_double(stmt, 3, u.balance);

        // we can call the sqlite3_step() function with a statement
        // this will execute the statement and return the database result
        if (sqlite3_step(stmt) != SQLITE_DONE) {
            // since this function does not accept an errMsg parameter
            // we need to call the sqlite3_errmsg() function to get
            // the latest error message
            std::cerr << "Insert failed: " << sqlite3_errmsg(db) << "\n";
        }
        // this commits the database transaction
        sqlite3_finalize(stmt);
    }
    std::cout << "Inserted initial records.\n";

    // 4. UPDATE (Modify)
    const char* updateSQL = "UPDATE Users SET BALANCE = ? WHERE NAME = ?;";
    // once again, we need to prepare a statement
    sqlite3_prepare_v2(db, updateSQL, -1, &stmt, nullptr);
    // and we need to bind the new balance to the first question mark
    sqlite3_bind_double(stmt, 1, 1950.00);
    // and bind the name of the user being updated to the second question mark
    sqlite3_bind_text(stmt, 2, "Alice", -1, SQLITE_TRANSIENT);

    // just like before, we need to check if the update succeeded
    if (sqlite3_step(stmt) == SQLITE_DONE) {
        std::cout << "Updated Alice's balance to 1950.00.\n";
    }
    sqlite3_finalize(stmt);

    // basically the same as an update
    // 5. DELETE
    const char* deleteSQL = "DELETE FROM Users WHERE NAME = ?;";
    sqlite3_prepare_v2(db, deleteSQL, -1, &stmt, nullptr);
    sqlite3_bind_text(stmt, 1, "Bob", -1, SQLITE_TRANSIENT);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        std::cout << "Deleted record for Bob.\n";
    }
    sqlite3_finalize(stmt);

    // 6. SELECT (Read into C++ structs)
    const char* selectSQL = "SELECT ID, NAME, AGE, BALANCE FROM Users;";
    // we want to prepare our SQL statement
    sqlite3_prepare_v2(db, selectSQL, -1, &stmt, nullptr);

    // we want to create a vector to store the values from the table
    std::vector<User> retrievedUsers;
    // now we want to check if the sqlite3_step returns a SQL row
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        // create a user
        User u;
        // in this case, we are using 0 indexing for the values
        // sqlite3_colunn_int() will get the latest integer value at the
        // specified index from the provided statement
        //  the values are going to be read from the database as a 
        //  array of c-strings
        //  the column_datatype will cast them to the datatype used
        u.id = sqlite3_column_int(stmt, 0);
        // cast it as a C-string, then store it in the name value
        u.name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        // another integer, so we use column_int()
        u.age = sqlite3_column_int(stmt, 2);
        // and then the last value is the balance, which is a double
        // so we use sqlite3_column_double()
        u.balance = sqlite3_column_double(stmt, 3);
        // at this point, we've read the data values for each
        // field of our struct, and we can push it into the vector
        retrievedUsers.push_back(u);
    }
    // then we need to call finalize to say we are done with this statement
    sqlite3_finalize(stmt);

    // Output query results
    std::cout << "\n--- Current Database Contents ---\n";
    for (const auto& u : retrievedUsers) {
        std::cout << "ID: " << u.id 
                  << " | Name: " << u.name 
                  << " | Age: " << u.age 
                  << " | Balance: $" << u.balance << "\n";
    }

    // we need to call sqlite3_close to release the database file
    // 7. Clean up connection
    sqlite3_close(db);
    return 0;
}
