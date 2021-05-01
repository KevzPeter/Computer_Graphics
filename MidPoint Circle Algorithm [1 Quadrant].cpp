#include <stdio.h>
#include <conio.h>
#include <graphics.h>
void drawFirstQuad(int a, int b, int r)
{
    int x = 0;
    int y = r;
    int p = 1 - r;
    while (x < y)
    {
        if (p < 0)
            p += (2 * x) + 3;
        else
        {
            p += (2 * x) - (2 * y) + 5;
            y--;
        }
        x++;
        putpixel(a + x, b - y, WHITE); //first octant
        putpixel(a + y, b - x, RED);   //second octant
    }
    getch();
    closegraph();
}
void main()
{
    int gdriver = DETECT, gmode, error, a, b, r;
    initgraph(&gdriver, &gmode, "C:\\TURBOC3\\BGI");
    printf("Enter coordinates of center of circle:\n");
    scanf("%d %d", &a, &b);
    printf("Enter radius of circle:\n");
    scanf("%d", &r);
    drawFirstQuad(a, b, r);
}