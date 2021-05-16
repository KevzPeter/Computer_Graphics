#include <graphics.h>
#include <process.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <dos.h>
#define x 250
#define y 100
#define z 100
int arr[24];
void draw(int pts3[24]);
void cube(int pts1[16]);
int main(void)
{
    int gd = DETECT, gm, s, ch;
    void tran();
    void rot();
    void scale();
    initwindow(1000, 768);
    printf("Enter length of the cube:\n");
    scanf("%d", &s);
    arr[0] = x;
    arr[1] = y;
    arr[2] = z;
    arr[3] = x + s;
    arr[4] = y;
    arr[5] = z;
    arr[6] = x + s;
    arr[7] = y;
    arr[8] = z + s;
    arr[9] = x;
    arr[10] = y;
    arr[11] = z + s;
    arr[12] = x;
    arr[13] = y - s;
    arr[14] = z;
    arr[15] = x + s;
    arr[16] = y - s;
    arr[17] = z;
    arr[18] = x + s;
    arr[19] = y - s;
    arr[20] = z + s;
    arr[21] = x;
    arr[22] = y - s;
    arr[23] = z + s;
    draw(arr);
    getch();
    do
    {
        clearviewport();
        printf("3D Transformation\n");
        printf("Enter choice:\n");
        printf("1.translation\n");
        printf("2.rotation\n");
        printf("3.scaling\n");
        printf("4.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            draw(arr);
            tran();
            getch();
            break;
        case 2:
            draw(arr);
            rot();
            getch();
            break;
        case 3:
            draw(arr);
            scale();
            getch();
            break;
        case 4:
            break;
        default:
            printf("\n Wrong entry!!!");
            getch();
            break;
        }
    } while (ch != 4);
    closegraph();
}
void cube(int pts1[16])
{
    setcolor(15);
    setlinestyle(DOTTED_LINE, 1, 1);
    line(pts1[0], pts1[1], pts1[2], pts1[3]);
    delay(200);
    line(pts1[2], pts1[3], pts1[4], pts1[5]);
    delay(200);
    line(pts1[2], pts1[3], pts1[10], pts1[11]);
    delay(200);
    setlinestyle(SOLID_LINE, 1, 1);
    line(pts1[4], pts1[5], pts1[6], pts1[7]);
    delay(200);
    line(pts1[6], pts1[7], pts1[0], pts1[1]);
    delay(200);
    line(pts1[0], pts1[1], pts1[8], pts1[9]);
    delay(200);
    line(pts1[4], pts1[5], pts1[12], pts1[13]);
    delay(200);
    line(pts1[6], pts1[7], pts1[14], pts1[15]);
    delay(200);
    line(pts1[18], pts1[9], pts1[10], pts1[11]); //
    delay(200);
    setcolor(WHITE);
    line(pts1[10], pts1[11], pts1[12], pts1[13]);
    delay(200);
    line(pts1[12], pts1[13], pts1[14], pts1[15]);
    delay(200);
    line(pts1[8], pts1[9], pts1[14], pts1[15]);
    delay(200);
    setcolor(15);
}
void draw(int pts3[24])
{
    int pts2[16], i, j;
    float a1 = 3.14 * 60 / 180;
    float a2 = 3.14 * 60 / 180;
    for (i = 0, j = 0; i < 24, j < 16; i += 3, j += 2)
    {
        pts2[j] = pts3[i] + pts3[i + 2] * 1 / tan(a1) * cos(a2);
        pts2[j + 1] = pts3[i + 1] + pts3[i + 2] * 1 / tan(a1) * cos(a2);
    }
    cube(pts2);
}
void tran()
{
    int tr3[24];
    int i, tx, ty, tz;
    printf("\n Enter the translation vectors:");
    scanf("%d%d%d", &tx, &ty, &tz);
    for (i = 0; i < 24; i += 3)
    {
        tr3[i] = arr[i] + tx;
        tr3[i + 1] = arr[i + 1] + ty;
        tr3[i + 2] = arr[i + 2] + tz;
    }
    draw(tr3);
}
void rot()
{
    int r3[24];
    float deg, rad;
    int i, axis;
    printf("enter the angle:");
    scanf("%f", &deg);
    rad = 3.14 * deg / 180;
    printf("Enter 1: X-axis, 2: Y-axis, 3:Z-axis\n");
    scanf("%d", &axis);
    for (i = 0; i < 24; i += 3)
    {
        switch (axis)
        {
        case 1:
            r3[i] = arr[i];
            r3[i + 1] = arr[i + 1] * cos(rad) - arr[i + 2] * sin(rad);
            r3[i + 2] = arr[i + 1] * sin(rad) + arr[i + 2] * cos(rad);
            break;
        case 2:
            r3[i + 3] = arr[i + 1];
            r3[i] = arr[i + 2] * sin(rad) + arr[i] * cos(rad);
            r3[i + 2] = arr[i + 2] * cos(rad) - arr[i + 2] * sin(rad);
            break;
        case 3:
            r3[i] = arr[i] * cos(rad) - arr[i + 1] * sin(rad);
            r3[i + 1] = arr[i] * sin(rad) + arr[i + 1] * cos(rad);
            break;
        default:
            printf("\n Wrong Entry!!!");
            getch();
            break;
        }
    }
    draw(r3);
}
void scale()
{
    float sx, sy, sz;
    int i, s3[24];
    printf("\n Enter the scaling factor:");
    scanf("%f%f%f", &sx, &sy, &sz);
    for (i = 0; i < 24; i += 3)
    {
        s3[i] = arr[i] * sx;
        s3[i + 1] = arr[i + 1] * sy;
        s3[i + 2] = arr[i + 2] * sz;
    }
    draw(s3);
}
