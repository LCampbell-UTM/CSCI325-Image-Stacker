// Authors: Lane Campbell and Blaine Smith
// File: stacker.cpp
// Purpose: Implements the stacker class which reads multiple images and averages their pixels

#include "stacker.h"
#include <iostream>
#include <fstream>
#include <sstream>

/**
 * @brief Default constructor for the stacker class
 * Initializes the header values for the stacked image
 */
stacker::stacker()
{
    magic_number = "P3"; // had to add these, so image.cpp and image.h weren't needed
    width = 0;
    height = 0;
    max_color = 255;
}

/**
 * @brief Averages the pixels of all stored images.
 * @return The stacked image.
 */
bool stacker::stack(const std::string& baseName, int numImages)
{
    std::vector<int> rsum;
    std::vector<int> gsum;
    std::vector<int> bsum;

    for (int i = 1; i <= numImages; i++)
    {
        std::ostringstream filename;
        filename << baseName << "/" << baseName << "_";

        // adds the _### at the end of the filename
        if (i < 10) 
        {
            filename << "00" << i;
        }
        else if (i>= 10 && i < 100)
        {
            filename << "0" << i;
        }
        else
        {
            filename << i;
        }
        filename << ".ppm";

        // print the filename as it’s being processed
        std::cout << "     " << filename.str() << "\n";

        std::ifstream file(filename.str());

        if (!file)
        {
            std::cout << "Error: Cannot open " << filename.str() << std::endl;
            return false; 
        }

        std::string line;

        // read the first line 
        std::getline(file, line);

        if (i == 1)
        {
            magic_number = line; //stores "P3" if line is one. used later when writing the output file
        }

        // find the width and height
        while (std::getline(file, line))
        {
            if (line.empty() || line[0] == '#')
            {
                continue; // cant use break
            }

            std::stringstream ss(line);
            ss >> width >> height; // stores the width and height

            if (ss) // if it worked, break
            {
                break;
            }
        }

        // read the maximum color value
        file >> max_color;

        // get the necessary length
        int total = width * height;

        // initialize the sum vectors at the necessary length
        if (i == 1)
        {
            rsum.resize(total, 0);
            gsum.resize(total, 0);
            bsum.resize(total, 0);
        }

        // go through each pixel add pixel values to the totals
        for (int i = 0; i < total; i++)
        {
            int r = 0; // resets with every new pixel
            int g = 0;
            int b = 0;

            file >> r >> g >> b;

            rsum[i] += r;
            gsum[i] += g;
            bsum[i] += b;
        }
    }

    int total = width * height; // get necessary length

    pixels.resize(total); // resize to necessary lenth

    // set the i-th pixels values to the averages of the totals for the i-th image across all input images
    for (int i = 0; i < total; i++)
    {
        pixels[i].r = rsum[i] / numImages;
        pixels[i].g = gsum[i] / numImages;
        pixels[i].b = bsum[i] / numImages;
    }

    return true;
}

/**
 * @brief Save this image to a P3 PPM file
 * @param filename File to save
 */
void stacker::saveFile(const std::string& filename)
{
    std::ofstream file(filename);

    file << magic_number << "\n"; // "P3"
    file << width << " " << height << "\n";
    file << max_color << "\n";

    // write each pixel's color values
    for (size_t i = 0; i < pixels.size(); i++)
    {
        file << pixels[i].r << " "
             << pixels[i].g << " "
             << pixels[i].b << "\n";
    }
}
