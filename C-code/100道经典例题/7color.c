/*����������ı���ɫ*/

//1 - f�ֱ�������ɫ���£�
//
//0 = ��ɫ		1 = ��ɫ		2 = ��ɫ	3 = ����ɫ	4 = ��ɫ	5 = ��ɫ		6 = ��ɫ	7 = ��ɫ 	8 = ��ɫ        9 = ����ɫ        
//A = ����ɫ       B = ��ǳ��ɫ   C = ����ɫ        D = ����ɫ         E = ����ɫ        F = ����ɫ
#include <stdio.h>
#include <windows.h>
void color(short x)	//�Զ��庯���ݲ����ı���ɫ 
{
	if (x >= 0 && x <= 15)//������0-15�ķ�Χ��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);	//ֻ��һ���������ı�������ɫ 
	else//Ĭ�ϵ���ɫ��ɫ
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}
int main()
{
	printf("�˴�Ϊû������ɫ����֮ǰĬ�ϵ���ɫ\n");
	//�����Զ���color(x)���� �ı����ɫ
	color(0);	printf("��ɫ\n");
	color(1); 	printf("��ɫ\n");
	color(2); 	printf("��ɫ\n");
	color(3); 	printf("����ɫ\n");
	color(4);  	printf("��ɫ\n");
	color(5);  	printf("��ɫ\n");
	color(6); 	printf("��ɫ\n");
	color(7);  	printf("��ɫ\n");
	color(8);  	printf("��ɫ\n");
	color(9); 	printf("����ɫ\n");
	color(10); 	printf("����ɫ\n");
	color(11); 	printf("��ǳ��ɫ\n");
	color(12);  printf("����ɫ\n");
	color(13); 	printf("����ɫ\n");
	color(14); 	printf("����ɫ\n");
	color(15); 	printf("����ɫ\n");
	color(16);    //��Ϊ�������15���ָ�Ĭ�ϵ���ɫ 
	printf("�ص�ԭ����ɫ\n");
	return 0;
}