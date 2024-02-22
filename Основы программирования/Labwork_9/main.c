#include <stdio.h>

void task_2() {
    // Создаем переменные и считываем их значения с консоли
    int calls_duration;
    float subscription_fee;
    float overlimit_fee;
    printf("Enter calls duration: ");
    scanf("%d", &calls_duration);
    printf("Enter subscription fee: ");
    scanf("%f", &subscription_fee);
    printf("Enter overlimit fee (per minute): ");
    scanf("%f", &overlimit_fee);
    // Высчитываем стоимость минуты по тарифу, если она превышет
    // стоимость минуты по повышенному тарифу - выводим ошибку
    // и рекурсивно запускаем эту же задачу
    if (overlimit_fee <= subscription_fee / 499) {
        printf("Overlimit fee (per minute) must be more than subscription fee (per minute). Try again\n\n");
        return task_2();
    }
    float total_fee;
    // Если расход <= 499 минут - платим только фиксу
    if (calls_duration <= 499) {
        total_fee = subscription_fee;
    } else {
        // Если расход больше 499 минут - платим фиксу + пов. тариф
        total_fee = subscription_fee + overlimit_fee * (calls_duration - 499);
    }
    // Выводим результат в консоль
    printf("Total fee is %.2f\n", total_fee);
}

void task_3() {
    // Создаем переменные и считываем их значения с консоли
    int num;
    char* number;
    printf("Enter number: ");
    scanf("%d", &num);
    // Проверяем введенное число конструкцией switch,
    // Записываем числительное в переменную number
    switch (num) {
        case 0:
            number = "Zero";
            break;
        case 1:
            number = "One";
            break;
        case 2:
            number = "Two";
            break;
        case 3:
            number = "Three";
            break;
        case 4:
            number = "Four";
            break;
        case 5:
            number = "Five";
            break;
        case 6:
            number = "Six";
            break;
        case 7:
            number = "Seven";
            break;
        case 8:
            number = "Eight";
            break;
        case 9:
            number = "Nine";
            break;
        default:
            // Если число не в промежутке [0, 9] - записывем ошибку
            number = "Not number or out of range";
            break;
    }
    // Выводим результат
    printf("%s", number);
}

int main() {
    task_2();
    task_3();
    return 0;
}