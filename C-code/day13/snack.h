#ifndef _GAME_
#define _GAME_

#include<time.h>
#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
#pragma warning(disable:4996)

struct snake {
	int x, y;  //�������� 
	int dir;  //����ֻ����ͷ�ķ��������õģ� 
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
