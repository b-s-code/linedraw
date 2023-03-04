#include <iostream>
#include <vector>
#include "hull.h"
#include <algorithm>

/*
* We don't care about order of elements, we just wish to see if they are
* "equivalent" in the sense of unordered_multisets.
*/
bool EdgeSetsMatch(std::vector<Hull::Edge>& es1, std::vector<Hull::Edge>& es2)
{
    return std::is_permutation(es1.begin(), es1.end(), es2.begin(), es2.end());
}
 
bool DummyTest() { return true; }

bool TestGetConvexHull_Basic()
{
    Hull::Point p (0, 0);
    Hull::Point q (100, 100);
    Hull::Point r (200, 0);
    Hull::Point s (100, 50); // just this point is interior to the hull
    
    std::vector<Hull::Point> points {p, q, r, s};
    std::vector<Hull::Edge> edges = Hull::GetConvexHull(points);
    
    std::vector<Hull::Edge> expected {
                                         Hull::Edge(p, q),
                                         Hull::Edge(q, r),
                                         Hull::Edge(r, s)
                                     };
    bool testPass = EdgeSetsMatch(edges, expected);
    return testPass;
}

int main()
{
    // run tests
    std::vector<bool> testResults {
                                     DummyTest(),
                                     TestGetConvexHull_Basic()
                                  };
    
    // display results
    int i = 0;
    for (bool res : testResults)
    {
        std::cout << "Test " << i++ << " : " << res << std::endl;
    }

    return 0;
}
