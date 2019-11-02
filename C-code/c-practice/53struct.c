#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
struct Date
{
	int year;
	int month;
	int day;
};
struct Book
{
	char title[128];
	char author[40];
	float price;
	struct Date date;
	char publisher[40];
};

void getInput(struct Book* b, int);
void printBook(struct Book* b, int);

void getInput(struct Book* b, int num)
{
	printf("��%d����:\n", num);
	printf("����:");
	scanf("%s", (b + num - 1)->title);
	printf("����:");
	scanf("%s", (b + num - 1)->author);
	printf("�۸�:");
	scanf("%f", &(b + num - 1)->price);
	printf("����:");
	scanf("%d%d%d", &(b + num - 1)->date.year, &(b + num - 1)->date.month, &(b + num - 1)->date.day);
	printf("������:");
	scanf("%s", (b + num - 1)->publisher);

}

void printBook(struct Book* b, int num)
{
	int i;
	for (i = 0; i < num; i++)
	{
		printf("��%d����:\n", i + 1);
		printf("����:%s\n����:%s\n", (b + i)->title, (b + i)->author);
		printf("�۸�:%.2f\n", (b + i)->price);
		printf("����:%d-%d-%d\n", (b + i)->date.year, (b + i)->date.month, (b + i)->date.day);
		printf("������:%s\n", (b + i)->publisher);
	}
}

int main(void)
{

	struct Book* b = NULL;
	char c;
	int num = 0;
	printf("�Ƿ�Ҫ¼���鼮(Y/N)?");
	scanf("%c", &c);
	while (c != 'y' && c != 'Y' && c != 'n' && c != 'N')
	{
		printf("�����������������:");
		scanf("%c", &c);
	}
	while (c == 'Y' || c == 'y')
	{
		num++;
		b = (struct Book*)realloc(b, sizeof(struct Book) * num);
		getInput(b, num);
		printf("�Ƿ�Ҫ¼���鼮(Y/N)?");
		getchar();
		scanf("%c", &c);
		while (c != 'y' && c != 'Y' && c != 'n' && c != 'N')
		{
			printf("�����������������:");
			scanf("%c", &c);
		}
	}
	putchar('\n');
	printBook(b, num);
	free(b);

	return 0;
}