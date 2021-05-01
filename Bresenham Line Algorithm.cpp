#include <stdio.h>
#include <conio.h>
#include <graphics.h>
void draw_line(int x1, int x2, int y1, int y2)
{
    int incx = 1, incy = 1;
    int dx = x2 - x1;
    int dy = y2 - y1;
    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;
    if (x2 < x1)
        incx = -1;
    if (y2 < y1)
        incy = -1;
    int x = x1;
    int y = y1;
    if (dx > dy)
    {
        putpixel(x, y, RED);
        int e = 2 * dy - dx;
        for (int i = 0; i < dx; i++)
        {
            if (e >= 0)
            {
                y += incy;
                e += 2 * (dy - dx);
            }
            else
            {
                e += 2 * dy;
            }
            x += incx;
            putpixel(x, y, RED);
        }
    }
    else
    {
        putpixel(x, y, RED);
        int e = 2 * dx - dy;
        for (int i = 0; i < dy; i++)
        {
            if (e >= 0)
            {
                x += incx;
                e += 2 * (dx - dy);
                ;
            }
            else
                e += 2 * dx;
            y += incy;
            putpixel(x, y, RED);
        }
    }
}
void main()
{
    int gdriver = DETECT, gmode, error, x1, y1, x2, y2;
    initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
    printf("Enter co-ordinates of first point:\n");
    scanf("%d%d", &x1, &y1);
    printf("Enter co-ordinates of second point:\n");
    scanf("%d%d", &x2, &y2);
    drawline(x1, y1, x2, y2);
    getch();
    closegraph();
}