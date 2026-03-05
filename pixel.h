// Authors: Lane Campbell and Blaine Smith
// File: pixel.cpp
// Last Modified: 2026-03-05
// Purpose: Implement the pixel struct for representing individual pixels in the image

#ifndef PIXEL_H
#define PIXEL_H

struct pixel // pixel struct, requirement checked off
{
    int r;
    int g;
    int b;

    pixel(int r = 0, int g = 0, int b = 0);

    void add(const pixel& other);
    void divide(int value);
};

#endif