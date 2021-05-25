#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>
#include<math.h>

void TriAngle(int x1, int y1, int x2, int y2, int x3, int y3);
void Rotate(int x1, int y1, int x2, int y2, int x3, int y3);

int main(void) {
   int gd = DETECT, gm;
   int x1, y1, x2, y2, x3, y3;
   initwindow(800,800);

   printf("Enter the 1st point for the triangle:");
   scanf("%d%d", &x1, &y1);
   printf("Enter the 2nd point for the triangle:");
   scanf("%d%d", &x2, &y2);
   printf("Enter the 3rd point for the triangle:");
   scanf("%d%d", &x3, &y3);
   TriAngle(x1, y1, x2, y2, x3, y3);
   getch();
   cleardevice();
   Rotate(x1, y1, x2, y2, x3, y3);
   setcolor(1);
   TriAngle(x1, y1, x2, y2, x3, y3);
   getch();
}

void TriAngle(int x1, int y1, int x2, int y2, int x3, int y3) {
   line(x1, y1, x2, y2);
   line(x2, y2, x3, y3);
   line(x3, y3, x1, y1);
}

void Rotate(int x1, int y1, int x2, int y2, int x3, int y3) {
   int x, y, a1, b1, a2, b2, a3, b3, p = x2, q = y2;
   float Angle;
   printf("Enter the angle for rotation:");
   scanf("%f", &Angle);
   cleardevice();
   Angle = (Angle * 3.14) / 180;
   a1 = p + (x1 - p) * cos(Angle)-(y1 - q) * sin(Angle);
   b1 = q + (x1 - p) * sin(Angle)+(y1 - q) * cos(Angle);
   a2 = p + (x2 - p) * cos(Angle)-(y2 - q) * sin(Angle);
   b2 = q + (x2 - p) * sin(Angle)+(y2 - q) * cos(Angle);
   a3 = p + (x3 - p) * cos(Angle)-(y3 - q) * sin(Angle);
   b3 = q + (x3 - p) * sin(Angle)+(y3 - q) * cos(Angle);
   printf("Rotate");
   TriAngle(a1, b1, a2, b2, a3, b3);
}
