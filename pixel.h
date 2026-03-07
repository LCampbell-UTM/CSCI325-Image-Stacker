// Authors: Lane Campbell and Blaine Smith
// File: pixel.cpp
// Last Modified: 2026-03-05
// Purpose: Implement the pixel struct for representing individual pixels in the image

#ifndef PIXEL_H
#define PIXEL_H

/**
 * @struct pixel
 * @brief Represents a single pixel with red, green, and blue components
 */
struct pixel // Pixel struct, requirement checked off
{
    // RGB values for the pixel
    int r;
    int g;
    int b;

    /**
     * @brief Constructs a pixel with zeroed RGB values by default
     * @param r Red component
     * @param g Green component
     * @param b Blue component
     */
    pixel(int r = 0, int g = 0, int b = 0);

    /**
     * @brief Add the RGB values of another pixel to this one
     * @param other Pixel to add
     */
    void add(const pixel& other);

    /**
     * @brief Divide the RGB values of this pixel by a given value
     * @param value The value to divide by
     */
    void divide(int value);
};

#endif
