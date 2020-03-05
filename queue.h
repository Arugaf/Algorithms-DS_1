//
// Created by arugaf on 05.03.2020.
//

#ifndef ALGORITHMS_DS_1_QUEUE_H
#define ALGORITHMS_DS_1_QUEUE_H

#include "stack.h"

template <typename T>
class Queue {
 public:
    Queue();
    ~Queue();

    void PushBack(const T& value);
    T PopFront();
 private:
    Stack<T>* first;
    Stack<T>* second;
};

template<typename T>
Queue<T>::Queue() : first(new Stack<T>), second(new Stack<T>) {

}

template<typename T>
Queue<T>::~Queue() {
    delete first;
    delete second;
}

template<typename T>
void Queue<T>::PushBack(const T &value) {
    first->PushFront(value);
}

template<typename T>
T Queue<T>::PopFront() {
    if (second->IsEmpty() && !first->IsEmpty()) {
        *first >> *second;
    }
    return second->PopFront();
}

#endif //ALGORITHMS_DS_1_QUEUE_H
