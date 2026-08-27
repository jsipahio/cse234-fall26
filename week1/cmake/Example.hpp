// header file for class Example. the class is declared here

// these are include guards. when a file is included, it's code is copy-pasted into the file with the include
// if the same file is included twice, that could result in a "redeclaration" error and fail to compile
// therefore, these are used to prevent the code in the header from being compiled twice

// the ifndef checks if INCLUDED_EXAMPLE_HPP is defined
// if it isn't, everything until #endif is compiled
#ifndef INCLUDED_EXAMPLE_HPP
// this immediately defines the INCLUDED_EXAMPLE_HPP macro
// this way, if this code is encountered again, the macro will exist and the code will not be compiled
#define INCLUDED_EXAMPLE_HPP

// class declaration
class Example {
public:
    Example(int x);
    int getValue() const;
    void setValue(int x);
private:
    int value;
};

// ends the conditional compilation
#endif
