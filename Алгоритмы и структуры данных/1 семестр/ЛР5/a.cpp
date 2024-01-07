#include <iostream>

void bin_search(int64_t* toys, int64_t from_i, int64_t to_i) {
    if (from_i <= to_i) {
        int64_t mid_i = (from_i + to_i) / 2;
        std::cout << toys[mid_i] << ' ';
        bin_search(toys, from_i, mid_i - 1);
        bin_search(toys, mid_i + 1, to_i);
    }
}

int main() {
    int64_t toys_total;
    std::cin >> toys_total;
    int64_t* toys = new int64_t[toys_total];
    for (int64_t i = 0; i < toys_total; ++i) {
        std::cin >> toys[i];
    }
    bin_search(toys, 0, toys_total - 1);
    return 0;
}