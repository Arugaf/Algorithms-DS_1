//
// Created by arugaf on 05.03.2020.
//

#ifndef ALGORITHMS_DS_1_STACK_H
#define ALGORITHMS_DS_1_STACK_H

#include <cstring>
#include <iostream>
#include <utility>

template <typename T>
class Stack {
 public:
    Stack();
    ~Stack();

    void PushFront(const T& value);
    T PopFront();
    bool IsEmpty();

    void operator >>(Stack<T>& stack) {
        while (top != buffer) {
            stack.PushFront(this->PopFront());
        }
    }

 private:
    void Reallocate();

    const unsigned long int default_capacity = 10;
    unsigned int capacity;
    unsigned int current_size;

    T* buffer;
    T* top;
};

template<typename T>
Stack<T>::Stack() : capacity(default_capacity), buffer(new T[default_capacity]), current_size(0) {
    top = buffer;
}

template<typename T>
Stack<T>::~Stack() {
    delete[] buffer;
}

template<typename T>
void Stack<T>::PushFront(const T &value) {
    if (top == buffer + capacity - 1) {
        Reallocate();
    }

    *top++ = value;
}

template<typename T>
T Stack<T>::PopFront() {
    return (top > buffer) ? (*--top) : -1;
}

template<typename T>
bool Stack<T>::IsEmpty() {
    return top == buffer;
}

template<typename T>
void Stack<T>::Reallocate() {
    auto old_capacity = capacity;
    capacity *= 2;
    auto buf = new T[capacity];
    std::memcpy(buf, buffer, old_capacity * sizeof(T));
    delete[] buffer;

    buffer = buf;
    top = buffer + old_capacity - 1;
}

#endif //ALGORITHMS_DS_1_STACK_H
