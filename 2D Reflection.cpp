#include <stdio.h>
#include <graphics.h>
int graDriver = DETECT, graMode;
int n, xs[100], ys[100], i;
int tempYaxis, tempXaxis;

void DrawFn()
{
    for (i = 0; i < n; i++)
        line(xs[i], ys[i], xs[(i + 1) % n], ys[(i + 1) % n]);
}

void FlipV()
{
    tempXaxis = getmaxy() / 2;
    for (i = 0; i < n; i++)
        ys[i] = tempXaxis + (tempXaxis - ys[i]);

    for (i = 0; i < getmaxx(); i++)
        putpixel(i, tempXaxis, WHITE);
}

void FlipH()
{
    tempYaxis = getmaxx() / 2;
    for (i = 0; i < n; i++)
        xs[i] = tempYaxis + (tempYaxis - xs[i]);
    setcolor(WHITE);
    for (i = 0; i < getmaxy(); i++)
        putpixel(tempYaxis, i, WHITE);
}

int main(void)
{
    printf("Enter number of sides: ");
    scanf("%d", &n);
    printf("Enter coordinates: x,y for each point ");
    for (i = 0; i < n; i++)
        scanf("%d %d", &xs[i], &ys[i]);
    initgraph(&graDriver, &graMode, "C:\\TURBOC3\\BGI\\");
    setcolor(RED);
    DrawFn();
    FlipV();
    setcolor(BLUE);
    DrawFn();
    FlipH();
    setcolor(GREEN);
    DrawFn();
    getch();
}
