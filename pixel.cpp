#include "pixel.h"

 pixel::pixel(int r, int g, int b) 
{
    this->r = r;
    this->g = g;
    this->b = b;
}

void pixel::add(const pixel& other) 
{
    r += other.r;
    g += other.g;
    b += other.b;
}

void pixel::divide(int value) 
{
    r /= value;
    g /= value;
    b /= value;
}