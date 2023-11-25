#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Point
{
    int x, y;
};

Point findLowestPoint(const std::vector<Point> &points)
{
    Point lowest = points[0];
    for (const Point &p : points)
    {
        if (p.y < lowest.y || (p.y == lowest.y && p.x < lowest.x))
        {
            lowest = p;
        }
    }
    return lowest;
}

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

bool compare(Point p1, Point p2)
{
    int o = orientation(findLowestPoint({p1, p2}), p1, p2);
    if (o == 0)
        return (p1.x + p1.y < p2.x + p2.y);
    return (o == 2);
}

double distance(Point p1, Point p2)
{
    return std::sqrt(std::pow(p2.x - p1.x, 2) + std::pow(p2.y - p1.y, 2));
}

double giftWrapping(std::vector<Point> &points)
{
    std::vector<Point> convexHull;
    Point startPoint = findLowestPoint(points);
    convexHull.push_back(startPoint);

    do
    {
        Point current = convexHull.back();
        Point next = points[0];

        for (const Point &candidate : points)
        {
            if (current.x == candidate.x && current.y == candidate.y)
                continue;

            int o = orientation(current, next, candidate);
            if (next.x == current.x && next.y == current.y || o == 2 ||
                (o == 0 && distance(current, candidate) > distance(current, next)))
            {
                next = candidate;
            }
        }

        convexHull.push_back(next);

    } while (convexHull[0].x != convexHull.back().x || convexHull[0].y != convexHull.back().y);

    double perimeter = 0.0;
    for (size_t i = 0; i < convexHull.size() - 1; ++i)
    {
        perimeter += distance(convexHull[i], convexHull[i + 1]);
    }
    perimeter += distance(convexHull.back(), convexHull[0]);

    return perimeter;
}

using namespace std;

int main()
{
    int numReservas;
    cin >> numReservas;

    double perimetroTotal = 0.0;
    for (int i = 0; i < numReservas; ++i)
    {
        int numArvores;
        cin >> numArvores;

        vector<Point> pontos;
        for (int j = 0; j < numArvores; ++j)
        {
            Point ponto;
            cin >> ponto.x >> ponto.y;
            pontos.push_back(ponto);
        }

        perimetroTotal += giftWrapping(pontos);
    }

    cout << perimetroTotal << endl;

    return 0;
}
