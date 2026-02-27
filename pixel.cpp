#include "pixel.h"

pixel::pixel(int r, int g, int b) : r(r), g(g), b(b) {}

int pixel::getR() const { return r; }
int pixel::getG() const { return g; }
int pixel::getB() const { return b; }

void pixel::set(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
}

void pixel::add(const pixel& other) {
    r += other.r;
    g += other.g;
    b += other.b;
}

void pixel::divide(int value) {
    r /= value;
    g /= value;
    b /= value;
}