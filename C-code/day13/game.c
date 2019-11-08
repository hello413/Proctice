#include"snack.h"

int  dx[4] = { -1, 0, 1, 0 };             //A:0		S:1		D:2		W:3
int  dy[4] = { 0, 1, 0, -1 };   

int sum = 5;  //���ܳ���
int over = 0;  //�Ƿ�����
int speed;     //ˢ���ٶ�
char map[17][17];

void game()
{
	system("cls");
	init();
	show();
}

void init()  //��ʼ������
{ 
	speed = 500;
	over = 0;
	sum = 5;
	int i, j;
	for (i = 0; i < 100; i++) {  //��ʼ����ͷ�����������
		A[i].dir = 0;
		A[i].x = 0;
		A[i].y = 0;
	}
	A[0].x = 1; A[0].y = 1;  //��ͼ���Ͻ�����һ������Ϊ5����
	A[1].x = 1; A[1].y = 2;
	A[2].x = 1; A[2].y = 3;
	A[3].x = 1; A[3].y = 4;
	A[4].x = 1; A[4].y = 5; A[4].dir = 1;
	for (i = 0; i < 17; i++) {  //���õ�ͼ
		for (j = 0; j < 17; j++) {
			map[i][j] = '#';
		}
	}
	for (i = 1; i < 16; i++) {
		for (j = 1; j < 16; j++) {
			map[i][j] = ' ';
		}
	}
	map[A[4].x][A[4].y] = 'Y';  //������ͷ
	for (i = 0; i < sum - 1; i++) {  //��������
		map[A[i].x][A[i].y] = 'I';
	}
	food();
}

void check()  //����Ƿ��������߳Ե�ʳ��
{ 
	int x, y, i, j;
	x = A[sum - 1].x + dx[A[sum - 1].dir];  //��¼����ǰ�����ƶ�һ�����ͷ������ 
	y = A[sum - 1].y + dy[A[sum - 1].dir];
	if (map[x][y] == '#' || map[x][y] == 'I') {  //�����ͼ�ϸ����괦�ַ�Ϊ'#'(ǽ)��'I'(����)������ 
		if (x != A[0].x || y != A[0].y) {  //��β���� 
			for (int k = 0; k < 17; k++)
			{
				map[8][k] = ' ';
			}
			map[8][4] = 'G'; map[8][5] = 'A'; map[8][6] = 'M'; map[8][7] = 'E';  //�����GAME OVER�� 
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
	else if (map[x][y] == 'O') {  //�Ե�ƻ�� 
		sum++;  //�����ܳ���1 
		speed = ((600 - sum * 20) > 100) ? (600 - sum * 20) : 100; //�ٶȼӿ� 
	}
}

void food() //����ʳ��
{  
	srand((unsigned)time(NULL));
	while (1) {
		int x = (int)(15 * rand() / (RAND_MAX + 1.0));  //�������һ��ʳ������
		int y = (int)(15 * rand() / (RAND_MAX + 1.0));
		if (map[x][y] == ' ') {  //����ǿո����ڸô�����ʳ��
			map[x][y] = 'O';
			break;
		}
	}
}
void show()  //��ʾ����
{  
	int i, j, x, y;
	for (i = 0; i < 17; i++) {  //��ʾ����
		for (j = 0; j < 17; j++) {
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
	while (1) {
		Sleep(speed);  //����ˢ���ٶ�
		turn();
		move();
		if (over) {  //��������������Խ��еĲ��� 
			while (1) {
				int ch = 0;
				scanf("%d", &ch);
				if (ch == 0) {  //���롮0������ 
					return;
				}
				else if (ch == 1) {  //���롮1�����¿�ʼ 
					init();
					break;
				}
				else
				{
					printf("enter error!Please enter again:>");
				}
			}
		}
		system("cls");  //���� 
		for (i = 0; i < 17; i++) {  //������ʾ����
			for (j = 0; j < 17; j++) {
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
	}
}

void turn()  //ת��
{ 
	if (kbhit()) {
		char dir = _getch();  //��ȡ����ļ� 
		switch (dir) {  //�ı䷽��     W:0 A:3 S:2  D:1
		case 'w': A[sum - 1].dir = (A[sum - 1].dir == 2) ? 2 : 0; break;  
		case 'a': A[sum - 1].dir = (A[sum - 1].dir == 1) ? 1 : 3; break;
		case 'd': A[sum - 1].dir = (A[sum - 1].dir == 3) ? 3 : 1; break;
		case 's': A[sum - 1].dir = (A[sum - 1].dir == 0) ? 0 : 2; break;
		}
	}
}

void move()  //���ƶ�
{ 
	int i, x, y;
	int t = sum;  //t��¼��ǰ���ܳ��� 
	check();  //�ƶ�ǰ��鰴��ǰ�����ƶ�һ��������
	if (t == sum) {  //û�гԵ�ƻ��(�����ʱ�Ե�ƻ���Ļ���sum��+1)
		for (i = 0; i < sum - 1; i++) {			//����
			if (i == 0) {  //��β���괦��ɿո񣬰���β������ǰһ����������� 
				map[A[i].x][A[i].y] = ' ';
				A[i].x = A[i + 1].x;
				A[i].y = A[i + 1].y;
			}
			else {  //ÿ���������궼��Ϊ��ǰһ�����������
				A[i].x = A[i + 1].x;
				A[i].y = A[i + 1].y;
			}
			map[A[i].x][A[i].y] = 'I';  //�ѵ�ͼ���������괦���ַ����óɡ�I��
		}
		A[sum - 1].x = A[sum - 1].x + dx[A[sum - 1].dir];  //��ͷ����ǰ�����ƶ�һ�� 
		A[sum - 1].y = A[sum - 1].y + dy[A[sum - 1].dir];
		map[A[sum - 1].x][A[sum - 1].y] = 'Y';  //�ѵ�ͼ����ͷ���괦���ַ����óɡ�Y��
	}
	else {  //�Ե�ƻ����sum���1��
		map[A[sum - 2].x][A[sum - 2].y] = 'I';  //�ѵ�ͼ��ԭ��ͷ���괦���ַ����óɡ�I��
		A[sum - 1].x = A[sum - 2].x + dx[A[sum - 2].dir];  //����ͷ��������ԭ��ͷ�ص�ǰ�����ƶ�һ�������� 
		A[sum - 1].y = A[sum - 2].y + dy[A[sum - 2].dir];
		A[sum - 1].dir = A[sum - 2].dir;  //����ͷ����Ϊԭ��ͷ�ķ���
		map[A[sum - 1].x][A[sum - 1].y] = 'Y';  //�ѵ�ͼ����ͷ���괦���ַ����óɡ�Y��
		food();
	}
}
