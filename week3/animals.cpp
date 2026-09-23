
#include <iostream>
#include <string>

class Animal {
public:
    Animal() {}
    virtual void makeSound() const {
        std::cout << "sound\n";
    }
    virtual std::string getName() const { return name; }
protected:
    std::string name;
};

class Dog: public Animal {
public:
    Dog(const std::string& n) {
        name = n;
    }
    void makeSound() const override {
        std::cout << "woof\n";
    }
};

class Cat: public Animal {
public:
    Cat(const std::string& n) {
        name = n;
    }
    void makeSound() const override {
        std::cout << "meow\n";
    }
};

// object slicing:
//  when you pass a base class by value, subclass methods, overrides, and additional fields are "sliced off"
//  
void printAnimal(const Animal &animal) {
    std::cout << "Animal's name: " << animal.getName() << "\n";
    std::cout << "Animal says: ";
    animal.makeSound();
}

int main() {
    Animal animal;
    Dog dog("fido");
    Cat cat("mr. whiskers");

    animal.makeSound();
    dog.makeSound();
    cat.makeSound();

    Animal *ptr;
    ptr = &animal;
    ptr->makeSound();
    ptr = &dog;
    ptr->makeSound();
    ptr = &cat;
    ptr->makeSound();

    printAnimal(animal);
    printAnimal(dog);
    printAnimal(cat);

    return 0;
}
