#include <iostream>
#include <algorithm>

bool can(uint64_t* men, uint64_t* women, uint64_t amount, uint64_t episode, uint64_t coeff) {
    int64_t i_men = amount - 1;
    uint64_t count = 0;
    for (uint64_t i_women = 0; i_women < amount; ++i_women) {
        while (i_men >= 0 && women[i_women] + men[i_men] > coeff) {
            --i_men;
        }
        count += i_men + 1;
    }
    return count < episode;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    uint64_t amount, episode;
    std::cin >> amount >> episode;
    uint64_t* men = new uint64_t[amount];
    uint64_t* women = new uint64_t[amount];
    for (uint64_t i = 0; i < amount; ++i) {
        std::cin >> women[i];
    }
    for (uint64_t i = 0; i < amount; ++i) {
        std::cin >> men[i];
    }
    std::sort(men, men + amount);
    std::sort(women, women + amount);
    uint64_t l = men[0] + women[0];
    uint64_t r = men[amount - 1] + women[amount - 1];
    while (l + 1 < r) {
        uint64_t m = (l + r) / 2;
        if (can(men, women, amount, episode, m)) {
            l = m;
        } else {
            r = m;
        }
    }
    std::cout << r;
    delete[] men;
    delete[] women;
    return 0;
}
