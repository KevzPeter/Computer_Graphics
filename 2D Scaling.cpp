#include<stdio.h>
#include<graphics.h>

void findNewCoordinate(int s[][2], int p[][1])
{
	int temp[2][1] = { 0 };

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 1; j++)
			for (int k = 0; k < 2; k++)
				temp[i][j] += (s[i][k] * p[k][j]);

	p[0][0] = temp[0][0];
	p[1][0] = temp[1][0];
}

void scale(int x[], int y[], int sx, int sy)
{
	setcolor(RED);
	line(x[0], y[0], x[1], y[1]);
	line(x[1], y[1], x[2], y[2]);
	line(x[2], y[2], x[0], y[0]);


	int s[2][2] = { sx, 0, 0, sy };
	int p[2][1];

	for (int i = 0; i < 3; i++)
	{
		p[0][0] = x[i];
		p[1][0] = y[i];

		findNewCoordinate(s, p);

		x[i] = p[0][0];
		y[i] = p[1][0];
	}
    printf("Coordinates after scaling:\n(%d,%d)\n(%d,%d)\n(%d,%d)",x[0],y[0],x[1],y[1],x[2],y[2]);
	setcolor(WHITE);
	line(x[0], y[0], x[1], y[1]);
	line(x[1], y[1], x[2], y[2]);
	line(x[2], y[2], x[0], y[0]);
}

int main()
{
	int x[] = { 100, 200, 300 };
	int y[] = { 200, 100, 200 };
	int sx = 3, sy = 3;
    printf("Coordinates before scaling:\n(%d,%d)\n(%d,%d)\n(%d,%d)\n",x[0],y[0],x[1],y[1],x[2],y[2]);
	int gd, gm;
	detectgraph(&gd, &gm);
	initwindow(1200,700);

	scale(x, y, sx,sy);
	getch();

	return 0;
}
