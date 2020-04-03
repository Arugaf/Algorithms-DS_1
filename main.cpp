//
// Created by arugaf on 03.04.2020.
//

#include "Stat.h"

int main() {
    int array_size = 0;
    int k = 0;
    std::cin >> array_size >> k;

    auto array = new int[array_size];
    for (int i = 0; i < array_size; ++i) {
        std::cin >> array[i];
    }

    Stat<int> stat{};

    std::cout << stat.FindStat(array_size, k, array);

    delete[] array;
    return 0;
}
