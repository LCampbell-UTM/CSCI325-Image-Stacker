// Authors: Lane Campbell and Blaine Smith
// File: image.h
// Last Modified: 2026-03-05
// Purpose: Implement the image class for loading, saving, and manipulating images

#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "pixel.h"

/**
 * @class image
 * @brief Meant to represent an image made up of pixels. An image can be loaded from a file, saved to a file, and manipulated by altering its pixel's values. An image is a 2D vector of x = width and y = height pixels, with a maximum color value of 255.
 */
class image 
{
    private:  // private members are implemented, so that requirements checked off

        // Image dimensions and maximum color value
        int width;
        int height;
        int maxColor;

        std::vector<pixel> pixels; // vector of pixels, size size of width * height, requirement checked off

    public:
        /**
         * @brief Default constructor initializes empty image.
         */
        image();

        /**
         * @brief Construct an image of given width and height.
         * @param width Width of image
         * @param height Height of image
         */
        image(int width, int height);

        /**
         * @brief Load a P3 PPM file into this image.
         * @param filename Name of the file to load
         * @return true if successful, false otherwise
         */
        bool loadFile(const std::string& filename);

        /**
         * @brief Save this image to a P3 PPM file.
         * @param filename Name of the file to save
         */
        void saveFile(const std::string& filename) const;

        /**
         * @brief Get image width.
         * @return Width
         */
        int getWidth() const;

        /**
         * @brief Get image height.
         * @return Height
         */
        int getHeight() const;

        /**
         * @brief Get maximum color value.
         * @return Max color
         */
        int getMaxColor() const;

        /**
         * @brief Access pixel at (x,y) for modification.
         * @param x X-coordinate
         * @param y Y-coordinate
         * @return Reference to pixel
         */
        pixel& at(int x, int y);

        /**
         * @brief Access pixel at (x,y) for reading.
         * @param x X-coordinate
         * @param y Y-coordinate
         * @return Const reference to pixel
         */
        const pixel& at(int x, int y) const;
};

#endif