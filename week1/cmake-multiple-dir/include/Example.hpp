#ifndef INCLUDED_EXAMPLE_HPP
#define INCLUDED_EXAMPLE_HPP

class Example {
public:
    Example(int x);
    int getValue() const;
    void setValue(int x);
private:
    int value;
};

#endif
