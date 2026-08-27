# this allows multiple test files to be built. it grabs all the .cpp files in this directory
# and makes them into executables. that way, if we had a ton of tests, this CMakeLists.txt would still work

# turns on testing setting for CMake
enable_testing()

# grabs every file that ends with ".cpp" and stores it in TEST_FILES
file(GLOB TEST_FILES *cpp)

# iterates through the test files
foreach(TEST_FILE IN ITEMS ${TEST_FILES})
    # this command splits file paths
    # the NAME_WE specifies that it should store the name of the file
    # without the extension in the variable TEST_NAME
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
    # creates an executable with the name we just extracted
    add_executable(${TEST_NAME})
    # sources are the C++ file for that test
    target_sources(${TEST_NAME} 
        PRIVATE
        ${TEST_FILE}
    )
    # add the include directory
    target_include_directories(${TEST_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../src)
    # add the library
    target_link_libraries(${TEST_NAME} PRIVATE libexample)
endforeach()
