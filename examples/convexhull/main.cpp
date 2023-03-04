#include <iostream>
#include <vector>
#include <utility>

class Edge
{
public:
    Edge(int x1, int y1, int x2, int y2)
    {
        p1 = std::make_pair(x1, y1);
        p2 = std::make_pair(x2, y2);
    }
    friend std::ostream& operator<<(std::ostream& os, const Edge& e);
private:
    std::pair<int, int> p1;
    std::pair<int, int> p2;
};

std::ostream& operator<<(std::ostream& os, const Edge& e)
{
    os << e.p1.first << ',' << e.p1.second << ',' << e.p2.first << ',' << e.p2.second;
    return os;
}

int main()
{
    std::vector<Edge> edges;

    Edge myDiagEdge = Edge(10,10,100,100);
    edges.push_back(myDiagEdge);
    edges.push_back(Edge(10,50,50,50));

    for (Edge e : edges)
    {
        std::cout << e << std::endl;
    }
    return 0;
}
