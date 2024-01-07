#include <iostream>

#define INCOME_DAYS_TOTAL 32623

void set_income_days(uint64_t* array) {
    // min: 101
    // max: 1100 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111
    const uint64_t MIN_INCOME_DAY = 5;
    const int MAX_BITS = 60;

    array[0] = MIN_INCOME_DAY;
    int current_day = 1;

    uint64_t bits, days_in_group, day, add;
    for (bits = 4; bits <= MAX_BITS; ++bits) {
        for (days_in_group = bits - 2; days_in_group > 0; --days_in_group) {
            for (day = 0, add = 2; day < days_in_group && current_day < INCOME_DAYS_TOTAL; ++day, ++current_day) {
                array[current_day] = array[current_day - 1] + add;
                if (day != 0) {
                    add *= 2;
                } else if (days_in_group == bits - 2) {
                    array[current_day] += 2;
                }
            }
        }
    }
}

int get_num_of_income_days(uint64_t from_day, uint64_t to_day) {
    uint64_t income_days[INCOME_DAYS_TOTAL];
    set_income_days(income_days);
    int from = 0;
    while (income_days[from] < from_day) {
        ++from;
    }
    int to = INCOME_DAYS_TOTAL - 1;
    while (income_days[to] > to_day) {
        --to;
    }
    return to - from + 1;
}

int main() {
    uint64_t from_day, to_day;
    std::cin >> from_day >> to_day;
    std::cout << get_num_of_income_days(from_day, to_day);
    return 0;
}
