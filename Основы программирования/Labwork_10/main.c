#include <stdio.h>
#include "stdlib.h"
#include <math.h>

struct Coord {
    float x;
    float y;
};

float** get_distances(struct Coord* points, int points_size) {
    float** result = (float**)malloc(points_size*sizeof(float *));
    for (int from = 0; from < points_size; ++from) {
        result[from] = (float*)malloc((points_size - 1)*sizeof(float));
        for (int to = 0; to < points_size; ++ to) {
            if (from == to) {
                continue;
            }
            result[from][to < from ? to : to - 1] = sqrtf(pow(points[to].x - points[from].x, 2) + pow(points[to].y - points[from].y, 2));
        }
    }
    return result;
}

void task_2() {
    const int n = 3;
    struct Coord coords[n];
    coords[0].x = 0;
    coords[0].y = 0;

    coords[1].x = 1;
    coords[1].y = 1;
    
    coords[2].x = 2;
    coords[2].y = 2;

    float** dist = get_distances(coords, n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            printf("%0.2f\t", dist[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
}

int* get_array(int num) {
    int* array = (int*)malloc(10 * sizeof(int));
    for (int j = 0; j < 10; ++j) {
        array[j] = 0;
    }
    int i = 0;
    while (num > 0) {
        array[9 - i++] = num % 10;
        num /= 10;
    }
    return array;
}

void task_3() {
    int num = 5678910;
    int* array = get_array(num);
    for (int i = 0; i < 10; ++i) {
        printf("%d\t", array[i]);
    }
}

int main() {
    task_2();
    task_3();
    return 0;
}