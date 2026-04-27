#include <stdio.h>
#include <math.h>

#define MAX 100

typedef struct
{
    int x, y;
    int visited;
} Point;

int distance(Point a, Point b)
{
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return (int)(sqrt(dx * dx + dy * dy));
}

void robotTour(Point points[], int n)
{
    int current = 0;
    points[current].visited = 1;
    int totalDistance = 0;

    printf("Tour: %d -> ", current);

    for (int step = 1; step < n; step++)
    {
        int minDist = 1000000;
        int next = -1;

        for (int i = 0; i < n; i++)
        {
            if (points[i].visited == 0)
            {
                int d = distance(points[current], points[i]);
                if (d < minDist)
                {
                    minDist = d;
                    next = i;
                }
            }
        }

        points[next].visited = 1;
        totalDistance += minDist;
        printf("%d -> ", next);
        current = next;
    }

    totalDistance += distance(points[current], points[0]);
    printf("0\n");
    printf("Total Distance: %d\n", totalDistance);
}

int main()
{
    Point points[] = {
        {0, 0, 0},
        {1, 2, 0},
        {4, 3, 0},
        {6, 1, 0},
        {3, 5, 0}};
    int n = sizeof(points) / sizeof(points[0]);

    robotTour(points, n);

    return 0;
}
