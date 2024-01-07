#include <iostream>

void antiQSort(int* arr, int n) {
    for (int i = 2; i < n; i++) {
        int mid = i / 2;
        int buf = arr[mid];
        arr[mid] = arr[i];
        arr[i] = buf;
    }
}

int main() {
    int n;
    std::cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    antiQSort(arr, n);

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }
    
    delete []arr;

    return 0;
}