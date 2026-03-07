// Authors: Lane Campbell and Blaine Smith
// File: image.cpp
// Last Modified: 2026-03-05
// Purpose: Implement the image class for loading, saving, and manipulating images

#include "image.h"

// constructors //////////////////////////////////////////////////////////
/**
 * @brief Default constructor initializes an empty image.
 */
image::image() : width(0), height(0), maxColor(255) {}

/**
 * @brief Construct an image with specified width and height.
 * @param width Image width
 * @param height Image height
 */
image::image(int width, int height)
{
    this->width = width;
    this->height = height;
    maxColor = 255;
    pixels.resize(width * height);
}

// getters ///////////////////////////////////////////////////
/**
 * @brief Get the width of the image.
 * @return Image width
 */
int image::getWidth() const 
{ 
    return width; 
}
/**
 * @brief Get the height of the image.
 * @return Image height
 */
int image::getHeight() const 
{ 
    return height; 
}
/**
 * @brief Get the maximum color value of the image.
 * @return Maximum color
 */
int image::getMaxColor() const 
{ 
    return maxColor; 
}

// pixel accessors //////////////////////////////////////////////////////////
/**
 * @brief Access a pixel for modification.
 * @param x X-coordinate
 * @param y Y-coordinate
 * @return Reference to the pixel at (x, y)
 */
pixel& image::at(int x, int y) // modifiable
{
    return pixels[y * width + x]; // y * width gets us the right row, x selects the desired pixel in that row. has to multiply because its stored in a vector. so a new row will start every width number of pixels
}

/**
 * @brief Access a pixel for reading only.
 * @param x X-coordinate
 * @param y Y-coordinate
 * @return Const reference to the pixel at (x, y)
 */
const pixel& image::at(int x, int y) const // non-modifiable
{
    return pixels[y * width + x];
}

/**
 * @brief Load a P3 PPM image file.
 * @param filename File to load
 * @return true if successful, false otherwise
 */
bool image::loadFile(const std::string& filename) 
{
    std::ifstream file(filename);
    if (!file) 
    {
        std::cout << "Error: Cannot open " << filename << std::endl; 
        return false; // "file bad"
    }

    std::string line;

    std::getline(file, line); // 

    while (std::getline(file, line)) 
    {
        if (line.empty() || line[0] == '#') continue;

        std::stringstream ss(line); //takes the line of text
        ss >> width >> height; // tries to get values from the text
        if (ss) break; // checks if that worked or not
    }

    file >> maxColor;

    pixels.resize(width * height); // sets the size of the vector to hold all the pixels

    for (int i = 0; i < width * height; i++) // loop through each pixel
    {
        int r, g, b; //create the integers
        file >> r >> g >> b; // extraction operator to assign values to the integers
        pixels[i].r = r; // set the i-th pixels color values to those values
        pixels[i].g = g;
        pixels[i].b = b;
    }

    return true;
}

/**
 * @brief Save this image to a P3 PPM file
 * @param filename File to save
 */
void image::saveFile(const std::string& filename) const 
{
    std::ofstream file(filename);

    file << "P3\n";
    file << width << " " << height << "\n";
    file << maxColor << "\n";

    for (const pixel& p : pixels) 
    {
        file << p.r << " " << p.g << " " << p.b << "\n"; // this should work. output wont look the same as here examples, but the file will work. it just prints each pixels color values on its own line. example shows four per line. not required from what i can tell.
    }
}