#include<stdio.h>
/*��С�˵��ж�*/
int main()
{
	char c;
	int a = 490;
	int* p = &a;
	c = *p;
	printf("%d   %d\n", c, a);
	if (c == a)					//ʵ���Ͼ����ж��Ƿ������û�������С�ˣ���֮��ˡ�
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}

	return 0;


}