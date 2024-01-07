#include <iostream>

bool is_pyramid(int64_t* array, int64_t array_size) {
    for (int64_t i = 1; i <= array_size; ++i) {
        if (2 * i <= array_size) {
            if (array[i] > array[2 * i]) {
                return false;
            }
        }
        if (2 * i + 1 <= array_size) {
            if (array[i] > array[2 * i + 1]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int64_t array_size;
    std::cin >> array_size;
    int64_t* array = new int64_t[array_size+1];
    for (int64_t i = 1; i <= array_size; ++i) {
        std::cin >> array[i];
    }
    if (is_pyramid(array, array_size)) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    delete[] array;
    return 0;
}