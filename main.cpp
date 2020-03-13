//
// Created by arugaf on 12.03.2020.
//

#include "static_array.h"

template<typename T>
unsigned int DefineBound(const Array<T>& array, const T& key) {
    unsigned int bound = 1;

    while (bound < array.GetSize() && array[bound] < key) {
        bound *= 2;
    }
    return bound;
}

template<typename T>
unsigned int BinarySearch(const Array<T>& array, const T& key, unsigned int left, unsigned int right) {
    unsigned int middle = (left + right) / 2;

    for (; left < right; middle = (left + right) / 2) {
        if (key < array[middle]) {
            right = middle - 1;
        } else if (key > array[middle]) {
            left = middle + 1;
        } else {
            return middle;
        }
    }

    return array[middle] == key ? middle : array.GetSize();
}

template<typename T>
unsigned int ExponentialSearch(const Array<T>& array, const T& key) {
    auto bound = DefineBound(array, key);
    return BinarySearch<T>(array, key, bound / 2, std::min(bound + 1, array.GetSize()));
}

int main() {
    unsigned int first_array_size = 0;
    unsigned int second_array_size = 0;
    int element = 0;

    std::cin >> first_array_size >> second_array_size;

    Array<int> first(first_array_size);
    Array<int> second(second_array_size);

    for (unsigned int i = 0; i < first_array_size; ++i) {
        std::cin >> element;
        first.AddElement(element);
    }

    for (unsigned int i = 0; i < second_array_size; ++i) {
        std::cin >> element;
        second.AddElement(element);
    }

    for (unsigned int i = 0; i < second.GetSize(); ++i) {
        auto index = ExponentialSearch<int>(first, second[i]);

        if (index != first.GetSize()) {
            if (first[ExponentialSearch<int>(first, second[i])] == second[i]) {
                std::cout << second[i] << ' ';
            }
        }
    }

    return 0;
}
