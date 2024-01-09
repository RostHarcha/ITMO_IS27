#include <stdio.h>
#include <math.h>

// Функция конвертирует градусы в радианы
double radians(double degrees) {
    return 0.0174532925 * degrees;
}

// Функция конвертирует радианы в градусы
double degrees(double radians) {
    return 57.2957795 * radians;
}

// Функция возвращает значение числа Пи в радианах
double pi() {
    return radians(90);
}

double z1(double alpha) {
    // Переводим угол в радианы
    alpha = radians(alpha);
    // Возвращаем результат вычислений
    return cos(alpha) + sin(alpha) + cos(3 * alpha) + sin(3 * alpha);
}

double z2(double alpha) {
    // Переводим угол в радианы
    alpha = radians(alpha);
    // Возвращаем результат вычислений
    return 2 * sqrt(2) * cos(alpha) * sin((pi() / 4) + 2 * alpha);
}

int main() {
    double alpha;
    printf("Enter alpha (in degrees): ");
    // Запрашиваем ввод угла из консоли
    scanf("%lf", &alpha);
    // Выводим результат функции z1
    printf("z1(alpha) = %lf\n", z1(alpha));
    // Выводим результат функции z2
    printf("z2(alpha) = %lf\n", z2(alpha));
    return 0;
}
