#include <iostream>
#include <random>

template<typename T>
void swap(T* a, T* b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

int rand_int_range(int from, int to) {
    return std::rand() % (to - from + 1) + from;
}

template<typename T>
int partition(T* array, int left, int right) {
    T pivot = array[rand_int_range(left, right)];
    int l = left;
    int r = right;
    while (l <= r) {
        while (array[l] < pivot) {
            ++l;
        }
        while (array[r] > pivot) {
            --r;
        }
        if (l >= r) {
            break;
        }
        swap<T>(&array[l++], &array[r--]);
    }
    return r;
}

template<typename T>
void quicksort(T* array, int left, int right) {
    if (left < right) {
        int middle = partition<T>(array, left, right);
        quicksort<T>(array, left, middle);
        quicksort<T>(array, middle + 1, right);
    }
}

int main() {
    int size;
    std::cin >> size;
    int32_t* array = new int32_t[size];
    for (int i = 0; i < size; ++i) {
        std::cin >> array[i];
    }
    quicksort<int32_t>(array, 0, size - 1);
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
    delete []array;
    return 0;
}