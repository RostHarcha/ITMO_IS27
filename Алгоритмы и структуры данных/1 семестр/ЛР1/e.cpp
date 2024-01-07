#include <iostream>

int main() {
    int len;
    std::cin >> len;
    char word[len];
    for (int i = 0; i < len; ++i) {
        std::cin >> word[i];
    }
    int left = 0;
    int right = len - 1;
    int mistakes = 0;
    while (left < right) {
        if (word[left] == word[right]) {
            ++left;
            --right;
        } else if (word[left + 1] == word[right]) {
            ++left;
        } else if (word[left] == word[right - 1]) {
            --right;
        } else  if (++mistakes > 1){
            std::cout << "NO";
            return 0;
        }
    }
    std::cout << "YES";
    return 0;
}