#pragma once

#include <iostream>

template <class T>
void increase(T& source, T& value);

template <class T>
void increase(T* source, T* value);

void fractional_only(float& source);

void fractional_only(float* source);

struct Complex {
    float re;
    float im;

    Complex(float re_, float im_);
};

std::ostream& operator<<(std::ostream& os, const Complex& complex);

void complex_conjugate(Complex& source);

void complex_conjugate(Complex* source);

struct Point {
    float x;
    float y;

    Point();
    Point(float x_, float y_);
};

struct Square {
    Point points[4];

    Square(Point a_point, float side_size);
};

struct Vector {
    float x;
    float y;

    Vector(float x_, float y_);
};

void move_square(Square& square, Vector& vector);

void move_square(Square* square, Vector* vector);
