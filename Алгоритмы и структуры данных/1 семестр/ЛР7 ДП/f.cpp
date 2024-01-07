#include <iostream>
#include <vector>

struct Solution {
    int64_t rows_total, cols_total;
    std::vector<std::vector<bool>> matrix;
    std::vector<std::vector<int64_t>> max_square;
    int64_t max_size = 0;
    int64_t max_row;
    int64_t max_col;

    int64_t min(int64_t a, int64_t b) {
        if (a < b) {
            return a;
        }
        return b;
    }

    int64_t get_max_square(int64_t row, int64_t col) {
        if (row >= rows_total || col >= cols_total) {
            return 0;
        }
        return max_square[row][col];
    }

    void solve() {
        for (int64_t row = rows_total - 1; row >= 0; --row) {
            for (int64_t col = cols_total - 1; col >= 0; --col) {
                if (matrix[row][col] == false) {
                    max_square[row][col] = 0;
                } else {
                    int64_t right = get_max_square(row, col + 1);
                    int64_t bottom = get_max_square(row + 1, col);
                    if (right == bottom) {
                        if (get_max_square(row + 1, col + 1) >= right) {
                            max_square[row][col] = right + 1;
                            if (max_size < max_square[row][col]) {
                                max_size = right + 1;
                                max_row = row;
                                max_col = col;
                            }
                        } else {
                            max_square[row][col] = right;
                        }
                    } else {
                        max_square[row][col] = min(right, bottom) + 1;
                    }
                }
            }
        }
    }
};

int main() {
    Solution solution;
    std::cin >> solution.rows_total >> solution.cols_total;
    solution.matrix = std::vector<std::vector<bool>>(solution.rows_total, std::vector<bool>(solution.cols_total));
    solution.max_square = std::vector<std::vector<int64_t>>(solution.rows_total, std::vector<int64_t>(solution.cols_total));
    for (int64_t r = 0; r < solution.rows_total; ++r) {
        for (int64_t c = 0; c < solution.cols_total; ++c) {
            char val;
            std::cin >> val;
            solution.matrix[r][c] = val == '5' ? true : false;
        }
    }
    solution.solve();
    std::cout << solution.max_size << ' ' << solution.max_row + 1 << ' ' << solution.max_col + 1;
    return 0;
}