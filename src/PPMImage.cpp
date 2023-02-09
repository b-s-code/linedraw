#include <iostream>
#include <vector>
#include <utility>
#include "coordrships.h"
#include "PPMImage.h"
#include <iostream>

PPMImage::PPMImage(int h, int w)
    : ImageHeight(h),
        ImageWidth(w),
        Image2DArray(std::vector<std::vector<std::vector<int>>>
        (h, std::vector<std::vector<int>> (w, BackgroundColour)))
{

}

const void PPMImage::PrintImage()
{
    // print PPM file header
    std::cout << MagicNumber << std::endl;
    std::cout << ImageWidth << " " << ImageHeight << std::endl;
    std::cout << MaxColor << std::endl;
    
    // print actual image data
    std::vector<int> CurrentPixel (3);
    for (int RowNum = 0; RowNum < ImageHeight; RowNum++)
    {  
        for (int ColNum = 0; ColNum < ImageWidth; ColNum++)
        {   
            CurrentPixel = Image2DArray.at(RowNum).at(ColNum);
            
            // RGB components of CurrentPixel
            for (int SubPixel = 0; SubPixel < 3; SubPixel++)
            {
                std::cout << CurrentPixel.at(SubPixel) << ' ';
            }
        }
        std::cout << std::endl;
    }
}

void PPMImage::AddPoint(int X, int Y)
{
    Image2DArray.at(ImageHeight - 1 - Y).at(X) = LineColour;
}

void PPMImage::AddLine(int X1, int Y1, int X2, int Y2)
{
    Rship rship = GetCoordRship(X1, Y1, X2, Y2, ImageWidth, ImageHeight);
    if (rship != Rship::outOfBounds)
    {
        switch (rship)
        {
            case Rship::overlapping:
                AddPoint(X1, Y1);
                break;
            case Rship::horizAligned:
                AddHorizLine(X1, Y1, X2, Y2);
                break;
            case Rship::vertAligned:
                AddVertLine(X1, Y1, X2, Y2);
                break;
            case Rship::upRight:
            case Rship::downLeft:
            case Rship::upLeft:
            case Rship::downRight:
                AddDiagonalLine(X1, Y1, X2, Y2);
                break;
            default:
                break;
        }
    }
}

void PPMImage::AddHorizLine(int X1, int Y1, int X2, int Y2)
{
    int Y = Y1;
    int xMin = X1 < X2 ? X1 : X2;
    int xMax = X1 < X2 ? X2 : X1;
    for (int i = xMin; i < xMax; i++)
    {
        Image2DArray.at(ImageHeight - 1 - Y).at(i) = LineColour;
    }
}

void PPMImage::AddVertLine(int X1, int Y1, int X2, int Y2)
{
    int X = X1;
    int yMin = Y1 < Y2 ? Y1 : Y2;
    int yMax = Y1 < Y2 ? Y2 : Y1;
    for (int j = yMin; j < yMax; j++)
    {
        Image2DArray.at(ImageHeight - 1 - j).at(X) = LineColour;
    }
}

/*
 * See
 * https://en.wikipedia.org/wiki/Digital_differential_analyzer_(graphics_algorithm)
 * */
void PPMImage::AddDiagonalLine(int X1, int Y1, int X2, int Y2)
{
    std::pair<int, int> lhsPoint = X1 < X2 ? std::make_pair(X1, Y1) : std::make_pair(X2, Y2);
    std::pair<int, int> rhsPoint = X1 < X2 ? std::make_pair(X2, Y2) : std::make_pair(X1, Y1);
    float dx = rhsPoint.first - lhsPoint.first;
    float dy = rhsPoint.second - lhsPoint.second;
    int step = abs(dx) > abs(dy) ?  abs(dx) : abs(dy);
    dx /= step;
    dy /= step;
    float x = lhsPoint.first;
    float y = lhsPoint.second;
    int i = 1;
    while (i <= step)
    {
        Image2DArray.at(ImageHeight - 1 - y).at(x) = LineColour;
        x += dx;
        y += dy;
        i++;
    }
}

const float PPMImage::YGivenX(int X1, int Y1, int X2, int Y2, int X)
{
    float DeltaY = Y2 - Y1;
    float DeltaX = X2 - X1;
    float Gradient = DeltaY / DeltaX;
    float YIntercept = Y1 - Gradient * X1;
    float Y = Gradient * X + YIntercept;
    return Y;
}
