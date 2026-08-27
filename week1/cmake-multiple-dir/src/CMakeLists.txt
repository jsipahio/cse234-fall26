
# create the libexample static library
add_library(libexample)
# add the include directory
target_include_directories(libexample PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
# add the source code
target_sources(libexample PRIVATE Example.cpp)

# create the example executable
add_executable(example)
# add the source code
target_sources(example PRIVATE main.cpp)
# add the library
target_link_libraries(example PRIVATE libexample)
