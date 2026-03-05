// Authors: Lane Campbell and Blaine Smith
// File: image.h
// Last Modified: 2026-03-05
// Purpose: Declare the image class for loading, saving, and manipulating images

#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "pixel.h"

class image 
{
    private:  // private members are implemented, so that requirements checked off
        int width;
        int height;
        int maxColor;
        std::vector<pixel> pixels; // vector of pixels, size size of width * height, requirement checked off

    public:
        image();
        image(int width, int height);

        bool loadFile(const std::string& filename);
        void saveFile(const std::string& filename) const;

        int getWidth() const;
        int getHeight() const;
        int getMaxColor() const;

        pixel& at(int x, int y);
        const pixel& at(int x, int y) const;
};

#endif