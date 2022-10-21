#include <iostream>
#include <vector>
#include <string>
#include "PPMImage.h"
#include "EdgeParser.h"

int main()
{
    // parse piped input
    std::vector<std::vector<int>> parsedLines = {};
    while (std::cin.peek() != EOF)
    {
        std::string line;
        std::getline(std::cin, line);
        std::vector<int> parsedLine = parseLine(line);
        parsedLines.push_back(parsedLine);
    }

    // actually make a PPM image now
    const int padding = 10; // pixels

    // determine required canvas dimensions from extreme x-values and y-values
    int Xmin = parsedLines.at(0).at(0);
    int Ymin = parsedLines.at(0).at(1);
    int Xmax = parsedLines.at(0).at(2);
    int Ymax = parsedLines.at(0).at(3);
    for (auto edge : parsedLines)
    {
        int X1 = edge.at(0);
        int Y1 = edge.at(1);
        int X2 = edge.at(2);
        int Y2 = edge.at(3);
        if (X1 < Xmin)
        {
            Xmin = X1;
        }
        else if (X1 > Xmax)
        {
            Xmax = X1;
        }
        if (X2 < Xmin)
        {
            Xmin = X2;
        }
        else if (X2 > Xmax)
        {
            Xmax = X2;
        }
        if (Y1 < Ymin)
        {
            Ymin = Y1;
        }
        else if (Y1 > Ymax)
        {
            Ymax = Y1;
        }
        if (Y2 < Ymin)
        {
            Ymin = Y2;
        }
        else if (Y2 > Ymax)
        {
            Ymax = Y2;
        }
    }

    int canvasWidth = Xmax - Xmin + 2 * padding;
    int canvasHeight = Ymax - Ymin + 2* padding;

    // translation to shift all points to the quadrant 1 of the 2D plane
    int translationX = -Xmin + padding;
    int translationY = -Ymin + padding;

    PPMImage myImage(canvasHeight, canvasWidth);
    for (auto edge: parsedLines)
    {
        int X1 = edge.at(0) + translationX;
        int Y1 = edge.at(1) + translationY;
        int X2 = edge.at(2) + translationX;
        int Y2 = edge.at(3) + translationY;
        myImage.AddLine(X1, Y1, X2, Y2);
    }
    myImage.PrintImage();


    return 0;
}
