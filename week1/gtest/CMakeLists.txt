cmake_minimum_required(VERSION 3.28)

project(CSE234-GTEST-WEEK1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)

add_executable(testing_example)
target_sources(testing_example PRIVATE testing_example.cpp)
target_link_libraries(testing_example
    PRIVATE 
        GTest::gtest 
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(testing_example)