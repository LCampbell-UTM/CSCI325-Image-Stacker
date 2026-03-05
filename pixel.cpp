// Authors: Lane Campbell and Blaine Smith
// File: pixel.cpp
// Last Modified: 2026-03-05
// Purpose: Implement the pixel struct for representing individual pixels in the image

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