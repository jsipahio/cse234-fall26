cmake_minimum_required(VERSION 3.28)
project(CSE234_EXAMPLE)

add_executable(example)
target_sources(example PRIVATE main.cpp Example.cpp Example.hpp)
