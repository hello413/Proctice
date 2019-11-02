#include"game.h"

void game()
{
	char mine_table[COL][ROW];
	char show_table[COL][ROW];
	int no_x, no_y;
	memset(mine_table, '0', sizeof(mine_table));
	memset(show_table, '*', sizeof(show_table));
	setmine(mine_table,COL,ROW, &no_x, &no_y);
	int x = 0, y = 0;
	int times = 100 - NUM;
	do
	{
		system("cls");
		showtable(show_table, COL, ROW);
		printf("Please enter your coord:>");
		scanf("%d%d", &x, &y);
		if (x < 1 || x>10 || y < 1 || y>10) 
		{
			printf("enter orrer! Please enter again\n");
			continue;
		}
		if (show_table[x][y]!='*')
		{
			printf("enter orrer! it has used! Please enter again\n");
			continue;
		}
		if (mine_table[x][y] == '1')
		{
			if (times == 80) {
				mine_table[x][y] = '0';
				mine_table[no_x][no_y] = '1';
			}
			else {
				printf("Game Over!!\n");
				showtable(mine_table, COL, ROW);
				break;
			}
		}
		show_table[x][y] = statistics(mine_table, x, y)+'0';
		Expand(mine_table, show_table, x, y);
		times--;
	} while (times > 0);
	printf("Are you again?\n");
	start();
}

void setmine(char mine_table[COL][ROW], int col, int row,int* no_x, int* no_y)
{
	int num = NUM;
	srand((unsigned)time(NULL));
	while (num)
	{
		int x = rand() % (col - 2) + 1;
		int y = rand() % (row - 2) + 1;
		if (mine_table[x][y] == '0')
		{
			mine_table[x][y] = '1';
			num--;
		}
	}
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			if (mine_table[i][j] == '0')
			{
				no_x = i;
				no_y = j;
				return;
			}
		}
	}
}

void showtable(char show_table[COL][ROW], int col, int row)
{
	printf("    ");
	for (int i = 1; i <= 10; i++)
	{
		printf(" %2d |", i);
	}
	printf("\n");
	for (int i = 1; i <= 11; i++)
	{
		printf("-----");
	}
	printf("\n");
	for (int i = 1; i <= 10; i++)
	{
		printf("%2d |", i);
		for (int j = 1; j <= 10; j++)
		{
			printf(" %2c |", show_table[i][j]);
		}
		printf("\n");
		for (int i = 1; i <= 11; i++)
		{
			printf("-----");
		}
		printf("\n");
	}
}
int statistics(char mine_table[COL][ROW], int x, int y)
{
	return mine_table[x - 1][y - 1] + mine_table[x - 1][y] + mine_table[x - 1][y + 1] + mine_table[x][y - 1] \
		+ mine_table[x][y + 1] + mine_table[x + 1][y - 1] + mine_table[x + 1][y] + mine_table[x + 1][y + 1] - 8 * '0';
}
void Expand(char mine_table[COL][ROW], char show_table[COL][ROW],int x, int y)//展开函数
{
	if (x>0&&x<11&&y>0&&y<11)
	{
		if (statistics(mine_table, x, y) + '0' == '0')  //周围没有雷
		{
			show_table[x][y] = ' ';    //置为空白
			if (show_table[x - 1][y - 1] == '*')
			{
				Expand(mine_table, show_table, x - 1, y - 1);
			}
			if (show_table[x - 1][y] == '*')
			{
				Expand(mine_table, show_table, x - 1, y);
			}
			if (show_table[x - 1][y + 1] == '*')
			{
				Expand(mine_table, show_table, x - 1, y + 1);
			}
			if (show_table[x][y - 1] == '*')
			{
				Expand(mine_table, show_table, x, y - 1);
			}
			if (show_table[x][y + 1] == '*')
			{
				Expand(mine_table, show_table, x, y + 1);
			}
			if (show_table[x + 1][y - 1] == '*')
			{
				Expand(mine_table, show_table, x + 1, y - 1);
			}
			if (show_table[x + 1][y] == '*')
			{
				Expand(mine_table, show_table, x + 1, y);
			}
			if (show_table[x + 1][y + 1] == '*')
			{
				Expand(mine_table, show_table, x + 1, y + 1);
			}
		}
	}
}