//
// Created by arugaf on 14.03.2020.
//

#include <iostream>

template <typename T>
class Heap {
 public:
    Heap(T*& array, const unsigned int& left, const unsigned int& right,
         bool comparator(const T& lhs, const T& rhs) = [](const T& lhs, const T& rhs) -> bool {return lhs > rhs;});
    ~Heap();

    T GetMax();
 private:
    T* heap_array;
    unsigned int heap_size;

    void Heapify(bool comparator(const T& lhs, const T& rhs));
    void SiftDown(const unsigned int& index, bool comparator(const T& lhs, const T& rhs));
};

template<typename T>
Heap<T>::Heap(T*& array, const unsigned int& left, const unsigned int& right, bool comparator(const T& lhs, const T& rhs)) : heap_size(right - left + 1) {
    heap_array = new T[heap_size];

    for (auto i = 0; i < heap_size; ++i) {
        heap_array[i] = array[i + left];
    }

    Heapify(comparator);
}

template<typename T>
Heap<T>::~Heap() {
    delete[] heap_array;
}

template<typename T>
void Heap<T>::Heapify(bool comparator(const T& lhs, const T& rhs)) {
    for (int i = heap_size / 2 - 1; i >= 0; --i) {
        SiftDown(i, comparator);
    }
}

template<typename T>
void Heap<T>::SiftDown(const unsigned int& index, bool comparator(const T& lhs, const T& rhs)) {
    unsigned int left = 2 * index + 1;
    unsigned int right = 2 * index + 2;

    auto largest = index;
    if (left < heap_size && comparator(heap_array[left], heap_array[index])) {
        largest = left;
    }
    if (right < heap_size && comparator(heap_array[right], heap_array[largest])) {
        largest = right;
    }

    if (largest != index) {
        std::swap(heap_array[index], heap_array[largest]);
        SiftDown(largest, comparator);
    }
}

template<typename T>
T Heap<T>::GetMax() {
    return heap_array[0];
}

int main() {
    unsigned int array_size = 0;
    std::cin >> array_size;

    auto array = new int[array_size];

    int element = 0;
    for (int i = 0; i < array_size; ++i) {
        std::cin >> element;
        array[i] = element;
    }

    unsigned int windows_size = 0;
    std::cin >> windows_size;

    int max = array[0];
    bool build_heap = true;
    for (unsigned int i = 0, j = windows_size - 1; j < array_size; ++i, ++j) {
        if (array[j] > max) {
            max = array[j];
        }

        if (build_heap) {
            Heap<int> heap(array, i, j);
            max = heap.GetMax();
            build_heap = false;
        }

        if (array[i] == max) {
            build_heap = true;
        }

        std::cout << max << ' ';
    }

    delete[] array;

    return 0;
}
