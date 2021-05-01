#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
void drawQuads(int a,int b,int r){
int x=0;
int y=r;
int p=1-r;
while(x<y){
if(p<0)
p+=(2*x)+3;
else{
p+=(2*x)-(2*y)+5;
y--;
}
x++;
putpixel(a+x,b+y,RED);
putpixel(a+y,b+x,RED);
putpixel(a-x,b+y,BLUE);
putpixel(a-y,b+x,BLUE);
putpixel(a-x,b-y,WHITE);
putpixel(a-y,b-x,WHITE);
delay(100);
}
getch();
closegraph();
}
void main(){
int gdriver=DETECT,gmode,error,a,b,r;
initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
printf("Enter coordinates of center of circle:\n");
scanf("%d %d",&a,&b);
printf("Enter radius of circle:\n");
scanf("%d",&r);
drawQuads(a,b,r);
}