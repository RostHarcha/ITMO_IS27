#include <iostream>

struct Movie {
    uint64_t id;
    uint64_t rating;
};

int main() {
    uint64_t critics_total, movies_total, rating_size, rating;
    std::cin >> critics_total >> movies_total >> rating_size;
    uint64_t* prestige = new uint64_t[critics_total];
    for (uint64_t critic = 0; critic < critics_total; ++critic) {
        std::cin >> prestige[critic];
    }
    Movie* movies = new Movie[movies_total];
    for (uint64_t movie = 0; movie < movies_total; ++movie) {
        movies[movie].id = movie + 1;
        movies[movie].rating = 0;
        for (uint64_t critic = 0; critic < critics_total; ++critic) {
            std::cin >> rating;
            movies[movie].rating += rating * prestige[critic];
            movies[movie].rating %= 1000000007;
        }
    }
    for (uint64_t i = 0; i < movies_total; ++i) {
        for (uint64_t j = 0; j < movies_total; j++) {
            if (movies[i].rating >= movies[j].rating) {
                Movie tmp = movies[i];
                movies[i] = movies[j];
                movies[j] = tmp;
            }
        }
    }
    for (uint64_t i = 0; i < rating_size; ++i) {
        std::cout << movies[i].id << ' ';
    }
    delete []prestige;
    delete []movies;
    return 0;
}
