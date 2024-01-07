#include <iostream>

int main() {
    int seasons_total, episodes_total, series_available;
    std::cin >> seasons_total >> episodes_total >> series_available;
    bool **available = new bool *[seasons_total];
    for (int season = 0; season < seasons_total; ++season) {
        available[season] = new bool[episodes_total];
        for (int episode = 0; episode < episodes_total; ++episode) {
            available[season][episode] = 0;
        }
    }
    int unique_series_available = 0;
    for (int i = 0, season, episode; i < series_available; ++i) {
        std::cin >> episode >> season;
        if (!available[--season][--episode]) {
            ++unique_series_available;
        }
        available[season][episode] = 1;
    }
    std::cout << seasons_total * episodes_total - unique_series_available << '\n';
    for (int season = 0; season < seasons_total; ++season) {
        for (int episode = 0; episode < episodes_total; ++episode) {
            if (!available[season][episode]) {
                std::cout << episode + 1 << ' ' << season + 1 << '\n';
            }
        }
    }
    return 0;
}