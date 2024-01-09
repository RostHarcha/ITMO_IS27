#include <stdio.h>
int main() {
    // Объявление целочисленной переменной
    int integer;
    // Вывод в консоль подсказки
    printf("Enter integer number:\n>>>");
    // Ввод целочисленного значения из консоли в переменную integer
    scanf("%d", &integer);
    // Вывод введенного целочисленного значения
    printf("integer = %d\n", integer);

    // Объявление переменной с числом с плавающей точкой
    float float_num;
    // Вывод в консоль подсказки
    printf("Enter floating point number:\n>>>");
    // Ввод числа с плавающей точкой из консоли в переменную float_num
    scanf("%f", &float_num);
    // Вывод введенного числа с плавающей точкой
    printf("float = %f\n", float_num);

    return 0;
}
