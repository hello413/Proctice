#include"snack.h"

int  dx[4] = { -1, 0, 1, 0 };             //A:0		S:1		D:2		W:3
int  dy[4] = { 0, 1, 0, -1 };   

int sum = 5;  //蛇总长度
int over = 0;  //是否死亡
int speed;     //刷新速度
char map[17][17];

void game()
{
	system("cls");
	init();
	show();
}

void init()  //初始化界面
{ 
	speed = 500;
	over = 0;
	sum = 5;
	int i, j;
	for (i = 0; i < 100; i++) {  //初始化蛇头和蛇身的数据
		A[i].dir = 0;
		A[i].x = 0;
		A[i].y = 0;
	}
	A[0].x = 1; A[0].y = 1;  //地图左上角设置一条长度为5的蛇
	A[1].x = 1; A[1].y = 2;
	A[2].x = 1; A[2].y = 3;
	A[3].x = 1; A[3].y = 4;
	A[4].x = 1; A[4].y = 5; A[4].dir = 1;
	for (i = 0; i < 17; i++) {  //设置地图
		for (j = 0; j < 17; j++) {
			map[i][j] = '#';
		}
	}
	for (i = 1; i < 16; i++) {
		for (j = 1; j < 16; j++) {
			map[i][j] = ' ';
		}
	}
	map[A[4].x][A[4].y] = 'Y';  //设置蛇头
	for (i = 0; i < sum - 1; i++) {  //设置蛇身
		map[A[i].x][A[i].y] = 'I';
	}
	food();
}

void check()  //检查是否死亡或者吃到食物
{ 
	int x, y, i, j;
	x = A[sum - 1].x + dx[A[sum - 1].dir];  //记录按当前方向移动一格后蛇头的坐标 
	y = A[sum - 1].y + dy[A[sum - 1].dir];
	if (map[x][y] == '#' || map[x][y] == 'I') {  //如果地图上该坐标处字符为'#'(墙)或'I'(蛇身)就死亡 
		if (x != A[0].x || y != A[0].y) {  //蛇尾除外 
			for (int k = 0; k < 17; k++)
			{
				map[8][k] = ' ';
			}
			map[8][4] = 'G'; map[8][5] = 'A'; map[8][6] = 'M'; map[8][7] = 'E';  //输出“GAME OVER” 
			map[8][9] = 'O'; map[8][10] = 'V'; map[8][11] = 'E'; map[8][12] = 'R';
			system("cls");
			for (i = 0; i < 17; i++) {
				for (j = 0; j < 17; j++) {
					printf("%c", map[i][j]);
				}
				printf("\n");
			}
			printf("Input '1' to again>\nInput '0' to quit>\n");
			over = 1;
		}
	}
	else if (map[x][y] == 'O') {  //吃到苹果 
		sum++;  //蛇身总长加1 
		speed = ((600 - sum * 20) > 100) ? (600 - sum * 20) : 100; //速度加快 
	}
}

void food() //生成食物
{  
	srand((unsigned)time(NULL));
	while (1) {
		int x = (int)(15 * rand() / (RAND_MAX + 1.0));  //随机产生一组食物坐标
		int y = (int)(15 * rand() / (RAND_MAX + 1.0));
		if (map[x][y] == ' ') {  //如果是空格则在该处生成食物
			map[x][y] = 'O';
			break;
		}
	}
}
void show()  //显示界面
{  
	int i, j, x, y;
	for (i = 0; i < 17; i++) {  //显示界面
		for (j = 0; j < 17; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	while (1) {
		Sleep(speed);  //界面刷新速度
		turn();
		move();
		if (over) {  //设置蛇死掉后可以进行的操作 
			while (1) {
				int ch = 0;
				scanf("%d", &ch);
				if (ch == 0) {  //输入‘0’结束 
					return;
				}
				else if (ch == 1) {  //输入‘1’重新开始 
					init();
					break;
				}
				else
				{
					printf("enter error!Please enter again:>");
				}
			}
		}
		system("cls");  //清屏 
		for (i = 0; i < 17; i++) {  //重新显示界面
			for (j = 0; j < 17; j++) {
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
	}
}

void turn()  //转弯
{ 
	if (kbhit()) {
		char dir = _getch();  //读取输入的键 
		switch (dir) {  //改变方向     W:0 A:3 S:2  D:1
		case 'w': A[sum - 1].dir = (A[sum - 1].dir == 2) ? 2 : 0; break;  
		case 'a': A[sum - 1].dir = (A[sum - 1].dir == 1) ? 1 : 3; break;
		case 'd': A[sum - 1].dir = (A[sum - 1].dir == 3) ? 3 : 1; break;
		case 's': A[sum - 1].dir = (A[sum - 1].dir == 0) ? 0 : 2; break;
		}
	}
}

void move()  //蛇移动
{ 
	int i, x, y;
	int t = sum;  //t记录当前蛇总长度 
	check();  //移动前检查按当前方向移动一步后的情况
	if (t == sum) {  //没有吃到苹果(如果此时吃到苹果的话，sum会+1)
		for (i = 0; i < sum - 1; i++) {			//蛇身
			if (i == 0) {  //蛇尾坐标处变成空格，把蛇尾坐标变成前一个蛇身的坐标 
				map[A[i].x][A[i].y] = ' ';
				A[i].x = A[i + 1].x;
				A[i].y = A[i + 1].y;
			}
			else {  //每个蛇身坐标都变为它前一个蛇身的坐标
				A[i].x = A[i + 1].x;
				A[i].y = A[i + 1].y;
			}
			map[A[i].x][A[i].y] = 'I';  //把地图上蛇身坐标处的字符设置成‘I’
		}
		A[sum - 1].x = A[sum - 1].x + dx[A[sum - 1].dir];  //蛇头按当前方向移动一格 
		A[sum - 1].y = A[sum - 1].y + dy[A[sum - 1].dir];
		map[A[sum - 1].x][A[sum - 1].y] = 'Y';  //把地图上蛇头坐标处的字符设置成‘Y’
	}
	else {  //吃到苹果（sum会加1）
		map[A[sum - 2].x][A[sum - 2].y] = 'I';  //把地图上原蛇头坐标处的字符设置成‘I’
		A[sum - 1].x = A[sum - 2].x + dx[A[sum - 2].dir];  //新蛇头的坐标是原蛇头沿当前方向移动一格后的坐标 
		A[sum - 1].y = A[sum - 2].y + dy[A[sum - 2].dir];
		A[sum - 1].dir = A[sum - 2].dir;  //新蛇头方向为原蛇头的方向
		map[A[sum - 1].x][A[sum - 1].y] = 'Y';  //把地图上蛇头坐标处的字符设置成‘Y’
		food();
	}
}
