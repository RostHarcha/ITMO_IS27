#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int number, new_number;
    
    // Запрашиваем ввод числа в 10-тичной системе счисления
    printf("Enter DEC number: ");
    scanf("%d", &number);

    // Выводим число в 8-ричной системе счисления
    printf("OCT %o\n\n", number);

    // Выводим число в 16-ричной системе счисления, 
    printf("HEX: %x\n", number);
    // затем в 16-ричной с побитовым сдвигом на 2 влево
    printf("HEX (with shift): %x\n\n", number << 2);

    // Выводим число в 16-ричной системе счисления, 
    printf("HEX: %x\n", number);
    // затем в 16-ричной с применением к нему битовой
    // битовой операции отрицания
    printf("HEX (with ~): %x\n\n", ~number);

    // Запрашиваем ввод числа в 16-ричной системе счисления
    printf("Enter HEX number: ");
    scanf("%x", &new_number);
    // Выводим в 16-ричной системе счисления результат
    // битовой операции ИЛИ двух введенных чисел
    printf("HEX: %x", number | new_number);

    return 0;
}