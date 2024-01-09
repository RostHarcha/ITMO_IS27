#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bmp.h"
#include "GameOfLife.h"

int main(int argc, char* argv[]) {
    struct BMPImage image;
    char* output_dir = "output/";
    int max_iter = -1;
    int dump_freq = 1;
    int image_initalized = 0;
    int output_initalized = 0;
    for (int i = 0; i < argc; ++i) {
        if (!strcmp("--input", argv[i])) {
            image = readBMP(argv[i + 1]);
            image_initalized = 1;
        }
        if (!strcmp("--output", argv[i])) {
            output_dir = argv[i + 1];
            mkdir(output_dir);
            output_initalized = 1;
        }
        if (!strcmp("--max_iter", argv[i])) {
            max_iter = strtol(argv[i + 1], 0, 10);
        }
        if (!strcmp("--dump_freq", argv[i])) {
            dump_freq = strtol(argv[i + 1], 0, 10);
        }
    }
    if (!image_initalized || !output_initalized) {
        printf("Usage: GameOfLife.exe --input [input .bmp file] --output [output directory] <--max_iter [num of iterations]> <--dump_freq [dump frequency]>");
        return 0;
    }
    struct GameOfLife game = GameOfLife(image.infoheader.biWidth, image.infoheader.biHeight, image.data);
    int current_iter = 0;
    char filepath[100];
    while (max_iter == -1 || current_iter < max_iter) {
        ++current_iter;
        tick(&game);
        if (current_iter % dump_freq == 0) {
            sprintf_s(filepath, 100, "%s%d.bmp", output_dir, current_iter);
            dump(&image, filepath, game.map);
        }
    }
    return 0;
}
