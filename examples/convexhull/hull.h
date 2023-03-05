#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

namespace Hull
{
    using Point = std::pair<int, int>;
    using Vec2 = std::pair<int, int>;
    
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

    /*
    * returns whether r is to the lhs of pq
    * modulo computation errors
    */
    bool IsOnLHS(Point r, Point p, Point q)
    {
        int rx = r.first, ry = r.second,
            px = p.first, py = p.second,
            qx = q.first, qy = q.second;
    
        // use 2D cross-product
        return ((qx - px)*(ry - py) - (qy - py)*(rx - px)) > 0;
    }

    std::vector<Edge> GetConvexHull(std::vector<Point> points)
    {
        std::vector<Edge> edges;
        for (size_t i = 0; i < points.size(); i++)
        {
            for (size_t j = 0; j < points.size(); j++) // we must test, for example, both line AB and line BA
            {
                Point p = points.at(i), q = points.at(j);
                if (p.first == q.first && p.second == q.second)
                {
                    continue;
                }
                
                bool shouldIncludeEdge = true; // will try to falsify
                for (Point r : points)
                {
                    if (r == p || r == q)
                    {
                        continue;
                    }
                    else if (IsOnLHS(r, p, q))
                    {
                        shouldIncludeEdge = false;
                        break;
                    }
                }

                if (shouldIncludeEdge)
                {
                    edges.push_back(Edge(p, q));
                }
            }
        }
        return edges;
    }
}