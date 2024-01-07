#include <iostream>

int get_optimal_day() {
    int n_days;
    std::cin >> n_days;
    if (n_days < 2) {
        return 0;
    }
    int *days = new int[n_days];
    int left_sum = 0;
    int right_sum = 0;
    for (int day = 0; day < n_days; ++day) {
        std::cin >> days[day];
        right_sum += days[day];
    }
    right_sum -= days[0];
    for (int day = 0; day < n_days; ++day) {
        if (left_sum == right_sum) {
            return day;
        }
        left_sum += days[day];
        right_sum -= days[day + 1];
    }
    return -1;
}

int main() {
    std::cout << get_optimal_day();
    return 0;
}