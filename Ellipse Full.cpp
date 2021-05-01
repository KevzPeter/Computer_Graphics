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
 putpixel(xc + x, yc + y, WHITE);
 while (dx < dy) {
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
 putpixel(x + xc, y + yc, WHITE);
 putpixel(-x + xc, y + yc, WHITE);
 putpixel(x + xc, -y + yc, WHITE);
 putpixel(-x + xc, -y + yc, WHITE);
 }
 d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y -
1))) - (rx * rx * ry * ry);
 while (y > 0)
 {
 if (d2 >= 0){
 y--;
 dy = dy - (2 * rx * rx);
 d2 = d2 + (rx * rx) - dy;
 }
 else{
 y--;
 x++;
 dx = dx + (2 * ry * ry);
 dy = dy - (2 * rx * rx);
 d2 = d2 + dx - dy + (rx * rx);
 }
 putpixel(x + xc, y + yc, WHITE);
 putpixel(-x + xc, y + yc, WHITE);
 putpixel(x + xc, -y + yc, WHITE);
 putpixel(-x + xc, -y + yc, WHITE);
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
