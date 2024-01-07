#include <iostream>

template<typename T>
void swap(T* a, T* b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

uint64_t rand_int_range(uint64_t from, uint64_t to) {
    return std::rand() % (to - from + 1) + from;
}

template<typename T>
uint64_t partition(T* array, uint64_t left, uint64_t right) {
    T pivot = array[rand_int_range(left, right)];
    uint64_t l = left;
    uint64_t r = right;
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
void quicksort(T* array, uint64_t left, uint64_t right) {
    if (left < right) {
        uint64_t middle = partition<T>(array, left, right);
        quicksort<T>(array, left, middle);
        quicksort<T>(array, middle + 1, right);
    }
}

int main() {
    uint64_t sticks_total;
    std::cin >> sticks_total;
    uint64_t* sticks = new uint64_t[sticks_total];
    for (uint64_t i = 0; i < sticks_total; ++i) {
        std::cin >> sticks[i];
    }
    quicksort(sticks, 0, sticks_total - 1);
    uint64_t temp;
    bool a = false;
    uint64_t answer = 0;
    for (int64_t i = sticks_total - 1; i >= 0; --i) {
        if (sticks[i] == sticks[i - 1] || sticks[i] - 1 == sticks[i - 1]) {
            if (a) {
                answer += temp * sticks[i - 1];
            }
            temp = sticks[i - 1];
            a = !a;
            --i;
        }
    }
    std::cout << answer;
    return 0;
}
