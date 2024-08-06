
#include <stdio.h>
#include <stdlib.h>

typedef struct point { int x, y; } Point;
typedef struct rect { Point pt1, pt2; } Rect;

Point makepoint(int x, int y)
{
    Point temp = { x, y };
    return temp;
}

int main(void)
{
    Rect screen;
    Point makepoint(int, int);

    screen.pt1 = makepoint(0, 0);
    screen.pt2 = makepoint(100, 100);

    Point middle = makepoint((screen.pt1.x + screen.pt2.x) / 2,
                             (screen.pt1.y + screen.pt2.y) / 2);

    printf("%d, %d\n", middle.x, middle.y);

    return EXIT_SUCCESS;
}
