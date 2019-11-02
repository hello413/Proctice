#ifndef GAME_H
#define GAME_H


#include<stdio.h>
#include<windows.h>
#include<time.h>
#pragma warning(disable:4996)

#define COL 3
#define ROW 3



void start();
void game();
void initial(char table[3][3], int cow, int row);
void computer(char table[3][3], int cow, int row);
void showtable(char table[3][3], int col, int row);
char judge(char table[3][3]);


#endif // GAME_H


