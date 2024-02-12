#pragma once
#include <iostream>

template<typename T>
struct Vector {
    int size;
    T* data;

    Vector(int size, T* initial_values) : size(size), data(new T[size]) {
        for(int i=0; i<size; i++) {
            data[i] = initial_values[i];
        }
    }

    ~Vector() {
        delete[] data;
    }

    void setIndex(int index, T value) {
        this->data[index] = value;
    }

    void print() const {
        for(int i=0; i<this->size; i++) {
            std::cout << this->data[i];
            if(i != this->size-1)
                std::cout << ", ";
        }
        std::cout << std::endl;
    }

};


