#include "stacker.h"

void stacker::addImage(const std::string& filename)
{
    image img;
    if (img.loadFile(filename))
    {
        images.push_back(img);
    }
}

image stacker::stack()
{
    int width = images[0].getWidth();
    int height = images[0].getHeight();

    image result(width, height);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int r = 0;
            int g = 0;
            int b = 0;

            for (size_t i = 0; i < images.size(); i++) // error was here, changed in to size_t
            {
                const pixel& p = images[i].at(x, y);
                r += p.r;
                g += p.g;
                b += p.b;
            }

            result.at(x, y).r = r / images.size();
            result.at(x, y).g = g / images.size();
            result.at(x, y).b = b / images.size();
        }
    }

    return result;
}