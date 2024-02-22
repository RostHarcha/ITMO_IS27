#include <stdlib.h>
#include <stdio.h>
#include "GameOfLife.h"

struct GameOfLife GameOfLife(int width, int height, int** map) {
    struct GameOfLife game;
    game.width = width;
    game.height = height;
    game.map = map;
    game.temp = (int**)calloc(height, sizeof(int*));
    for (int i = 0; i < height; ++i) {
        game.temp[i] = (int*)calloc(width, sizeof(int));
    }
    return game;
}

int on_map(int height, int width, int h, int w) {
    return 0 <= h && h < height && 0 <= w && w < width;
}

int count_neighbors(struct GameOfLife *game, int h, int w) {
    int count = 0;
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            if ((i == 0 && j == 0) || !on_map(game->height, game->width, h + i, w + j)) {
                continue;
            }
            count += game->map[h + i][w + j];
        }
    }
    return count;
}

void tick(struct GameOfLife* game) {
    for (int h = 0; h < game->height; ++h) {
        for (int w = 0; w < game->width; ++w) {
            int neighbors = count_neighbors(game, h, w);
            if (game->map[h][w]) {
                game->temp[h][w] = neighbors == 2 || neighbors == 3 ? 1 : 0;
            }
            else {
                game->temp[h][w] = neighbors == 3 ? 1 : 0;
            }
        }
    }
    for (int h = 0; h < game->height; ++h) {
        for (int w = 0; w < game->width; ++w) {
            game->map[h][w] = game->temp[h][w];
        }
    }
}
