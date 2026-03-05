// Authors: Lane Campbell and Blaine Smith
// File: image.cpp
// Last Modified: 2026-03-05
// Purpose: Implement the image class for loading, saving, and manipulating images

#include "image.h"

image::image() : width(0), height(0), maxColor(255) {}

image::image(int width, int height)
{
    this->width = width;
    this->height = height;
    maxColor = 255;
    pixels.resize(width * height);
}

// getters
int image::getWidth() const 
{ 
    return width; 
}
int image::getHeight() const 
{ 
    return height; 
}
int image::getMaxColor() const 
{ 
    return maxColor; 
}

pixel& image::at(int x, int y) // modifiable
{
    return pixels[y * width + x]; // y * width gets us the right row, x selects the desired pixel in that row. has to multiply because its stored in a vector. so a new row will start every width number of pixels
}

const pixel& image::at(int x, int y) const // non-modifiable
{
    return pixels[y * width + x];
}

bool image::loadFile(const std::string& filename) 
{
    std::ifstream file(filename);
    if (!file) 
    {
        std::cout << "Error: Cannot open " << filename << std::endl; 
        return false; // "file bad"
    }

    std::string line;

    std::getline(file, line);

    while (std::getline(file, line)) 
    {
        if (line.empty() || line[0] == '#') continue;

        std::stringstream ss(line); //takes the line of text
        ss >> width >> height; // tries to get values from the text
        if (ss) break; // checks if that worked or not
    }

    file >> maxColor;

    pixels.resize(width * height);

    for (int i = 0; i < width * height; i++) 
    {
        int r, g, b; //create the integrs
        file >> r >> g >> b; // extraction operator to assign values to the integers
        pixels[i].r = r; // set the i-th pixels color values to those values
        pixels[i].g = g;
        pixels[i].b = b;
    }

    return true;
}

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