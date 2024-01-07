#include <iostream>

int get_answer(int a, int b) {
    if (a == b) {
        return a;
    }
    if (a < b) {
        int c = a;
        a = b;
        b = c;
    }
    // a > b
    // Тут алгоритм Евклида, хз как он работает но я перевел в код. Вот источник: https://skysmart.ru/articles/mathematic/naibolshij-obshchij-delitel
    while (1) {
        int c;
        c = a % b;
        if (c == 0) {
            return b;
        }
        a = b;
        b = c;
    }
}

int main() {
    int a, b;
    std::cin >> a >> b;
    std::cout << get_answer(a, b);
    return 0;
}