#include <stdio.h>

int main() {
    int number;
    // Вводим число
    printf("Enter number:");
    scanf("%d", &number);
    // Выводим результат проверки на попадание числа в диапазон 1 - 100
    // Используются только логические операторы
    printf("%d %s in range 1-100\n", number, (1 <= number) && (number <= 100) ? "is": "is not");
    
    // Вводим число
    printf("Enter number:");
    scanf("%d", &number);
    // Выводим 2-ой бит введенного числа
    printf("2nd bit of %d is %d", number, (number >> 2) & 1u);
    return 0;
}