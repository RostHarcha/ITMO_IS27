#include <stdio.h>
#include "square.h" // Импортируем файл с описанием структуры и функций

int main() {
    int Ax, Ay, length; // Объявляем переменные
    printf("Enter coords and side linght of square (format: Ax Ay length): ");
    scanf("%d %d %d", &Ax, &Ay, &length); // Вводим параметры с консоли
    struct Square square = new_square(Ax, Ay, length); // Создаем квадрат
    // Выводим параметры квадрата в консоль
    printf("Area: %d\nPerimeter: %d", area(square), perimeter(square));
}