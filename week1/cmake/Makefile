# Makefile for the "example" executable
# the names before the colons are called targets
#	these are things you can ask make to build for you when using this Makefile
#	by default, it will build the first target in the file
# the names after the colon are dependencies
#	make will look for these files when attempting to build its corresponding targets
#	if the file doesn't exist, it will look for a target to build that file
#	if there is no target and make cannot find the file, the build will fail
# the shell commands that get run by make are indented on the line(s) below the target and its dependencies
#	like Python, the indentation is important. make will not work correctly without it

# build the executable example
# to build example, main.o and Example.o must exist
example: main.o Example.o
	g++ main.o Example.o -o example 

# build the intermediate file Example.o
# to build Example.o, Example.cpp and Example.hpp must exist
Example.o: Example.cpp Example.hpp
	g++ -c Example.cpp -o Example.o 

# build the intermediate file main.o
# to build main.o, main.cpp and Example.hpp must exist
main.o: main.cpp Example.hpp
	g++ -c main.cpp -o main.o

clean:
	rm -rf main.o Example.o example
