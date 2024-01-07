#include <iostream>
#include <vector>

struct PriorityQueue {
    std::vector<int64_t> heap;
    
    bool empty() {
        return heap.empty();
    }

    void sift_up(int64_t i) {
        while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
            std::swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void sift_down(int64_t i) {
        while (true) {
            uint64_t left = 2 * i + 1;
            uint64_t right = 2 * i + 2;
            if (left >= heap.size()) {
                return;
            }
            if (right < heap.size()) {
                if (heap[left] >= heap[i] && heap[right] >= heap[i]) {
                    return;
                }
                if (heap[left] > heap[right]) {
                    std::swap(heap[i], heap[right]);
                    i = right;
                } else {
                    std::swap(heap[i], heap[left]);
                    i = left;
                }
                continue;
            }
            if (heap[left] >= heap[i]) {
                return;
            }
            if (heap[left] <= heap[i]) {
                std::swap(heap[i], heap[left]);
                i = left;
            }
        }
    }

    void push(int64_t x) {
        heap.push_back(x);
        sift_up(heap.size() - 1);
    }

    int64_t pop() {
        int64_t tmp = heap[0];
        std::swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        sift_down(0);
        return tmp;
    }

    void merge(PriorityQueue a, PriorityQueue b) {
        heap = a.heap;
        for (uint64_t i = 0; i < b.heap.size(); ++i) {
            push(b.heap[i]);
        }
    }

    void decrease_key(int64_t old, int64_t new_) {
        for (uint64_t i = 0; i < heap.size(); ++i) {
            if (heap[i] == old) {
                heap[i] = new_;
                sift_up(i);
                return;
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::vector<PriorityQueue> queues;
    std::string command;
    int64_t k, x, m, y;
    while (std::cin >> command) {
        if (command == "create") {
            queues.push_back(PriorityQueue());
            continue;
        }
        if (command == "insert") {
            std::cin >> k >> x;
            queues[k].push(x);
            continue;
        }
        if (command == "extract-min") {
            std::cin >> k;
            if (queues[k].empty()) {
                std::cout << "*\n";
            } else {
                std::cout << queues[k].pop() << '\n';
            }
            continue;
        }
        if (command == "merge") {
            std::cin >> k >> m;
            PriorityQueue queue;
            queue.merge(queues[k], queues[m]);
            queues.push_back(queue);
            continue;
        }
        if (command == "decrease-key") {
            std::cin >> k >> x >> y;
            queues[k].decrease_key(x, y);
            continue;
        }
    }
    return 0;
}
