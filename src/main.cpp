#include <iostream>
#include <vector>
#include <string>
#include "PPMImage.h"
#include "EdgeParser.h"

int main()
{



// //////////////// "TESTS" THAT ARE STILL FAILING //////////

//     // PPMImage TestFile(600,800);
//     // TestFile.AddPoint(60, 800); // still carks it w vector range exception at runtime


// // PPMImage TestFile(6,8);
// //     TestFile.AddLine(1,1,5,5); // ok but edges are strange
//     // finding this issue hard to give a shit about tbh

// /////////////////////////////////////////////////////////
    
// // something I have now considered:
// // if the canvas size is 5px by 5px
// // it actually doesn't make sense to accept both
// // AddLine(0,0,3,3)    // currently works
// // and
// // AddLine(3,3,5,5)    // currently doesn't work
// // at least one of these should be illegal
// // because otherwise, unless part of some legal line segment gets cropped out,
// // then the canvas would be 6px by 6xp (this is also an option but is less likeable).
// // At the moment both run (}:~D)


// // PPMImage TestFile(5,5);
// // TestFile.AddLine(0,0,3,3);
// // // and
// // // TestFile.AddLine(3,3,5,5);




// //     TestFile.PrintImage();









//     // complete graph, order 5
//     // it works now
//     PPMImage TestFile(500,500);
//     TestFile.AddLine(300,200,230,295);
//     TestFile.AddLine(300,200,120,258);
//     TestFile.AddLine(300,200,120,142);
//     TestFile.AddLine(300,200,230,105);
//     TestFile.AddLine(230,295,120,258);
//     TestFile.AddLine(230,295,120,142);
//     TestFile.AddLine(120,142,230,105);
//     TestFile.AddLine(230,295,230,105);
//     TestFile.AddLine(120,258,120,142);
//     TestFile.AddLine(120,258,230,105);
//     TestFile.PrintImage();




////////// above = from before pipe experiment ///////////

////////// below = from pipe experiment ///////////


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

