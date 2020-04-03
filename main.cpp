//
// Created by arugaf on 03.04.2020.
//

#include <iostream>
#include <cstring>

const int number_of_symbols = 256;
const int default_capacity = 10;

template <typename T>
class Vector {
 public:
    Vector();
    ~Vector();

    int GetArraySize();
    void PushBack(const T&);

    T& operator[](const int&);

 private:
    void Reallocate();

    T* array;
    int size;
    int capacity;
};

template <typename T> Vector<T>::Vector() : size(0), capacity(default_capacity) {
    array = new T[capacity];
}

template <typename T> Vector<T>::~Vector() {
    delete[] array;
}

template <typename T> int Vector<T>::GetArraySize() {
    return size;
}

template <typename T> void Vector<T>::Reallocate() {
    T* buf = new T[capacity * 2];
    for (int i = 0; i < capacity; i++) {
        buf[i] = array[i];
    }

    delete[] array;
    array = buf;

    capacity *= 2;
}

template <typename T> void Vector<T>::PushBack(const T& element) {
    array[size++] = element;

    if (size >= capacity) {
        Reallocate();
    }
}

template <typename T> T& Vector<T>::operator[](const int& index) {
    return array[index];
}

char** input(int *n) {
    Vector<char*> array;
    std::string input_str;

    while(std::cin >> input_str) {
        char *str = new char[input_str.length() + 1];
        strcpy(str, input_str.c_str());

        array.PushBack(str);
    }

    char** string = new char*[array.GetArraySize()];
    for (int i = 0; i < array.GetArraySize(); i++) {
        string[i] = array[i];
    }

    *n = array.GetArraySize();
    return string;
}

void counting_sort(char** arr, int n, int digit, int *counts) {
    for (int i = 0; i < number_of_symbols; i++) {
        counts[i] = 0;
    }

    for (int i = 0; i < n; ++i) {
        ++counts[arr[i][digit]];
    }

    int sum = 0;

    for (int i = 0; i < number_of_symbols; ++i) {
        int tmp = counts[i];
        counts[i] = sum;
        sum += tmp;
    }

    char** aux = new char*[n];

    for (int i = 0; i < n; ++i) {
        aux[counts[arr[i][digit]]] = arr[i];
        counts[arr[i][digit]]++;
    }

    memcpy(arr, aux, n * sizeof(char*));
}

void MSD_sort(char** arr, int n, int digit) {
    int buckets[number_of_symbols + 1];
    buckets[number_of_symbols] = n;

    counting_sort(arr, n, digit, buckets);

    for (int i = 0; i < number_of_symbols; ++i) {
        int bucket_size = buckets[i + 1] - buckets[i];
        if (bucket_size > 1) {
            MSD_sort(arr + buckets[i], bucket_size, digit + 1);
        }
    }
}

int main() {
    int n = 0;
    auto array = input(&n);

    MSD_sort(array, n, 0);

    for (int i = 0; i < n; i++) {
        std::cout << array[i] << std::endl;
    }
}
