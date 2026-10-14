// the main way to do file I/O in C++ is with the fstream header
#include <iostream>
#include <fstream>
#include <string>

// the command line arguments are text arguments that are passed
// to the program when you run it
// to use them, you need to add two parameters to the main function
//  int argc - this is the number of command line arguments
//  char **argv  - this is an array of C strings that contain the command line arguments
// every program has 1 command line argument at least, which is the command used
// to run the program
// assuming this program is called "program"
// it would have the following command line argument if nothing else were passed
// "./program"
int main(int argc, char **argv) {
    
    // fstream provides two types for reading and writing files
    // ifstream is used to read files (the i is for input)
    std::ifstream fin;
    // files are opened using the "open()" member function
    fin.open("callbacks.cpp");

    // you should always check that a file was actually opened before using it
    if (fin.fail()) {
        std::cerr << "Could not open file\n";
        return 1;
    }

    // ifstream objects inherit from istream, which is what std::cin is
    // therefore, ifstream objects work just like std::cin
    std::string str;
    // fin >> str;
    std::cout << str << std::endl;
    // just like cin, whitespace will get skipped
    // the >> operator can be used like a boolean condition
    // while (fin >> str) {
    //     std::cout << str;
    // }

    // you should always close a file once you are done with it
    fin.close();

    // files are read as a stream from the first character to the last
    fin.open("callbacks.cpp");
    // the get() member function can be used to read a single character from a file
    // this will not skip whitespace
    char c;
    // while (fin.get(c)) {
    //     std::cout << c;
    // }

    fin.close();
    fin.open("callbacks.cpp");

    // you can also use the getline() function from string]
    std::string line;
    while (std::getline(fin, line)) {
        std::cout << line << std::endl;
    }

    fin.close();

    // to write to a file, you use an ofstream object
    std::ofstream fout;
    // just like how ifstream is like std::cin, ofstream behaves like std::cout
    fout.open("output.txt");
    if (fout.fail()) {
        std::cerr << "Could not open file for writing\n";
        return 2;
    }

    // if a file does not already exist, ofstream will create it
    // by default, if the file does exist, its contents will be
    // completely overwritten as soon as it is opened by ofstream

    fout << "First line of the file\n";
    fout << "Second line of the file\n";

    // remember to close the file
    fout.close();

    // to add content to the file, we need to use the 
    // std::ios::app flag
    fout.open("output.txt", std::ios::app);
    fout << "Third line of the file\n";
    fout.close();

    // the constructors for ifstream and ofstream
    // objects can be used like their open functions

    std::ifstream fin2("output.txt");
    std::ofstream fout2("output2.txt");
    fin2.close();
    fout2.close();

    // in modern versions of C++, std::strings can 
    // be passed to the constructors and open() functions

    return 0;
}
