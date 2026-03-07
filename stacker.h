// Authors: Lane Campbell and Blaine Smith
// File: pixel.cpp
// Last Modified: 2026-03-05
// Purpose: Define the stacker class used to combine multiple images by averaging their pixel values

#ifndef STACKER_H
#define STACKER_H

#include "image.h"
#include <vector>
#include <string>

/**
 * @class stacker
 * @brief Stores a group of images and combines them by averaging the RGB
 * values of the pixels at the same position.
 */
class stacker
{
private:
    std::vector<image> images; // vector to hold the images that will be stacked

public:

    /**
     * @brief Loads an image from a file and adds it to the list.
     * @param filename Name of the image file to load.
     */
    void addImage(const std::string& filename);

    /**
     * @brief Averages the pixels of all stored images.
     * @return The stacked image.
     */    
    image stack();
};

#endif