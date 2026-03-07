// Authors: Lane Campbell and Blaine Smith
// File: stacker.cpp
// Last Modified: 2026-03-05
// Purpose: Implements the stacker class for combining images

#include "stacker.h"


/**
 * @brief Loads an image from a file and adds it to the list.
 * @param filename Name of the image file to load.
 */
void stacker::addImage(const std::string& filename)
{
    image img;
    if (img.loadFile(filename))
    {
        images.push_back(img);
    }
}


/**
 * @brief Averages the pixels of all stored images.
 * @return The stacked image.
 */
image stacker::stack()
{
    int width = images[0].getWidth();
    int height = images[0].getHeight();

    image result(width, height); // the final image that is filled with the averaged pixel values and returned at the end

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            //resets with every new pixel
            int r = 0;
            int g = 0;
            int b = 0;

            for (size_t i = 0; i < images.size(); i++) // error was here when declaring int i, changed it to size_t
            {
                const pixel& p = images[i].at(x, y);

                // sets the variables to the sum of all same-pixel values
                r += p.r;
                g += p.g;
                b += p.b;
            }

            // average and store in the result image
            result.at(x, y).r = r / images.size();
            result.at(x, y).g = g / images.size();
            result.at(x, y).b = b / images.size();
        }
    }

    return result; // return the final, averaged image
}