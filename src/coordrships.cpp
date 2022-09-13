#include "coordrships.h"

bool XIsOutOfBounds(int X1, int X2, int W)
{
    return (X1 < 0 || X2 < 0 || X1 > W || X2 > W);
}

bool YIsOutOfBounds(int Y1, int Y2, int H)
{
    return (Y1 < 0 || Y2 < 0 || Y1 > H || Y2 > H);
}

bool OverlapOfSomeCoordExists(int X1, int Y1, int X2, int Y2)
{
    return (X1 == X2 || Y1 == Y2);
} 

Rship GetOverlapCase(int X1, int Y1, int X2, int Y2)
{
    // both X and Y coords overlapping
    if (X1 == X2 && Y1 == Y2)
    {
        return Rship::overlapping;
    }
    
    // overlapping X coords only
    if (Y1 == Y2)
    {
        return Rship::horizAligned;
    }
    
    // overlapping Y coords only
    return Rship::vertAligned;
}

Rship GetDiagCase(int X1, int Y1, int X2, int Y2)
{
    if (Y2 > Y1)
    {
        if (X2 > X1)
        {
            return Rship::upRight;
        }
        return Rship::upLeft;
    }
    
    if (Y2 < Y1)
    {
        if (X2 < X1)
        {
            return Rship::downLeft;
        }
    }
    return Rship::downRight;
}

Rship GetCoordRship(int X1, int Y1, int X2, int Y2, int W, int H)
{
    // pathological cases
    if (XIsOutOfBounds(X1, X2, W) || YIsOutOfBounds(Y1, Y2, H))
    {
        return Rship::outOfBounds;
    }
    
    // the two points vert aligned/horiz aligned or overlap completely
    if (OverlapOfSomeCoordExists(X1, Y1, X2, Y2))
    {
        return GetOverlapCase(X1, Y1, X2, Y2);
    }
    
    // line between the two points is diagonal and within image bounds
    return GetDiagCase(X1, Y1, X2, Y2);
}
