#include <iostream>
#include <vector>
#include "hull.h"

int main()
{
    Hull::Point p (0, 0);
    Hull::Point q (100, 100);
    Hull::Point r (200, 0);
    Hull::Point s (100, 50);
    
    std::vector<Hull::Point> points {p, q, r, s};
    std::vector<Hull::Edge> edges = Hull::GetConvexHull(points);

    for (Hull::Edge e : edges)
    {
        std::cout << e << std::endl;
    }
    return 0;
}
