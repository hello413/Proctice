#include"game.h"

void start()
{
	printf("###########################\n");
	printf("##### Welcome to join #####\n");
	printf("###########################\n");
	printf("### 1.play game  0.exit ###\n");
	printf("###########################\n");
}
void game()
{
	srand((unsigned)time(NULL));
	char table[3][3];
	initial(table, COL, ROW);
	int x, y;
	char result = 'N';
	int first = rand() % 2;
	if (first == 0)
	{
		printf("computer go before>\n");
		computer(table, COL, ROW);
		showtable(table, COL, ROW);
	}
	while (result == 'N')
	{
		printf("choose your coordinate :");
		scanf("%d%d", &x, &y);
		x--;
		y--;
		if (x < 0 || x>2 || y < 0 || y>2) {
			printf("enter error! please again:>\n");
			continue;
		}
		if (table[x][y] != ' ') {
			printf(" there plase is occupied! please again:>\n");
			continue;
		}
		table[x][y] = 'X';
		computer(table, COL,ROW);
		showtable(table, COL, ROW);
		result = judge(table);
		switch (result)
		{
		case 'N':
			break;
		case 'C':
			printf("\nsorry! the computer won!\n\n");
			break;
		case 'P':
			printf("you are won!\n");
			break;
		case 'M':
			printf("just so-so!\n");
			break;
		default:printf("3");
			break;
		}
	}
	start();
	printf("Are you again?\n");
}
/*初始化棋盘*/
void initial(char table[3][3], int col, int row)
{
	printf("   |  1 |  2 | 3  |\n");
	printf("------------------\n");
	for (int i = 0; i < col; i++)
	{
		printf(" %d |", i + 1);
		for (int j = 0; j < row; j++)
		{
			table[i][j] = ' ';
			printf("  %c |", table[i][j]);
			
		}
		printf("\n------------------\n");
	}
}
/*电脑走*/
void computer(char table[3][3], int cow, int row)
{
	srand((unsigned)time(NULL));
	int x = 0, y = 0, ch = 0;
	for (int i = 0; i < COL; i++)
	{
		if (ch == 1)
		{
			break;
		}
		for (int j = 0; j < ROW; j++)
		{
			if (table[i][j] == ' ')
			{
				ch = 1;
				break;
			}
		}
	}
	int i = 2;
	while (i > 0) {
		printf("computer is loading ... %d\r", i--);
		Sleep(1000);
	}
	printf("loading ... done!\n");
	while (ch == 1)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (table[x][y] == ' ') {
			table[x][y] = 'O';
			break;
		}
	}
}
/*判断输赢*/
char judge(char table[3][3])
{
	char result='M';
	for (int i = 0; i < COL; i++)
	{
		if (result == 'N')
		{
			break;
		}
		for (int j = 0; j < ROW; j++)
		{
			if (table[i][j] == ' ')
			{
				result = 'N';
				break;
			}
		}
	}
	for (int i = 0; i < COL; i++)
	{
		if (table[i][0]!=' '&& table[i][0]== table[i][1] && table[i][0] == table[i][2])
		{
			if (table[i][0]=='X')
			{
				result = 'P';
				break;
			}
			else
			{
				result = 'C';
				break;
			}
		}
		if (table[0][i] != ' ' && table[0][i] == table[1][i] && table[0][i] == table[2][i])
		{
			if (table[0][i] == 'X')
			{
				result = 'P';
				break;
			}
			else
			{
				result = 'C';
				break;
			}
		}
	}
	if (table[0][0] != ' ' && table[0][0] == table[1][1] && table[0][0] == table[2][2])
	{
		if (table[0][0] == 'X')
		{
			result = 'P';
		}
		else
		{
			result = 'C';
		}
	}
	if (table[0][2] != ' ' && table[0][2] == table[1][1] && table[0][2] == table[2][0])
	{
		if (table[2][0] == 'X')
		{
			result = 'P';
		}
		else
		{
			result = 'C';
		}
	}
	return result;
}
/*展示页面*/
void showtable(char table[3][3], int col, int row)
{
	printf("   |  1 |  2 | 3  |\n");
	printf("------------------\n");
	for (int i = 0; i < col; i++)
	{
		printf(" %d |", i + 1);
		for (int j = 0; j < row; j++)
		{
			printf("  %c |", table[i][j]);
		}
		printf("\n------------------\n");
	}
}