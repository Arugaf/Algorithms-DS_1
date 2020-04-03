//
// Created by arugaf on 03.04.2020.
//

#ifndef ALGORITHMS_DS_1_STAT_H
#define ALGORITHMS_DS_1_STAT_H

#include <functional>
#include <iostream>
#include <utility>

template<typename T>
class Stat {
public:
    explicit Stat(std::function<bool(const T &lhs, const T &rhs)> comparator = [](const T &lhs, const T &rhs) {
        return lhs < rhs;
    });
    ~Stat() = default;

    T FindStat(int array_size, int k, T *&array) const;

private:
    int FindPivot(T *&array, const int &left, const int &right) const;
    int Partition(T *&array, const int &left, const int &right) const;

    std::function<bool(const T &, const T &)> comparator;
};

template<typename T>
Stat<T>::Stat(std::function<bool(const T &, const T &)> comparator) : comparator(std::move(comparator)) {

}

template<typename T>
T Stat<T>::FindStat(const int array_size, const int k, T *&array) const {
    int left = 0;
    int right = array_size - 1;

    while (true) {
        int mid = Partition(array, left, right);

        if (mid == k) {
            return array[mid];
        } else if (k < mid) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
}

template<typename T>
int Stat<T>::FindPivot(T *&array, const int &left, const int &right) const {
    int mid = (left + right) / 2;

    if (array[mid] < array[left]) {
        if (array[left] < array[right]) {
            return left;
        }
        return (array[right] < array[mid]) ? mid : right;
    }

    if (array[mid] < array[right]) {
        return mid;
    }

    return (array[right] < array[left]) ? left : right;
}

template<typename T>
int Stat<T>::Partition(T *&array, const int &left, const int &right) const {
    int pivot = FindPivot(array, left, right);
    std::swap(array[pivot], array[left]);

    int i = right;
    for (int j = i; j > left;) {
        if (comparator(array[left], array[j])) {
            if (j != i) {
                std::swap(array[i], array[j]);
            }
            i--;
            j--;
        } else {
            j--;
        }
    }
    std::swap(array[left], array[i]);
    return i;
}

#endif //ALGORITHMS_DS_1_STAT_H
