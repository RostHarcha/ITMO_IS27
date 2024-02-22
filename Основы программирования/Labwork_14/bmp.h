#define BYTE unsigned char
#define WORD unsigned short
#define DWORD unsigned long
#define LONG long

struct BITMAPFILEHEADER {
    BYTE bfType[2];
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
};

struct BITMAPINFOHEADER {
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
};

struct BMPImage {
    char* filepath;
    struct BITMAPFILEHEADER header;
    struct BITMAPINFOHEADER infoheader;
    int line_size;
    int image_size;
    int** data;
};

struct BMPImage readBMP(char* filepath);

void print_data(struct BMPImage image);

void dump(struct BMPImage* image, char* filepath, int** data);
