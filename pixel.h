#ifndef PIXEL_H
#define PIXEL_H

struct pixel
{
    int r;
    int g;
    int b;

    pixel(int r = 0, int g = 0, int b = 0);

    void add(const pixel& other);
    void divide(int value);
};

#endif