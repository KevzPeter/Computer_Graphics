#include<stdio.h>
#include<graphics.h>
#include<conio.h>
void main()
{
 int gd=DETECT,gm;
 float p,x,y,xc,yc,a,b;
 initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
 cleardevice();
 printf("Enter xc, yc:\n");
 scanf("%f%f",&xc,&yc);
 printf("Enter a, b:\n");
 scanf("%f%f",&a,&b);
 x=0;
 y=b;
 //Region 1
 p=(b*b)-(a*a*b)+(0.25*a*a);
 do
 {
  putpixel(xc+x,yc+y,WHITE);
  putpixel(xc+x,yc-y,WHITE);
  putpixel(xc-x,yc+y,WHITE);
  putpixel(xc-x,yc-y,WHITE);
  if(p<0)
  {
   x=x+1;
   p=p+2*b*b*x+b*b;
  }
  else
  {
   x=x+1;
   y=y-1;
   p=p+2*b*b*x-2*a*a*y+b*b;
  }
 }while(2*b*b*x<2*a*a*y);

 getch();
 closegraph();
}