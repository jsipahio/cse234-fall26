// include the gtest header file
#include <gtest/gtest.h>

// function we are testing
int add(int x, int y) { return x + y; }

// the TEST macro expects the name of the test suite, and the name of the test
TEST(TEST_ADD_SUITE, TEST_ADD_ZEROS) {
    // the body contains the actual test code to be run
    int x = 0;
    int y = 0;
    // EXPECT_EQ compares its arguments for equality
    // it will report an error, but not crash
    EXPECT_EQ(add(x, y), 0);
}

TEST(TEST_ADD_SUITE, TEST_ADD_POSITIVE) {
    int x = 1;
    int y = 1;
    EXPECT_EQ(add(x, y), 2);
}

TEST(TEST_ADD_SUITE, TEST_ADD_NEGATIVE) {
    int x = -1;
    int y = -1;
    EXPECT_EQ(add(x, y), 2);
}

// this is the minimal main() function required to run a GTest test suite
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS(); // Automatically discovers and executes tests
}
