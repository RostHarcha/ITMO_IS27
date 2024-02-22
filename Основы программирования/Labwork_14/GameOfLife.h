struct GameOfLife {
	int width;
	int height;
	int ticks_left;
	int** map;
	int** temp;
};

struct GameOfLife GameOfLife(int width, int height, int** map);

void tick(struct GameOfLife* game);
