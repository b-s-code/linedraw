#ifndef COORDRSHIPS_H
#define COORDRSHIPS_H

enum class Rship
{
outOfBounds,
overlapping,
horizAligned,
vertAligned,
upRight,
upLeft,
downLeft,
downRight
};

bool XIsOutOfBounds(int X1, int X2, int W);

bool YIsOutOfBounds(int Y1, int Y2, int H);

bool OverlapOfSomeCoordExists(int X1, int Y1, int X2, int Y2);

Rship GetOverlapCase(int X1, int Y1, int X2, int Y2);

// return direction to point 2 from point 1, not the other way around
Rship GetDiagCase(int X1, int Y1, int X2, int Y2);

// returns relationship between (X1, Y1) and (X2, Y2)'s locations
// or outOfBounds if either point is outside the canvas
Rship GetCoordRship(int X1, int Y1, int X2, int Y2, int W, int H);

#endif // COORDRSHIP_H