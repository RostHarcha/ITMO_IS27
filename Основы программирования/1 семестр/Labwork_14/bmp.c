#pragma warning(disable : 4996)
#include <stdlib.h>
#include <stdio.h>
#include "bmp.h"

#define read_BYTE(dest, count, file) fread(dest, sizeof(BYTE), count, file)
#define read_WORD(dest, count, file) fread(dest, sizeof(WORD), count, file)
#define read_DWORD(dest, count, file) fread(dest, sizeof(DWORD), count, file)
#define read_LONG(dest, count, file) fread(dest, sizeof(LONG), count, file)

struct BITMAPFILEHEADER read_BITMAPFILEHEADER(FILE* file) {
    struct BITMAPFILEHEADER header;
    read_BYTE(header.bfType, 2, file);
    read_DWORD(&header.bfSize, 1, file);
    read_WORD(&header.bfReserved1, 1, file);
    read_WORD(&header.bfReserved2, 1, file);
    read_DWORD(&header.bfOffBits, 1, file);
    return header;
}

void print_BITMAPFILEHEADER(struct BITMAPFILEHEADER header) {
    printf("bfType %x%x\n", header.bfType[0], header.bfType[1]);
    printf("bfSize %ld\n", header.bfSize);
    printf("bfReserved1 %d\n", header.bfReserved1);
    printf("bfReserved2 %d\n", header.bfReserved2);
    printf("bfOffBits %ld\n", header.bfOffBits);
}

struct BITMAPINFOHEADER read_BITMAPINFOHEADER(FILE* file) {
    struct BITMAPINFOHEADER header;
    read_DWORD(&header.biSize, 1, file);
    read_LONG(&header.biWidth, 1, file);
    read_LONG(&header.biHeight, 1, file);
    read_WORD(&header.biPlanes, 1, file);
    read_WORD(&header.biBitCount, 1, file);
    read_DWORD(&header.biCompression, 1, file);
    read_DWORD(&header.biSizeImage, 1, file);
    read_LONG(&header.biXPelsPerMeter, 1, file);
    read_LONG(&header.biYPelsPerMeter, 1, file);
    read_DWORD(&header.biClrUsed, 1, file);
    read_DWORD(&header.biClrImportant, 1, file);
    return header;
}

void print_BITMAPINFOHEADER(struct BITMAPINFOHEADER header) {
    printf("biSize %ld\n", header.biSize);
    printf("biWidth %ld\n", header.biWidth);
    printf("biHeight %ld\n", header.biHeight);
    printf("biPlanes %d\n", header.biPlanes);
    printf("biBitCount %d\n", header.biBitCount);
    printf("biCompression %ld\n", header.biCompression);
    printf("biSizeImage %ld\n", header.biSizeImage);
    printf("biXPelsPerMeter %ld\n", header.biXPelsPerMeter);
    printf("biYPelsPerMeter %ld\n", header.biYPelsPerMeter);
    printf("biClrUsed %ld\n", header.biClrUsed);
    printf("biClrImportant %ld\n", header.biClrImportant);
}

void print_header(struct BMPImage image) {
    print_BITMAPFILEHEADER(image.header);
    print_BITMAPINFOHEADER(image.infoheader);
}

void print_data(struct BMPImage image) {
    for (int i = 0; i < image.infoheader.biHeight; ++i) {
        for (int j = 0, k = 0; j < image.infoheader.biWidth; ++j) {
            printf("%d ", image.data[i][j]);
        }
        printf("\n");
    }
}

struct BMPImage readBMP(char* filepath) {
    struct BMPImage image;
    image.filepath = filepath;
    FILE* file = fopen(filepath, "rb");
    image.header = read_BITMAPFILEHEADER(file);
    image.infoheader = read_BITMAPINFOHEADER(file);
    image.line_size = image.infoheader.biWidth * 3 + image.infoheader.biWidth % 4;
    image.image_size = image.infoheader.biSizeImage ? image.infoheader.biSizeImage : image.line_size * image.infoheader.biHeight;
    fseek(file, image.header.bfOffBits, SEEK_SET);
    image.data = (int**)calloc(image.infoheader.biHeight, sizeof(int*));
    for (int i = 0; i < image.infoheader.biHeight; ++i) {
        image.data[i] = (int*)calloc(image.infoheader.biWidth, sizeof(int));
        BYTE* buf = calloc(image.line_size, sizeof(BYTE));
        read_BYTE(buf, image.line_size, file);
        for (int j = 0, k = 0; j < image.line_size; j += 3) {
            if (j < image.infoheader.biWidth * 3) {
                image.data[i][k++] = buf[j] == 255 ? 0 : 1;
            }
        }
    }
    fclose(file);
    return image;
}

void dump(struct BMPImage* image, char* filepath, int** data) {
    FILE* original_file = fopen(image->filepath, "rb");
    FILE* dump_file = fopen(filepath, "wb");
    char* buf = (char*)calloc(image->header.bfOffBits, sizeof(BYTE));
    fread(buf, sizeof(BYTE), image->header.bfOffBits, original_file);
    fwrite(buf, sizeof(BYTE), image->header.bfOffBits, dump_file);
    for (int h = 0; h < image->infoheader.biHeight; ++h) {
        int w = 0;
        while (w < image->infoheader.biWidth) {
            BYTE buf_ = data[h][w] ? 0 : 255;
            fputc(buf_, dump_file);
            fputc(buf_, dump_file);
            fputc(buf_, dump_file);
            ++w;
        }
        w *= 3;
        while (w < image->line_size) {
            fputc(0, dump_file);
            ++w;
        }
    }
    fclose(original_file);
    fclose(dump_file);
}
