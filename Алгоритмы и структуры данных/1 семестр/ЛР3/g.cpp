#include <iostream>
#include <algorithm>

bool can(uint64_t* seats, uint64_t seats_total, uint64_t people_total, uint64_t distance) {
    uint64_t last_seat = seats[0];
    uint64_t count = 1;
    for (uint64_t seat = 0; seat < seats_total; ++seat) {
        if (last_seat + distance > seats[seat]) {
            continue;
        }
        ++count;
        last_seat = seats[seat];
    }
    return count >= people_total;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    uint64_t seats_total, people_total;
    std::cin >> seats_total >> people_total;
    uint64_t* seats = new uint64_t[seats_total];
    for (uint64_t i = 0; i < seats_total; ++i) {
        std::cin >> seats[i];
    }
    std::sort(&seats[0], &seats[seats_total - 1]);
    uint64_t l = 0;
    uint64_t r = seats[seats_total - 1] - seats[0] + 1;
    while (l + 1 < r) {
        uint64_t m = (l + r) / 2;
        if (can(seats, seats_total, people_total, m)) {
            l = m;
        } else {
            r = m;
        }
    }
    std::cout << l;
    delete[] seats;
    return 0;
}
