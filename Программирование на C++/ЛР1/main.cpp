#include "labwork1.h"

// Увеличение значения одной переменной на заданную величину (вторая переменная).
void check_task_2() {
    double a = 3;
    double b = 4;

    increase(a, b);
    std::cout << a << '\n';

    increase(&a, &b);
    std::cout << a << '\n';
}

// Отбрасывает от вещественного числа его целую часть.
void check_task_5() {
    float a = 3.141592;

    fractional_only(a);
    std::cout << a << '\n';

    a = 3.141592;
    fractional_only(&a);
    std::cout << a << '\n';
}

// Меняет комплексную переменную (см. вар. 9) на комплексно сопряженную к ней.
void check_task_10() {
    Complex z(3.5, 2.7);

    complex_conjugate(z);
    std::cout << z << '\n';

    complex_conjugate(&z);
    std::cout << z << '\n';
}

// Передвигает квадрат на заданный вектор.
void check_task_13() {
    Square square(Point(3, 5), 1);
    Vector vector(-2, -1);
    
    move_square(square, vector);
    for (int i = 0; i < 4; ++i) {
        std::cout << "(" << square.points[i].x << ", " << square.points[i].y << ") ";
    }
    std::cout << '\n';
    
    vector = Vector(8, -3);
    move_square(&square, &vector);
    for (int i = 0; i < 4; ++i) {
        std::cout << "(" << square.points[i].x << ", " << square.points[i].y << ") ";
    }
}

int main() {
    check_task_2();
    std::cout << '\n';

    check_task_5();
    std::cout << '\n';

    check_task_10();
    std::cout << '\n';

    check_task_13();
    std::cout << '\n';

    return 0;
}
