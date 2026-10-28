
#ifndef VECTOR_HPP
#define VECTOR_HPP

template <typename T>
class Vector {
public:
    Vector() {
        data = nullptr;
        capacity = 0;
    }
    Vector(unsigned size) {
        data = new T[size];
        capacity = size;
    }
    ~Vector() {
        delete[] data;
        capacity = 0;
    }
    Vector(const Vector& other) {
        data = new T[other.capacity];
        capacity = other.capacity;
        for (unsigned i = 0; i < capacity; ++i) {
            data[i] = other.data[i];
        }
    }
    void swap(Vector& other) {
        T *temp = data;
        data = other.data;
        other.data = temp;

        unsigned tempC = capacity;
        capacity = other.capacity;
        other.capacity = tempC;
    }

    Vector& operator=(Vector rhs) {
        swap(rhs);
        return *this;
    }

    void pushBack(const T& value) {
        if (usedIndex + 1 == capacity) {
            // we need to double the size of the vector
            T *temp = data;
            data = new T[capacity * 2];
            for (unsigned i = 0; i < usedIndex; ++i) {
                data[i] = temp[i];
            }
            delete temp;
            capacity *= 2;
        }
        ++usedIndex;
        data[usedIndex] = value;
    }

private:
    T *data;
    unsigned capacity;
    unsigned usedIndex;
};

#endif
