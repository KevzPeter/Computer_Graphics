#include <stdio.h>
#include <graphics.h>
#include<conio.h>
#include <dos.h>
void drawline(int x0,int y0,int x1,int y1){
int dx,dy,p,x,y;
dx=x1-x0;
dy=y1-y0;
x=x0;
y=y0;
p=2*dy-dx;
while(x<x1){
if(p>=0){
for(int i=0;i<100;i++){
putpixel(x+i,y,BLUE);
putpixel(x+100+i,y,WHITE);
putpixel(x+200+i,y,RED);
}
y=y+1;
p=p+2*dy-2*dx;
}
else{
for(int i=0;i<100;i++){
putpixel(x+i,y,BLUE);
putpixel(x+100+i,y,WHITE);
putpixel(x+200+i,y,RED);
}
p=p+2*dy;}
x=x+1;
delay(25);
}
}
void main(){
int gdriver=DETECT,gmode,error,x0,y0,x1,y1;
initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
printf("Enter coordinates of first point:\n");
scanf("%d%d",&x0,&y0);
printf("Enter coordinates of second point:\n");
scanf("%d%d",&x1,&y1);
drawline(x0,y0,x1,y1);
getch();
closegraph();
}