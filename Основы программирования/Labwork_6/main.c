#include <stdio.h>
#include <stdlib.h>

int main() {
    // Создаем массив
    float array0[4];
    // Объявляем указатель на массив
    float* pointer = array0;
    // Заполняем массив по индексам
    pointer[0] = 56.4f;
    pointer[1] = 36.5f;
    pointer[2] = 7.7f;
    pointer[3] = 44.3f;

    // Выводим массив через указатель
    for (int i = 0; i < 4; ++i) {
        printf("%d\t", i);
    }
    printf("\n");
    for (int i = 0; i < 4; ++i) {
        printf("%.2f\t", *(pointer + i));
    }
    printf("\n\n");

    // Создаем массив в дин. памяти
    float* array1 = (float*)malloc(4 * sizeof(float));
    // Заполняем массив по индексам
    array1[0] = 56.4f;
    array1[1] = 36.5f;
    array1[2] = 7.7f;
    array1[3] = 44.3f;
    // Выводим массив через указатель
    for (int i = 0; i < 4; ++i) {
        printf("%d\t", i);
    }
    printf("\n");
    for (int i = 0; i < 4; ++i) {
        printf("%.2f\t", *(array1 + i));
    }
    printf("\n");
    // Освобождаем память
    free(array1);
    return 0;
}