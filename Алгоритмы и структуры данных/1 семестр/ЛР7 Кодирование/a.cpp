#include <iostream>
#include <vector>

std::vector<std::vector<bool>> grays_code_next(std::vector<std::vector<bool>> current) {
    std::vector<std::vector<bool>> result;
    std::vector<bool> temp;
    for (int64_t i = 0; i < current.size(); ++i) {
        temp = {0};
        for (int64_t j = 0; j < current[i].size(); ++j) {
            temp.push_back(current[i][j]);
        }
        result.push_back(temp);
    }
    for (int64_t i = current.size() - 1; i >= 0; --i) {
        temp = {1};
        for (int64_t j = 0; j < current[i].size(); ++j) {
            temp.push_back(current[i][j]);
        }
        result.push_back(temp);
    }
    return result;
}

int main() {
    std::vector<std::vector<bool>> grays_code = {{0}, {1}};
    int64_t n;
    std::cin >> n;
    n -= 1;
    for (int64_t i = 0; i < n; ++i) {
        grays_code = grays_code_next(grays_code);
    }
    for (int64_t i = 0; i < grays_code.size(); ++i) {
        for (int64_t j = 0; j < grays_code[i].size(); ++j) {
            std::cout << grays_code[i][j];
        }
        std::cout << '\n';
    }
    return 0;
}