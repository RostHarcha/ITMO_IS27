#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: main.exe [path to file]");
        return 0;
    }
    char* filename = argv[1];
    FILE* file = fopen(filename, "r");
    char buffer[1024];
    int even = 0;
    if (file) {
        while ((fgets(buffer, 1024, file)) != NULL) {
            if (even) {
                printf("%s", buffer);
            }
            even = !even;
        }
        fclose(file);
    }

    return 0;
}