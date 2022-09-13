#include "EdgeParser.h"

std::vector<std::string> split(std::string s, char delimiter)
{
    std::vector<std::string> output = {};
    std::string segment = "";

    for (char workingCharacter : s)
    {
        if (workingCharacter == delimiter)
        {
            if (segment.empty())
            {
                // do nothing
                // no need to clutter the output vector with empty strings
            }
            else
            {
                output.push_back(segment);
                segment = "";
            }
        }
        else
        {
            segment += workingCharacter;
        }
    }

    // capture any final non-empty segment missed by the above for loop
    if (!segment.empty())
    {
        output.push_back(segment);
    }

    return output;
}

std::string filterChars(std::string s, std::string permittedChars)
{
    std::string output = "";
    for (char workingCharacter : s)
    {
        for (char permittedChar : permittedChars)
        {
            if (workingCharacter == permittedChar)
            {
                output += workingCharacter;
                break;
            }
        }
    }
    return output;
}

std::vector<int> parseLine(std::string line)
{
    std::vector<int> coordContainer = {};
    
    std::string lineCleaned = filterChars(line, "0123456789.,-");
    std::vector<std::string> coordsAsStrings = split(lineCleaned, ',');
    
    
    for (int i = 0; i < 4; i++)
    {
        coordContainer.push_back(stoi(coordsAsStrings[i]));
    }

    return coordContainer;
}