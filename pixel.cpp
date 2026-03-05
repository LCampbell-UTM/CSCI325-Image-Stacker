// Authors: Lane Campbell and Blaine Smith
// File: pixel.cpp
// Last Modified: 2026-03-05
// Purpose: Implement the pixel struct for representing individual pixels in the image

#include "pixel.h"

/**
 * @brief Constructs a pixel with zeroed RGB values by default
 * @param r Red component
 * @param g Green component
 * @param b Blue component
 */
pixel::pixel(int r, int g, int b) 
{
    // Initialize the pixels RGB values using this-> to tell the difference between member variables and parameters
    this->r = r; 
    this->g = g;
    this->b = b;
}

/**
 * @brief Add the RGB values of another pixel to this one
 * @param other Pixel to add
 */
void pixel::add(const pixel& other) 
{
    // Add the RGB values of the other pixel to this one
    r += other.r;
    g += other.g;
    b += other.b;
}

/**
 * @brief Divide the RGB values of this pixel by a given value
 * @param value The value to divide by
 */
void pixel::divide(int value) 
{
    // Divide the RGB values of this pixel by the given value
    r /= value;
    g /= value;
    b /= value;
}