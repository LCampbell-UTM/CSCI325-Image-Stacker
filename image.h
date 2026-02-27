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
    private:
        int width;
        int height;
        int maxColor;
        std::vector<pixel> pixels;

    public:
        image();

        bool loadFile(const std::string& filename);
        void saveFile(const std::string& filename) const;

        int getWidth() const;
        int getHeight() const;
        int getMaxColor() const;

        pixel& at(int x, int y);
        const pixel& at(int x, int y) const;
};

#endif