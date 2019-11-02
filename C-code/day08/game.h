#ifndef __GAME_H_
#define __GAME_H_


#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

#define COL 12
#define ROW 12
#define NUM 20

void start();
int statistics(char mine_table[COL][ROW], int x, int y);
void showtable(char show_table[COL][ROW], int col, int row);
void setmine(char mine_table[COL][ROW], int col, int row, int* no_x, int* no_y);
void Expand(char mine_table[COL][ROW], char show_table[COL][ROW], int x, int y);

#endif // !__GAME_H_
