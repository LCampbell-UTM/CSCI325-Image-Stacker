#ifndef STACKER_H
#define STACKER_H

#include "image.h"
#include <vector>
#include <string>

class stacker
{
private:
    std::vector<image> images;

public:
    void addImage(const std::string& filename);
    image stack();
};

#endif