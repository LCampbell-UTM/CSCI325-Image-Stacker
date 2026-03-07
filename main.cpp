// Authors: Lane Campbell and Blaine Smith
// File: main.cpp
// Last Modified: 2026-03-05
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

    std::cout << "Please enter the image you wish to stack: "; // just  copying the format of the output from the assignment page
    std::cin >> baseName;

    std::cout << "Please enter the number of images: ";
    std::cin >> numImages;

    stacker s;

    std::cout << "Stacking images:\n";

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

        std::cout << "     " << filename.str() << "\n"; // gives the indentation

        s.addImage(filename.str()); // adds the image to the stacker
    }

    image result = s.stack(); // stores result as anew image

    std::string outputFile = baseName + ".ppm"; // names the cleaned file baseName.ppm
    result.saveFile(outputFile);

    std::cout << "\nStacking succeeded.\n";
    std::cout << "Output written to: " << outputFile << std::endl;

    return 0;
}