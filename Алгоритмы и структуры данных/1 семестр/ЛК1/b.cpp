#include <iostream>
#include <vector>

struct Horse {
    uint64_t distanse;
    uint64_t speed;
};

double get_delta(std::vector<Horse> horses, double timedelta) {
    std::vector<double> distanses;
    for (uint64_t i = 0; i < horses.size(); ++i) {
        distanses.push_back(horses[i].speed * timedelta + horses[i].distanse);
    }
    double max = distanses[0];
    double min = distanses[0];
    for (uint64_t i = 0; i < horses.size(); ++i) {
        if (distanses[i] < min) {
            min = distanses[i];
        }
        if (distanses[i] > max) {
            max = distanses[i];
        }
    }
    return max - min;
}

int main() {
    uint64_t n;
    std::cin >> n;
    std::vector<Horse> horses;
    for (uint64_t i = 0, distanse, speed; i < n; ++i) {
        std::cin >> distanse >> speed;
        Horse horse = {distanse, speed};
        horses.push_back(horse);
    }
    double left = 0;
    double right = 10;
    double eps = 0.000001;
    while (right - left > eps) {
        double l_mid = (left * 2 + right) / 3;
        double r_mid = (left + right * 2) / 3;
        if (get_delta(horses, l_mid) < get_delta(horses, r_mid)) {
            right = r_mid;
        } else {
            left = l_mid;
        }
    }
    double timedelta = (left + right) / 2;
    std::cout << timedelta << ' ' << get_delta(horses, timedelta);
    return 0;
}