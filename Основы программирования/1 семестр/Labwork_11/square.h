// Include Guard - если переменная SQUARE уже инициализирована - 
// тогда нижеописанный код компилировать не нужно
#ifndef SQUARE
#define SQUARE

// Структура описывает точку на плоскости
struct Coord {
    int x;
    int y;
};

// Стурктура описывает квадрат
struct Square {
    struct Coord A, B, C, D; // 4 точки квадрата
    int side_length; // Длина стороны квадрата
};

// Объявляем функции. Тела функций описаны в файле square.c
struct Square new_square(int Ax, int Ay, int side_length);
int perimeter(struct Square square);
int area(struct Square square);

#endif