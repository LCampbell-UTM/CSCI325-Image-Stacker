// Authors: Lane Campbell and Blaine Smith
// File: stacker.h
// Purpose: Implements the stacker class which reads multiple images and averages their pixels

#ifndef STACKER_H
#define STACKER_H

#include <string>
#include <vector>
#include "pixel.h"

/**
 * @class stacker
 * @brief Represents an image created by stacking multiple PPM images
 * and averaging their pixel values. Used to just stack. Removed image
 * class after I read the instructions again.
 */
class stacker
{
private:
    std::string magic_number;
    int width;
    int height;
    int max_color;

    std::vector<pixel> pixels;

public:

    stacker();

    /**
     * @brief Averages the pixels of all stored images.
     * @return The stacked image.
     */
    bool stack(const std::string& baseName, int numImages);

    /**
     * @brief Save this image to a P3 PPM file
     * @param filename File to save
     */
    void saveFile(const std::string& filename);
};

#endif
