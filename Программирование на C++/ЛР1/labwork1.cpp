#include <iostream>
#include "labwork1.h"

template <class T>
void increase(T& source, T& value) {
    source += value;
}

template <class T>
void increase(T* source, T* value) {
    *source += *value;
}

void fractional_only(float& source) {
    source -= (int)source;
}

void fractional_only(float* source) {
    *source -= (int)*source;
}

Complex::Complex(float re_, float im_) {
    re = re_;
    im = im_;
}

std::ostream& operator<<(std::ostream& os, const Complex& complex) {
    os << complex.re << (complex.im < 0 ? "" : "+") << complex.im << "i";
    return os;
}

void complex_conjugate(Complex &source) {
    source.im = -source.im;
}

void complex_conjugate(Complex *source) {
    source->im = -source->im;
}

Point::Point(float x_, float y_) {
    x = x_;
    y = y_;
}

Point::Point() {
    x = 0;
    y = 0;
}

Square::Square(Point a_point, float side_size) {
    points[0] = a_point;
    points[1] = Point(a_point.x + side_size, a_point.y);
    points[2] = Point(a_point.x + side_size, a_point.y + side_size);
    points[3] = Point(a_point.x, a_point.y + side_size);
}

Vector::Vector(float x_, float y_) {
    x = x_;
    y = y_;
}

void move_square(Square& square, Vector& vector) {
    for (int i = 0; i < 4; ++i) {
        square.points[i].x += vector.x;
        square.points[i].y += vector.y;
    }
}

void move_square(Square* square, Vector* vector) {
    for (int i = 0; i < 4; ++i) {
        square->points[i].x += vector->x;
        square->points[i].y += vector->y;
    }
}
