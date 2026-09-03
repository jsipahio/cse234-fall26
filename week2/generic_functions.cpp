#include <string>
// handles any two types (that can be added)
// returns whatever T + U returns by default
template <typename T, typename U, typename R>
R add(T x, U y) { return x + y; }

template <typename T, typename U, typename R>
R sub(T x, U y) { return x - y; }

double add(int x, double y) { return x + y; }

int main() {
    int x = 10;
    double y = 13;
    double z = add<int, double, double>(x, y);

    std::string a("hello");
    std::string b(" world");
    std::string c = add<std::string, std::string, std::string>(a, b);
    // when using generic "typename T", this will not produce an error squiggle
    // however, this line will fail to compile
    std::string d = sub<std::string, std::string, std::string>(a, b);
    return 0;
}

