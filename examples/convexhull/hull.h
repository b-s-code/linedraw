#include <iostream>
#include <vector>
#include <utility>

namespace Hull
{
    using Point = std::pair<int, int>;
    
    class Edge
    {
    public:
        Edge(Point p, Point q) : p1(p), p2(q) { }

        /* 
        * Whole reason this class exists is so we can print edges.
        */
        friend std::ostream& operator<<(std::ostream& os, const Edge& e);

        /*
        * For testing purposes.
        * We say order of points (i.e. direction) doesn't matter for an Edge.
        * Edges might actually be better represented by an unordered_set of 2 endpoints.
        */
        constexpr bool operator==(const Edge& rhs)
        {
            bool sameWithOrderMatching = p1 == rhs.p1 && p2 == rhs.p2;
            bool sameWithOrderSwapped = p1 == rhs.p2 && p2 == rhs.p1;
            return sameWithOrderMatching || sameWithOrderSwapped;
        }

    private:
        Point p1, p2;
    };
    
    std::ostream& operator<<(std::ostream& os, const Edge& e)
    {
        os << e.p1.first << ',' << e.p1.second << ',' << e.p2.first << ',' << e.p2.second;
        return os;
    }

    std::vector<Edge> GetConvexHull(std::vector<Point> points)
    {
        /* bad, bad dummy functionality
            not a correct algorithm
            obviously makes test fail
            todo: actually implement a convex hull algo */
        std::vector<Edge> edges;
        for (auto p : points)
        {
            for (auto q : points)
            {
                edges.push_back(Edge(p, q));
            }
        }
        return edges;
    }
}
