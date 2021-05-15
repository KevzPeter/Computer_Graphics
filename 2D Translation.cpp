#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;

void translateRectangle(int P[][2], int T[])
{
    int gd = DETECT, gm, errorcode;
    initgraph(&gd, &gm, "c:\\tc\\bgi");
    setcolor(2);

    rectangle(P[0][0], P[0][1], P[1][0], P[1][1]);
    delay(2000);
    cleardevice();

    P[0][0] = P[0][0] + T[0];
    P[0][1] = P[0][1] + T[1];
    P[1][0] = P[1][0] + T[0];
    P[1][1] = P[1][1] + T[1];

    setcolor(WHITE);
    rectangle(P[0][0], P[0][1], P[1][0], P[1][1]);
    getch();
    closegraph();
}

int main()
{
    int x1, x2, y1, y2;
    printf("Enter coordinates of xmin,ymin,xmax,ymax:\n");
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    int P[2][2] = {x1, y1, x2, y2};
    int tx, ty;
    printf("Enter x and y translation factor:\n");
    scanf("%d %d", &tx, &ty);
    int T[] = {tx, ty};
    translateRectangle(P, T);
    return 0;
}
