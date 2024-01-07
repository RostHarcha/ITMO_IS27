#include <iostream>

void sift_down(int64_t* heap, int64_t heap_size, int64_t i) {
    int64_t tmp;
    while (true) {
        int64_t left = 2 * i + 1;
        int64_t right = 2 * i + 2;
        if (left >= heap_size && right >= heap_size) {
            return;
        }
        if (left < heap_size && right < heap_size) {
            if (heap[left] >= heap[i] && heap[right] >= heap[i]) {
                return;
            }
            if (heap[right] < heap[left]) {
                tmp = heap[right];
                heap[right] = heap[i];
                heap[i] = tmp;
                i = right;
            } else {
                tmp = heap[left];
                heap[left] = heap[i];
                heap[i] = tmp;
                i = left;
            }
            continue;
        }
        if (left < heap_size) {
            if (heap[left] >= heap[i]) {
                return;
            }
            tmp = heap[left];
            heap[left] = heap[i];
            heap[i] = tmp;
            i = left;
            continue;
        }
        if (heap[right] >= heap[i]) {
            return;
        }
        tmp = heap[right];
        heap[right] = heap[i];
        heap[i] = tmp;
        i = right;
    }
}

void heap_sort(int64_t* heap, int64_t heap_size) {
    int64_t* temp = new int64_t[heap_size];
    for (int64_t i = 0; i < heap_size; ++i) {
        temp[i] = heap[0];
        heap[0] = heap[heap_size - i - 1];
        sift_down(heap, heap_size - i - 1, 0);
    }
    for (int64_t i = 0; i < heap_size; ++i) {
        heap[i] = temp[i];
    }
    delete[] temp;
}

void array_to_heap(int64_t* heap, int64_t heap_size) {
    for (int64_t i = heap_size - 1; i >= 0; --i) {
        sift_down(heap, heap_size, i);
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int64_t heap_size;
    std::cin >> heap_size;
    int64_t* heap = new int64_t[heap_size];
    for (int64_t i = 0; i < heap_size; ++i) {
        std::cin >> heap[i];
    }
    array_to_heap(heap, heap_size);
    heap_sort(heap, heap_size);
    for (int64_t i = 0; i < heap_size; ++i) {
        std::cout << heap[i] << ' ';
    }
    delete[] heap;
    return 0;
}
