#ifndef _GAME_
#define _GAME_

#include<time.h>
#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning(disable:4996)

struct snake {
	int x, y;  //身体坐标 
	int dir;  //方向（只有蛇头的方向是有用的） 
} A[100];




void init();
void game();
void food();
void turn();
void move();
void show();
void check();
void welcome();



#endif // !_GAME_
