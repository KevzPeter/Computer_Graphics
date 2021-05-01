#include <stdio.h>
#include <conio.h>
#include <graphics.h>
void ellipse(int xc, int yc, int rx, int ry)
{
    float dx, dy, d1, d2, x, y;
    x = 0;
    y = ry;
    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;
    //region 1
    while (dx < dy)
    {
        putpixel(xc + x, y + yc, WHITE);
        if (d1 < 0)
        {
            x++;
            dx = dx + (2 * ry * ry);
            d1 = d1 + dx + (ry * ry);
        }
        else
        {
            x++;
            y--;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);
    //region 2
    while (y > 0)
    {
        putpixel(xc + x, y + yc, WHITE);
        if (d2 >= 0)
        {
            y--;
            dy = dy - (2 * rx * rx);
            d2 = d2 + (rx * rx) - dy;
        }
        else
        {
            y--;
            x++;
            dx = dx + (2 * ry * ry);
            dy = dy - (2 * rx * rx);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
}
void main()
{
    int gm, gd = DETECT;
    int xc, yc, rx, ry;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    printf("Enter the center coordinates : ");
    scanf("%d%d", &xc, &yc);
    printf("Enter the major and minor axis : ");
    scanf("%d%d", &rx, &ry);
    ellipse(xc, yc, rx, ry);
    getch();
}
