// Authors: Lane Campbell and Blaine Smith
// File: main.cpp
// Purpose: Run the image stacking program

#include "stacker.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


/**
 * @brief Runs the image stacking program.
 * Prompts the user for the image base name and number of images,
 * loads them into the stacker, and outputs the stacked result.
 */
int main()
{
    std::string baseName;
    int numImages;


    // just  copying the format of the output from the assignment page
    // get baseName
    std::cout << "Please enter the image you wish to stack: "; 
    std::cin >> baseName;

    // get numImages
    std::cout << "Please enter the number of images: ";
    std::cin >> numImages;

    stacker s;

    std::cout << "Stacking images:\n";

    // perform the stacking
    if (s.stack(baseName, numImages))
    {
        std::string outputFile = baseName + ".ppm"; // output filename

        s.saveFile(outputFile); // save the stacked image

        std::cout << "\nStacking succeeded.\n";
        std::cout << "Output written to: " << outputFile << std::endl;
    }

    return 0;
}
