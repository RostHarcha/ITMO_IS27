#include <iostream>

void test(int &a) {
    std::cout << a;
}

int main() {
    int a = 4;
    test(a);
    return 0;
}