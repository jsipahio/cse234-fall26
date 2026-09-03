# General Notes

More detailed notes can be found here: https://jsipahio.github.io/CSE234/week2  
Code examples are in the other files in this folder.

## STL
The C++ standard library is commonly referred to as the "Standard Template Library". This is because most of the functions and types it provides are generic, defined using templates. As an example, let's look at the two array wrappers provided by the STL, `std::vector<T>` and `std::array<T, SIZE>`.

### Vector
A vector is a dynamically allocated array that automatically resizes. Recall that a dynamic array is an array created with a pointer. This allows the array to be created on an area of memory known as the heap. This allows the array to change sizes at run time. Typical C static arrays are allocated on the "stack", which the compiler determines a fixed size for when the program is compiled. However, to resize a dynamic array, the following steps must be taken:  
1. Create a new dynamic array with the new size
2. Copy all elements from the original array to the new array
3. Create a backup pointer to the original array
4. Assign the original array to the new array
5. Delete the old array by deleting backup pointer
The `std::vector<>` class wraps a dynamic array. For one, it handles allocating memory and deleting it when the vector goes out of scope. Second, it automatically resizes the array when more elements are needed.  
To be generalizable, the vector must be able to store any data type. While C++ has a fixed number of standard, primitive data types, programmers can define their own types using structs and classes. Therefore, the vector must be a generic type. To tell the vector what type it will store, the name of the data type being stored is passed to the vector's generic argument list (angle brackets after the name `std::vector`). For example, a vector if integers would be declared using the type `std::vector<int>`. A vector of doubles are declared using `std::vector<double>`. If we had a programmer-defined struct `Student`, we can declare a vector of Students using `std::vector<Student>`.  

### Array
Vectors are very convenient, but there is a runtime performance cost to using a dynamically allocated array. On the other hand, static C arrays are clumsy to use. There is no way to know the size of a C array (technically `sizeof()` can be used, but it is also a little clunky). The STL array provides a wrapper around static C arrays, creating a class interface that provides useful information like the size of the array, and "safe" accessors called `at()` that check if the provided index is valid. Whereas `std::vector<>` only required one generic argument, the data type being stored, `std::array<>` requires two. The first generic argument is the data type the array stores. The second is the size of the array. The provided size must be a compile-time constant. For example, `std::array<int, 10>` would create an array of 10 integers. `std::array<Student, 32>` would create an array of 32 students.  

## Generic Functions
A generic function is a function that accepts different data types as its parameters and/or return type. For example, below is a generic function `add()`:
```cpp
template <typename T>
T add(T x, T y) { return x + y; }
```
The `template <>` syntax declares a template. This is an alias for a type. The name `T` will be substituted with an actual type when the function is called. The `typename` may be replaced with the keyword `class`, although in modern C++ this is rarely done. The `typename T` is referred to as a template parameter. Now, anywhere we want to use a generic type, we can use the alias `T`. In this case, the function `add()` will take two parameters of the same type, and return that type as well. For example, if we called this function like `add<int>(3, 4)`, the function would become:
```cpp
int add(int x, int y) { return x + y; }
```
If we call it like `add<std::string>("Hello ", "world")`, then the function becomes:
```cpp
std::string add(std::string x, std::string y) { return x + y; }
```
Effectively, this is what the compiler does any time you call a generic function. It replaces the template parameter (in this case, `T`) with the type passed to the function's generic argument list when it is called.  
You can define multiple template parameters for a generic function:
```cpp
template <typename T, typename U, typename R>
R sub(T x, U y) { return x - y; }
```
This generic function will use two different generic types for the parameters, then return whatever the return type of the result of subtracting those two parameters is. For example, we can call `sub<double, int, double>(1.2, 1)`, which will produce the function
```cpp
double sub(double x, int y) { return x - y; }
```
While the compiler still has to generate overloaded functions for each combination of generic arguments passed to the generic function, it saves us (the programmers) from having to manually write out all the overloads we need. Instead, we leave it to the compiler to handle that work.

## Generic Types
As we saw with `std::vector<>` and `std::array<>`, types can also be declared as generic. To do so, the template is placed before the class declaration:
```cpp
template <typename T>
class GenericClass {
public:
    GenericClass() {}
    GenericClass(const T& d): data(d) {}
    const T& getData() const { return data; }
    void setData(const T& d) { data = d; }
private:
    T data;
};
```
The template parameter `T` can be used as a type throughout the class declaration. Just like with generic functions, when a template parameter is substituted by an actual type, the compiler will generate a new definition of the class with the actual type substituted. For example, `GenericClass<int>` would generate the class:
```cpp
class GenericClass {
public:
    GenericClass() {}
    GenericClass(const int& d): data(d) {}
    const int& getData() const { return data; }
    void setData(const int& d) { data = d; }
private:
    int data;
};
```

### Non-Type Template Parameters
All the examples we have seen so far use template parameters to stand in for types. However, as we saw with `std::array<>`, template parameters can also accept values. These are called non-type template parameters. To declare one, you must use an actual type rather than `typename` or `class` in the template parameter list:
```cpp
template <typename T, size_t SIZE>
class Array {
// code in array.hpp
};
```

### Defining Methods Outside the Class Body
To define a method for a generic class outside the body of the class, the template parameter list must be redeclared for each function. Additionally, the template parameters are passed to the generic argument list of the type name when it scopes the function. For example:
```cpp
template <typename T>
class GenericClass {
public:
    GenericClass() {}
    GenericClass(const T& d): data(d) {}
    const T& getData() const;
    void setData(const T& d);
private:
    T data;
};

template <typename T>
const T& GenericClass<T>::getData() const { return data; }

template <typename T>
void GenericClass<T>::setData(const T& d) { data = d; }
```
This is because the template parameter `T` is only scoped to the immediately following class or function. Therefore, once you exit the class declaration, `T` no longer exists. It must be redeclared for each function that is defined outside the class. Additionally, now that we are outside the class declaration, you must specify `GenericClass<T>` so the compiler knows this is the implementation for the class using the template parameter `T` and not a specialization for a specific type.  
*You could even use a different template parameter name when defining the methods outside the class. However, this would be confusing, so I don't advise doing it*

## Compiling Generic Types
Since the compiler must create a new definition for each concrete type substituted into a generic type, you cannot split the implementation of a generic class into a separate `.cpp` file like you do for normal classes. This is because the implementation must be rewritten and recompiled each time the class/function is used. Therefore, generic types and functions are defined entirely in the their header file. This means that using generic types will increase compilation times, as an any file including a generic type/function must be recompiled each time that generic is modified.

## Concepts
Concepts were originally meant to be added to the C++ standard in 2011, but were delayed until 2020. Concepts provide additional checks that a type substitution will succeed when it is used as a generic argument. For example, consider this `sub<>()` function:
```cpp
template <typename T>
T sub(T x, T y) { return x - y; }
```
For this to compile, whatever type is substituted for T must have `operator-` defined for it. However, intellisense and compiler checks do not check for this until you attempt to compile the code. Therefore, it is possible to substitute an invalid generic argument and not know it until you compile your program. For example:
```cpp
std::string s = sub<std::string>(std::string("Hello "), std::string("world"));
```
Will not produce any red error squiggles in an editor. It is not until you compile it that you will get an error. Defining a concept will allow as to constrain which types can be substituted:
```cpp
template <typename T>
concept Subtractable = requires(T t) {
    t - t;
};
```
This concept, called `Subtractable`, states that instances of the type of template parameter `T` must be subtractable using the `-` operator. To use the concept, we can either use a `requires` clause on the template parameter list:
```cpp
template <typename T> requires Subtractable<T>
T sub(T x, T y) { return x - y; }
```
Or, we can use the concept `Subtractable` in place of `typename` in the template parameter list:
```cpp
template <Subtractable T>
T sub(T x, T y) { return x - y; }
```
