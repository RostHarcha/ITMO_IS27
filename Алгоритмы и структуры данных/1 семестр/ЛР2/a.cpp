#include <iostream>

void insertion_sort(int* array, int size) {
    int temp, insert_to;
    for (int sorted = 0; sorted < size - 1; ++sorted) {
        if (array[sorted + 1] < array[sorted]) {
            temp = array[sorted + 1];
            for (insert_to = sorted; insert_to >= 0 && array[insert_to] > temp; --insert_to) {
                array[insert_to + 1] = array[insert_to];
            }
            array[insert_to + 1] = temp;
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    insertion_sort(arr, n);
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << ' ';
    }
    delete[] arr;
    return 0;
}