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
int main(void)
{
    char ch;
    int gdriver = DETECT, gmode, errorcode,i;
    initgraph(&gdriver,&gmode,NULL);
    initwindow(800,800);
    setcolor(WHITE);
//    settextstyle(3, 0, 3);
//    outtextxy(200, 250, "Welcome to ISRO Rocket Launch Mission");
//    delay(2000);
//    cleardevice();
    outtextxy(240, 250, "Press 'Y' to start, 'N' to exit");
    ch = getch();
    if (ch == 'y' || ch=='Y')
    {
        cleardevice();
//        setbkcolor(BLACK);
//        setcolor(4);
//        settextstyle(0, 0, 10);
//        for( int i=3;i>0;i--){
//            char result[50];
//            sprintf(result, "%d", i);
//            outtextxy(260, 200,result);
//            delay(1000);
//            cleardevice();
//        }
//        settextstyle(0,0,8);
//        outtextxy(120, 200, "LIFT-OFF!");
//        delay(1000);
        for (i = 1; i <= 300; i++)
        {
                setfillstyle(1, 15);
                bar(280, 130 - i, 320, 300 - i);//rocket body
                setfillstyle(1, 8);
                bar(250, 190 - i, 280, 300 - i);//booster 1
                setfillstyle(1, 8);
                bar(320, 190 - i, 350, 300 - i);//booster 2
                //body cone
                setcolor(9);
                setfillstyle(6, 9);
                sector(300, 70 - i, 250, 290, 70, 70);
                //booster 1 cone
                setcolor(9);
                setfillstyle(6, 9);
                sector(265, 150 - i, 250, 290, 45, 45);
                //booster 2 cone
                setcolor(9);
                setfillstyle(6, 9);
                sector(335, 150 - i, 250, 290, 45, 45);
                //ISRO
                setcolor(WHITE);
                settextstyle(1,0,1);
                outtextxy(295, 180-i, "I");
                outtextxy(292, 210-i, "S");
                outtextxy(290, 240-i, "R");
                outtextxy(290, 270-i, "O");
                //moon
                setcolor(15);
                setfillstyle(1, 15);
                circle(650, 50, 20);
                floodfill(650, 50, 15);
                //body flames
                setcolor(14);
                setfillstyle(1, 14);
                circle(300, 333 - i, 33);
                floodfill(300, 333 - i, 14);
                setfillstyle(1, 14);
                circle(300, 370 - i, 25);
                floodfill(300, 370 - i, 14);
                setfillstyle(1, 14);
                circle(300, 400 - i, 15);
                floodfill(300, 400 - i, 14);
                //booster 1 flames
                setfillstyle(1, 14);
                circle(265, 320 - i, 20);
                floodfill(265, 320 - i, 14);
                setfillstyle(1, 14);
                circle(265, 345 - i, 12);
                floodfill(265, 345 - i, 14);
                setfillstyle(1, 14);
                circle(265, 360 - i, 8);
                floodfill(265, 360 - i, 14);
                //booster 2 flames
                setfillstyle(1, 14);
                circle(335, 320 - i, 20);
                floodfill(335, 320 - i, 14);
                setfillstyle(1, 14);
                circle(335, 345 - i, 12);
                floodfill(335, 345 - i, 14);
                setfillstyle(1, 14);
                circle(335, 360 - i, 8);
                floodfill(335, 360 - i, 14);
                setcolor(2);
                setfillstyle(1, 2);
                bar(0,400+i,800,800+i);
                setcolor(4);
                setfillstyle(1, 4);
                bar(210,200+i,225,400+i);
                delay(10);
                cleardevice();
            }
//            for(i=0;i<200;i++){
//                setcolor(BLUE);
//                  circle(150-i,300+i,400-i);
//                  circle(150-i,300+i,399-i);
//                  circle(150-i,300+i,398-i);
//                  circle(150-i,300+i,397-i);
//                  circle(150-i,300+i,396-i);
//                  circle(150-i,300+i,395-i);
//                  circle(150-i,300+i,394-i);
//                  circle(150-i,300+i,393-i);
//                  circle(150-i,300+i,392-i);
//                  circle(150-i,300+i,391-i);
//                  circle(150-i,300+i,390-i);
//                  circle(150-i,300+i,389-i);
//                  circle(150-i,300+i,388-i);
//                  setcolor(WHITE);
//                  //body
//                  line(320,250,440,130);
//                  line(340,270,460,150);
//                  line(320,250,340,270);
//                  line(440,130,460,150);
//                  //booster 1
//                  line(310,240,360,190);
//                  line(310,240,320,250);
//                  line(360,190,370,200);
//                  //booster 1
//                  line(350,280,400,230);
//                  line(350,280,340,270);
//                  line(400,230,390,220);
//                  //body flames
//                setcolor(14);
//                setfillstyle(1, 14);
//                circle(330, 260, 14);
//                floodfill(330, 260, 14);
////                setfillstyle(1, 14);
////                circle(300, 370, 25);
////                floodfill(300, 370, 14);
////                setfillstyle(1, 14);
////                circle(300, 400, 15);
////                floodfill(300, 400, 14);
//                  delay(20);
//                cleardevice();
//            }
        }
    else
    {
        cleardevice();
        setcolor(4);
        settextstyle(0, 0, 4);
        outtextxy(160, 200, "TRY AGAIN");
        delay(2000);
    }
    exit(0);
    getch();
    closegraph();
    return 0;
}
