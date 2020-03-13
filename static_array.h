//
// Created by arugaf on 13.03.2020.
//

#ifndef ALGORITHMS_DS_1_STATIC_ARRAY_H
#define ALGORITHMS_DS_1_STATIC_ARRAY_H

#include <iostream>

template <typename T>
class Array {
public:
    explicit Array(unsigned int size);
    void AddElement(T element);
    [[nodiscard]] unsigned int GetSize() const;

    T operator[](unsigned int index) const;

    ~Array();
private:
    unsigned int size;
    unsigned int current_element;
    T* array;
};

template<typename T>
Array<T>::Array(unsigned int size) : size(size), current_element(0) {
    array = new T[size];
}

template<typename T>
Array<T>::~Array() {
    delete[] array;
}

template<typename T>
void Array<T>::AddElement(T element) {
    if (current_element < size) {
        array[current_element++] = element;
    }
}

template<typename T>
unsigned int Array<T>::GetSize() const {
    return size;
}

template<typename T>
T Array<T>::operator[](unsigned int index) const {
    return array[index];
}

#endif //ALGORITHMS_DS_1_STATIC_ARRAY_H
