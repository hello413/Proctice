/*
0: �յ�
1: Ŀ�ĵ�   ��
2: ǽ��     ��
4: ����     ��
8: ���     ��
16: ���ӵ���Ŀ�ĵ�  ��
*/
int map[13][14] = {
	{ 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0 },
	{ 0, 2, 2, 2, 2, 0, 0, 4, 4, 2, 2, 2, 2, 2 },
	{ 0, 2, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 2 },
	{ 0, 2, 0, 4, 0, 0, 0, 4, 0, 0, 0, 4, 0, 2 },
	{ 0, 2, 0, 0, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2 },
	{ 2, 2, 2, 2, 0, 2, 2, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 0, 0, 0, 0, 2, 0, 0, 0, 8, 0, 0, 2 },
	{ 2, 0, 4, 0, 0, 0, 2, 0, 2, 2, 2, 2, 2, 2 },
	{ 2, 2, 0, 0, 0, 0, 2, 0, 2, 1, 1, 1, 2, 0 },
	{ 0, 2, 0, 2, 0, 0, 0, 0, 0, 1, 1, 1, 2, 0 },
	{ 0, 2, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 2, 0 },
	{ 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0 }
};
int mapcopy[13][14];

//չʾ������
void copy(int* dest, int* ch)
{
	int i = 0;
	while (ch[i])
	{
		dest[i] = ch[i];
		i++;
	}
	dest[i] = 0;
}


// Ŀ���
int tarPos[][2] = {
	{ 9, 9 },
	{ 9, 10 },
	{ 9, 11 },
	{ 10, 9 },
	{ 10, 10 },
	{ 10, 11 },
};


int row = 0, col = 0;    // �����ڵڼ��У��ڼ���
int oldType = 0;    // ����վ�ŵĵط�ԭ����ʲô����
int oldBoxType = 0; // ����վ�ŵĵط�ԭ����ʲô���� 



void Move(int r, int c)
{
	if (map[row + r][col + c] != 2)  // ���ǰ�治��ǽ�ڵĻ����Ϳ����ƶ�
	{
		if (map[row + r][col + c] == 4 || map[row + r][col + c] == 16)    // ����������ӵĴ���취
		{
			if (map[row + 2 * r][col + 2 * c] == 0 || map[row + 2 * r][col + 2 * c] == 1 )   // ���Ӻ��治��ǽ�ں�����
			{
				// �ƶ�����
				if (map[row + r][col + c] == 16)
				{
					oldBoxType = 1;
				}
				else if (map[row + r][col + c] == 4)
				{
					oldBoxType = 0;
				}
				map[row + r][col + c] = oldBoxType;
				if (map[row + 2 * r][col + 2 * c] == 1)
				{
					map[row + 2 * r][col + 2 * c] = 16;
				}
				else
				{
					map[row + 2 * r][col + 2 * c] = 4;
				}
			}
			else {
				return; // ������Ӻ�����ǽ�ڣ���ôֹͣ�ƶ�
			}
		}
		map[row][col] = oldType; // �������߹��ĵط���Ϊԭ���ĵ�������
		oldType = map[row + r][col + c]; // �洢���������Ҫ�ߵĵط��ĵ�������
		map[row + r][col + c] = 8;   // ���ƶ���λ�÷����仯
	}
}

// ����ͼ����
void DrawMap() 
{
	printf("w:�� a:��   s:��   d:��   0������    +:�˳�\n");
	for (int i = 0; i < sizeof(map) / sizeof(map[0]); i++)
	{
		for (int j = 0; j < sizeof(map[0]) / sizeof(map[0][0]); j++)
		{
			switch (map[i][j])
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("��");
				break;
			case 2:
				printf("��");
				break;
			case 4:
				printf("��");
				break;
			case 8:
				printf("��");
				row = i;
				col = j;
				break;
			case 16:
				printf("��");
				break;
			}
		}
		printf("\n");
	}
}

int resultCheck()
{
	int result = 1;
	for (int i = 0; i < sizeof(tarPos) / sizeof(tarPos[0]); i++)
	{
		if (map[tarPos[i][0]][tarPos[i][1]] != 16)
		{
			result = 0;
		}
	}
	if (result)
	{
		printf("You are won!!\n");
	}
	else
	{
		system("cls");  // �����Ļ
		DrawMap();  // ���»�ͼ
	}
	return result;
}


void game()
{
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 14; j++) {
			mapcopy[i][j] = map[i][j];
		}
	}
	DrawMap();
	int ch = 0;
	while (!ch)
	{
		char key = _getch();    //_getch()���������������̰���
		switch (key)
		{
		case 'a':
			Move(0, -1);
			break;
		case 'd':
			Move(0, 1);
			break;
		case 'w':
			Move(-1, 0);
			break;
		case 's':
			Move(1, 0);
			break;
		case '0':
			for (int i = 0; i < 13; i++)
			{
				for (int j = 0; j < 14; j++) {
					map[i][j] = mapcopy[i][j];
				}
			}
			oldType = 0;
			break;
		case '+':
			ch = 1;
			break;
		}
		int result = resultCheck();  // ����Ƿ����
		if (result)
		{
			for (int i = 0; i < 13; i++)
			{
				for (int j = 0; j < 14; j++) {
					map[i][j] = mapcopy[i][j] ;
				}
			}
			oldType = 0;
			break;
		}
	}
}