//
// Created by arugaf on 12.03.2020.
//

#include "static_array.h"

template <typename T>
std::pair<unsigned int, unsigned int> CalculateMaxPair(const Array<T>& first, const Array<T>& second) {
    unsigned int first_index = 0;
    unsigned int second_index = 0;
    unsigned int first_index_max = 0;

    for (unsigned int i = 0; i < second.GetSize(); ++i) {
        if (first[i] > first[first_index_max]) {
            first_index_max = i;
        }

        if (first[first_index_max] + second[i] > first[first_index] + second[second_index]) {
            first_index = first_index_max;
            second_index = i;
        }
    }

    return std::make_pair(first_index, second_index);
}

int main() {
    unsigned int array_size = 0;
    int element = 0;

    std::cin >> array_size;

    Array<int> first(array_size);
    Array<int> second(array_size);

    for (unsigned int i = 0; i < array_size; ++i) {
        std::cin >> element;
        first.AddElement(element);
    }

    for (unsigned int i = 0; i < array_size; ++i) {
        std::cin >> element;
        second.AddElement(element);
    }

    auto result = CalculateMaxPair<int>(first, second);

    std::cout << result.first << ' ' << result.second;

    return 0;
}
