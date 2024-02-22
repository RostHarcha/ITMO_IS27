#include <stdio.h>
#include "string.h"

// Функция сравнивает две строки по первым n символам
int equal(char* s1, char* s2, int n) {
    // Для кажого символа 
    for (int i = 0; i < n; ++i) {
        if (s1[i] != s2[i]) {
            // Если s1[i] не совпадает s2[i] - то строки не равны
            return 0;
        }
    }
    // Если все символы от 0 до n равны - возвращаем 1
    return 1;
}

// Функция ищет первое вхождение символа в строке
int first_in(char* str, int str_size, char c) {
    for (int i = 0; i < str_size; ++i) {
        if (str[i] == c) {
            // Когда находим искомый символ - возвращаем его индекс
            return i;
        }
    }
    // При отсутствии символа в строке - возвращаем -1
    return -1;
}

// Функция ищет присутсвие каждого символа из s2 в s1
void search(char* s1, char* s2, int s2_len) {
    for (int i = 0; i < s2_len; ++i) {
        if (strchr(s1, s2[i])) {
            printf("Symbol %c found in string \"%s\"\n", s2[i], s1);
        }
    }
}

int main() {
    // Объявляем две строки
    char s1[100] = "hello";
    char s2[100] = " world";
    int n = 3;
    strncat(s1, s2, n); // Склеиваем первую строку и n первых символов из второй
    printf("%s\n", s1);

    // Объявляем две строки
    char s3[100] = "abcdef";
    char s4[100] = "abcdfeu";
    n = 4;
    // Сравниваем первые n символов
    printf("%s %s %s by first %d\n", s3, equal(s3, s4, n) ? "=" : "!=", s4, n);
    
    char s5[100];
    n = 2;
    strncpy(s5, s1, n); // Копируем первые n символов из s1 в s5
    printf("%s\n", s5);

    char symb = 'l';
    // Ищем первое вхождение символа symb в строке s1
    printf("First \'%c\' in \"%s\": %d\n", symb, s1, first_in(s1, 7, symb));

    // Ищем все символы из s4 в s3
    search(s3, s4, 6);
    return 0;
}