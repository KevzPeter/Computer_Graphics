#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include<math.h>
#include<dos.h>
#include<string.h>
#include<iostream>
#include<ctime>

void EightWayPlot(int xc,int yc,int x,int y){
putpixel(x+xc,y+yc,RED);
putpixel(x+xc,-y+yc,YELLOW);
putpixel(-x+xc,-y+yc,GREEN);
putpixel(-x+xc,y+yc,YELLOW);
putpixel(y+xc,x+yc,12);
putpixel(y+xc,-x+yc,14);
putpixel(-y+xc,-x+yc,15);
putpixel(-y+xc,x+yc,6);
}
void Bresenham(int xc,int yc,int r)
{
int x=0,y=r,d=3-(2*r);
EightWayPlot(xc,yc,x,y);
while(x<=y){
if(d<=0){
d=d+(4*x)+6;
}
else{
d=d+(4*x)-(4*y)+10;
y=y-1;
}
x=x+1;
EightWayPlot(xc,yc,x,y);
}
}
int main(void){
int gdriver = DETECT, gmode, errorcode,xc,yc,r;
initgraph(&gdriver,&gmode,"d:\\tc\\bgi");
printf("enter coordinates of center:\n");
scanf("%d %d",&xc,&yc);
printf("enter radius of circle:\n");
scanf("%d",&r);
Bresenham(xc,yc,r);
getch();
closegraph();
return 0;
}
