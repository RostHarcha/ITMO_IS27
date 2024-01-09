#include <stdio.h>
#include "square.h"

int main() {
    int Ax, Ay, length;
    printf("Enter coords and side linght of square (format: Ax Ay length): ");
    scanf("%d %d %d", &Ax, &Ay, &length);
    struct Square square = new_square(Ax, Ay, length);
    printf("Area: %d\nPerimeter: %d", area(square), perimeter(square));
}