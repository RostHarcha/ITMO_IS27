#include "square.h"

// Функция для создания квадрата. Принимает координаты
// точки A (левая верхняя вершина) и длину стороны квадрата
struct Square new_square(int Ax, int Ay, int side_length) {
    struct Square square; // Объявляем квадрат
    square.side_length = side_length; // Задаём длину стороны
    // Вычисляем координаты вершин на плоскости
    square.A.x = Ax;
    square.A.y = Ay;
    square.B.x = Ax + side_length;
    square.B.y = Ay;
    square.C.x = Ax + side_length;
    square.C.y = Ay + side_length;
    square.D.x = Ax;
    square.D.y = Ay + side_length;
    return square; // Возвращаем описанный квадрат
}

// Фунция расчета периметра квадрата
int perimeter(struct Square square) {
    return square.side_length * 4;
}

// Функция расчета площади квадрата
int area(struct Square square) {
    return square.side_length * square.side_length;
}