#include <stdio.h>

// Объявляем перечисление месяцев
enum Month {
    JANUARY = 1, // Задаем начало отсчета с 1
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

// Структура описывает точку на плоскости
struct Coord {
    int x;
    int y;
};

// Стурктура описывает квадрат
struct Square {
    struct Coord A, B, C, D; // 4 точки квадрата
    int side_length; // Длина стороны квадрата
    int perimeter; // Периметр квадрата
};

// Функция для создания квадрата. Принимает координаты
// точки A (левая верхняя вершина) и длину стороны квадрата
struct Square new_square(int Ax, int Ay, int side_length) {
    struct Square square; // Объявляем квадрат
    square.side_length = side_length; // Задаём длину стороны
    square.perimeter = side_length * 4; // Вычисляем периметр
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

// Объяаляем объединение для принтера
union LaserPrinter {
    int a; // Тут хранятся данные
    // Структура позволяет обращаться к конкретрым битам (полям)
    struct {
        unsigned int ready : 1;
        unsigned int low_toner : 1;
        unsigned int drum_damaged: 1;
        unsigned int no_paper: 1;
    } status;
};

int main() {
    enum Month month = JULY; // Объявляем перечисление, задаем месяц июль
    printf("July is %d\n\n", month); // Выводим
    // Объявляем квадрат с точкой A(3, 5) и сторой 10
    struct Square square = new_square(3, 5, 10);
    printf("Perimeter of square is %d\n\n", square.perimeter); // Выводим квадрат
    // Объявляем объединение с индикаторами принтера
    union LaserPrinter laser_printer;
    laser_printer.a = 3; // Задаем статус 3 = 0011
    // Выводим в консоль состояние принтера
    printf("Laser printer:\n");
    printf("Ready: %d\n", laser_printer.status.ready);
    printf("Not enough toner: %d\n", laser_printer.status.low_toner);
    printf("The drum is damaged: %d\n", laser_printer.status.drum_damaged);
    printf("No paper: %d\n", laser_printer.status.no_paper);
    return 0;
}