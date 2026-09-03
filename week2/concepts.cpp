#include <concepts>
#include <string>

// concept definition using existing concepts from the library
template <typename T>
// Numeric says that the type T is either integral or floating point
concept Numeric = std::integral<T> || std::floating_point<T>;

// defining a concept using a requires clause
template <typename T>
// (T t) acts sort of like a parameter list, allowing you to check
// what an instance of the type T can do in the {} block of the requires
concept Addable = requires (T t) {
    // in this case, we are checking if "t + t" can be compiled
    t + t;
};

// another concept using a requires clause
template <typename T>
concept Subtractable = requires (T t) {
    t - t;
};

template <typename T, typename U>
concept AddableAndReturnable = requires (T t, U u) {
    // the "->" syntax allows us to check the return type of the expression
    {t + u} -> std::same_as<U>;
};

template <typename T>
concept HasSizeMethod = requires (T t) {
    // you can also check if an instance has a certain member function
    t.size();
};

// a requires clause can be added to a template parameter list
// to check if a template parameter satisfies a concept
template <typename num> requires Numeric<num>
num add(num a, num b) {
    return a + b;
}

// or the concept name can directly be used in place of "typename"
template <Subtractable S>
S sub(S a, S b) {
    return a - b;
}

// example of trailing return type
auto multiply(int x, int y) -> int {
    return x + y;
}

int main() {
    float x = 10.0;
    float y = 20.0;
    float z = add<float>(x, y);

    std::string a("hello");
    std::string b(" world");
    // if you have intellisense enabled, you will see
    // a red error squiggle under "sub" since std::string
    // does not satisfy the concept Subtractable
    std::string c = sub<std::string>(a, b);

    return 0;
}
