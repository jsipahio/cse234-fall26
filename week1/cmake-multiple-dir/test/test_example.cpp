#include <Example.hpp>
#include <assert.h>

int main() {
    {
        Example ex(0);
        assert(ex.getValue() == 0);
    }
    {
        Example ex(4);
        assert(ex.getValue() == 4);
        ex.setValue(2);
        assert(ex.getValue() == 2);
    }

    return 0;
}
