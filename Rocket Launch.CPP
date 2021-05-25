#include <graphics.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <dos.h>
#include <string.h>
#include <iostream>
#include <ctime>
void draw_line(int x1, int y1, int x2, int y2) //bresenham line drawing algorithm
{
    int incx = 1, incy = 1;
    int dx = x2 - x1;
    int dy = y2 - y1;
    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;
    if (x2 < x1)
        incx = -1;
    if (y2 < y1)
        incy = -1;
    int x = x1;
    int y = y1;
    if (dx > dy)
    {
        putpixel(x, y, RED);
        int e = 2 * dy - dx;
        for (int i = 0; i < dx; i++)
        {
            if (e >= 0)
            {
                y += incy;
                e += 2 * (dy - dx);
            }
            else
            {
                e += 2 * dy;
            }
            x += incx;
            putpixel(x, y, RED);
        }
    }
    else
    {
        putpixel(x, y, RED);
        int e = 2 * dx - dy;
        for (int i = 0; i < dy; i++)
        {
            if (e >= 0)
            {
                x += incx;
                e += 2 * (dx - dy);
                ;
            }
            else
                e += 2 * dx;
            y += incy;
            putpixel(x, y, RED);
        }
    }
}
void EightWayPlot(int xc, int yc, int x, int y)
{
    putpixel(x + xc, y + yc, RED);
    putpixel(x + xc, -y + yc, YELLOW);
    putpixel(-x + xc, -y + yc, GREEN);
    putpixel(-x + xc, y + yc, YELLOW);
    putpixel(y + xc, x + yc, 12);
    putpixel(y + xc, -x + yc, 14);
    putpixel(-y + xc, -x + yc, 15);
    putpixel(-y + xc, x + yc, 6);
}
void draw_circle(int xc, int yc, int r) //bresenham circle drawing algorithm
{
    int x = 0, y = r, d = 3 - (2 * r);
    EightWayPlot(xc, yc, x, y);
    while (x <= y)
    {
        if (d <= 0)
        {
            d = d + (4 * x) + 6;
        }
        else
        {
            d = d + (4 * x) - (4 * y) + 10;
            y = y - 1;
        }
        x = x + 1;
        EightWayPlot(xc, yc, x, y);
    }
}
int main(void)
{
    char ch;
    int gdriver = DETECT, gmode, errorcode, i;
    initgraph(&gdriver, &gmode, NULL);
    initwindow(800, 800);
    setcolor(WHITE);
    settextstyle(3, 0, 3);
    outtextxy(200, 250, "Welcome to ISRO Rocket Launch Mission");
    delay(2000);
    cleardevice();
    outtextxy(240, 250, "Press 'Y' to start, 'N' to exit");
    ch = getch();
    if (ch == 'y' || ch == 'Y')
    {
        setbkcolor(BLACK);
        cleardevice();
        setcolor(4);
        settextstyle(10, 0, 8);
        for (int i = 10; i > 0; i--)
        {
            char result[50];
            sprintf(result, "T - %d", i);
            outtextxy(260, 200, result);
            delay(1000);
            cleardevice();
        }
        settextstyle(0, 0, 8);
        outtextxy(120, 200, "LIFT-OFF!");
        delay(1000);
        setbkcolor(BLUE);
        cleardevice();
        ////******************LAUNCH***************
        for (i = 1; i <= 300; i++)
        {
            //rocket body
            setcolor(15);
            setfillstyle(1, 15);
            draw_line(280, 130 - i, 320, 130 - i);
            draw_line(320, 130 - i, 320, 300 - i);
            draw_line(320, 300 - i, 280, 300 - i);
            draw_line(280, 300 - i, 280, 130 - i);
            floodfill(281, 131 - i, 15);
            //booster 1
            setcolor(8);
            setfillstyle(1, 8);
            draw_line(250, 190 - i, 280, 190 - i);
            draw_line(280, 190 - i, 280, 300 - i);
            draw_line(280, 300 - i, 250, 300 - i);
            draw_line(250, 300 - i, 250, 190 - i);
            floodfill(251, 191 - i, 8);
            //booster 2
            draw_line(320, 190 - i, 350, 190 - i);
            draw_line(350, 190 - i, 350, 300 - i);
            draw_line(350, 300 - i, 320, 300 - i);
            draw_line(320, 300 - i, 320, 190 - i);
            floodfill(321, 191 - i, 8);
            // body cone
            setcolor(9);
            setfillstyle(6, 9);
            sector(300, 70 - i, 250, 290, 65, 65);
            // booster 1 cone
            sector(265, 150 - i, 250, 290, 45, 45);
            // booster 2 cone
            sector(335, 150 - i, 250, 290, 45, 45);
            //ISRO
            setcolor(WHITE);
            settextstyle(1, 0, 1);
            outtextxy(295, 180 - i, "I");
            outtextxy(292, 210 - i, "S");
            outtextxy(290, 240 - i, "R");
            outtextxy(290, 270 - i, "O");
            // moon
            setcolor(15);
            setfillstyle(1, 15);
            draw_circle(650, 50, 20);
            floodfill(650, 50, 15);
            //body flames
            setcolor(14);
            setfillstyle(1, 14);
            draw_circle(300, 323 - i, 33);
            floodfill(300, 323 - i, 14);
            draw_circle(300, 360 - i, 25);
            floodfill(300, 360 - i, 14);
            draw_circle(300, 390 - i, 15);
            floodfill(300, 390 - i, 14);
            //booster 1 flames
            draw_circle(265, 310 - i, 20);
            floodfill(265, 310 - i, 14);
            draw_circle(265, 335 - i, 12);
            floodfill(265, 335 - i, 14);
            draw_circle(265, 350 - i, 8);
            floodfill(265, 350 - i, 14);
            //booster 2 flames
            draw_circle(335, 310 - i, 20);
            floodfill(335, 310 - i, 14);
            draw_circle(335, 335 - i, 12);
            floodfill(335, 335 - i, 14);
            draw_circle(335, 350 - i, 8);
            floodfill(335, 350 - i, 14);
            //ground
            setcolor(2);
            setfillstyle(1, 2);
            draw_line(0, 400 + i, 800, 400 + i);
            draw_line(800, 400 + i, 800, 800 + i);
            draw_line(800, 800 + i, 0, 800 + i);
            draw_line(0, 800 + i, 0, 400 + i);
            floodfill(1, 401 + i, 2);
            //rocket support
            setcolor(4);
            setfillstyle(1, 4);
            draw_line(210, 200 + i, 225, 200 + i);
            draw_line(225, 200 + i, 225, 400 + i);
            draw_line(225, 400 + i, 210, 400 + i);
            draw_line(210, 400 + i, 210, 200 + i);
            floodfill(211, 201 + i, 4);
            delay(10);
            cleardevice();
        }
        ////*******************DEPLOY******************
        setbkcolor(BLACK);
        cleardevice();
        for (int i = 0; i < 300; i++)
        {
            setfillstyle(1, 15);
            bar(280, 130, 320, 300); //rocket body
            setfillstyle(1, 8);
            if (i < 50)
            {
                bar(250 - i, 190 + i, 280 - i, 300 + i); //booster 1
                bar(320 + i, 190 + i, 350 + i, 300 + i); //booster 2
                setcolor(9);
                setfillstyle(6, 9);
                //booster 1 cone
                sector(265 - i, 150 + i, 250, 290, 45, 45);
                //booster 2 cone
                sector(335 + i, 150 + i, 250, 290, 45, 45);
                //booster 1 flames
                setcolor(14);
                setfillstyle(1, 14);
                draw_circle(265 - i, 310 + i, 20);
                floodfill(265 - i, 310 + i, 14);
                draw_circle(265 - i, 335 + i, 12);
                floodfill(265 - i, 335 + i, 14);
                //booster 2 flames
                draw_circle(335 + i, 310 + i, 20);
                floodfill(335 + i, 310 + i, 14);
                draw_circle(335 + i, 335 + i, 12);
                floodfill(335 + i, 335 + i, 14);
            }
            else if (i >= 50 && i < 100)
            {
                i = i - 50;
                bar(200 - (i / 2), 240 + i, 230 - (i / 2), 350 + i); //booster 1
                bar(370 + (i / 2), 240 + i, 400 + (i / 2), 350 + i); //booster 2
                setcolor(9);
                setfillstyle(6, 9);
                //booster 1 cone
                sector(215 - (i / 2), 200 + i, 250, 290, 45, 45);
                //booster 2 cone
                sector(385 + (i / 2), 200 + i, 250, 290, 45, 45);
                setcolor(14);
                //booster 1 flames
                setfillstyle(1, 14);
                draw_circle(215 - (i / 2), 360 + i, 20);
                floodfill(215 - (i / 2), 360 + i, 14);
                //booster 2 flames
                draw_circle(385 + (i / 2), 360 + i, 20);
                floodfill(385 + (i / 2), 360 + i, 14);
                i = i + 50;
            }
            else
            {
                i = i - 100;
                bar(175, 290 + i, 205, 400 + i); //booster 1
                bar(395, 290 + i, 425, 400 + i); //booster 2
                setcolor(9);
                setfillstyle(6, 9);
                //booster 1 cone
                sector(190, 250 + i, 250, 290, 45, 45);
                //booster 2 cone
                sector(410, 250 + i, 250, 290, 45, 45);
                i = i + 100;
            }
            // body cone
            setcolor(9);
            setfillstyle(6, 9);
            sector(300, 70, 250, 290, 65, 65);
            setcolor(14);
            setfillstyle(1, 14);
            draw_circle(300, 360, 25);
            floodfill(300, 360, 14);
            draw_circle(300, 390, 15);
            floodfill(300, 390, 14);
            //ISRO
            setcolor(WHITE);
            settextstyle(1, 0, 1);
            outtextxy(295, 180, "I");
            outtextxy(292, 210, "S");
            outtextxy(290, 240, "R");
            outtextxy(290, 270, "O");
            setcolor(14);
            setfillstyle(1, 14);
            draw_circle(300, 323, 33);
            floodfill(300, 323, 14);
            //stars
            setcolor(WHITE);
            setfillstyle(1, 15);
            draw_circle(600, 400 + i, 2);
            floodfill(600, 400 + i, 15);
            draw_circle(100, 200 + i, 2);
            floodfill(100, 200 + i, 15);
            draw_circle(200, 600 + i, 2);
            floodfill(200, 600 + i, 15);
            draw_circle(400, 100 + i, 2);
            floodfill(400, 100 + i, 15);
            draw_circle(700, 300 + i, 2);
            floodfill(700, 300 + i, 15);
            draw_circle(100, i, 2);
            floodfill(100, i, 15);
            draw_circle(200, -100 + i, 2);
            floodfill(200, -100 + i, 15);
            draw_circle(750, 100 + i, 2);
            floodfill(750, 100 + i, 15);
            draw_circle(450, -200 + i, 2);
            floodfill(450, -200 + i, 15);
            delay(20);
            cleardevice();
        }
        //********************IN SPACE************************
        for (i = 0; i < 200; i++)
        {
            setcolor(BLUE);
            draw_circle(200 - i, 400 + i, 135 - (i / 2));
            setfillstyle(1, 1);
            floodfill(200 - i, 400 + i, 1);
            int arr1[] = {320, 250, 440, 130, 460, 150, 340, 270, 320, 250}; //body
            setfillstyle(1, 15);
            fillpoly(4, arr1);
            setcolor(9);
            setfillstyle(6, 9);
            sector(480, 110, 205, 245, 45, 45); //body cone
            //body flames
            setcolor(14);
            setfillstyle(1, 14);
            draw_circle(330, 260, 18);
            floodfill(330, 260, 14);
            draw_circle(312, 278, 10);
            floodfill(312, 278, 14);
            draw_circle(302, 288, 5);
            floodfill(302, 288, 14);
            //stars
            setcolor(15);
            setfillstyle(1, 15);
            draw_circle(650 - i, 50 + i, 3);
            floodfill(650 - i, 50 + i, 15);
            draw_circle(400 - i, 100 + i, 2);
            floodfill(400 - i, 100 + i, 15);
            draw_circle(500 - i, 300 + i, 1);
            floodfill(500 - i, 300 + i, 15);
            draw_circle(100 - i, 100 + i, 4);
            floodfill(100 - i, 100 + i, 15);
            draw_circle(700 - i, 500 + i, 2);
            floodfill(700 - i, 500 + i, 15);
            draw_circle(200 - i, 700 + i, 2);
            floodfill(200 - i, 700 + i, 15);
            draw_circle(400 - i, 650 + i, 1);
            floodfill(400 - i, 650 + i, 15);
            draw_circle(900 - i, 200 + i, 3);
            floodfill(900 - i, 200 + i, 15);
            draw_circle(900 - i, 550 + i, 3);
            floodfill(900 - i, 550 + i, 15);
            draw_circle(800 - i, 300 + i, 2);
            floodfill(800 - i, 300 + i, 15);
            draw_circle(400 - i, -100 + i, 1);
            floodfill(400 - i, -100 + i, 15);
            draw_circle(600 - i, 600 + i, 2);
            floodfill(600 - i, 600 + i, 15);
            //moon
            draw_circle(800 - i, -150 + i, 20);
            floodfill(800 - i, -150 + i, 15);
            delay(30);
            cleardevice();
        }

        //******************LANDING*****************
        setbkcolor(BLACK);
        cleardevice();
        for (int i = 0; i < 240; i++)
        {
            if (i < 200)
            {
                setfillstyle(1, 15);
                bar(380, 230 + i, 420, 400 + i);
                setcolor(9);
                setfillstyle(6, 9);
                sector(400, 170 + i, 250, 290, 65, 65);
                setcolor(14);
                setfillstyle(1, 14);
                draw_circle(400, 410 + i, 30 - (i / 10));
                floodfill(400, 410 + i, 14);
                setcolor(WHITE);
                settextstyle(1, 0, 1);
                outtextxy(395, 250 + i, "I");
                outtextxy(392, 280 + i, "S");
                outtextxy(390, 310 + i, "R");
                outtextxy(390, 340 + i, "O");
            }
            else
            {
                setcolor(9);
                setfillstyle(6, 9);
                sector(400, 370, 250, 290, 65, 65);
                setfillstyle(1, 15);
                bar(380, 430, 420, 600);
                setcolor(WHITE);
                settextstyle(1, 0, 1);
                outtextxy(395, 450, "I");
                outtextxy(392, 480, "S");
                outtextxy(390, 510, "R");
                outtextxy(390, 540, "O");
                setcolor(2);
                settextstyle(0, 0, 4);
                outtextxy(120, 200, "MISSION SUCCESS!");
                delay(10);
            }
            setfillstyle(1, 8);
            draw_line(0, 600, 800, 600);
            draw_line(800, 600, 800, 800);
            draw_line(800, 800, 0, 800);
            draw_line(0, 800, 0, 600);
            floodfill(1, 601, 8);
            delay(20);
            cleardevice();
        }
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
