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
	printf("第%d本书:\n", num);
	printf("书名:");
	scanf("%s", (b + num - 1)->title);
	printf("作者:");
	scanf("%s", (b + num - 1)->author);
	printf("价格:");
	scanf("%f", &(b + num - 1)->price);
	printf("日期:");
	scanf("%d%d%d", &(b + num - 1)->date.year, &(b + num - 1)->date.month, &(b + num - 1)->date.day);
	printf("出版社:");
	scanf("%s", (b + num - 1)->publisher);

}

void printBook(struct Book* b, int num)
{
	int i;
	for (i = 0; i < num; i++)
	{
		printf("第%d本书:\n", i + 1);
		printf("书名:%s\n作者:%s\n", (b + i)->title, (b + i)->author);
		printf("价格:%.2f\n", (b + i)->price);
		printf("日期:%d-%d-%d\n", (b + i)->date.year, (b + i)->date.month, (b + i)->date.day);
		printf("出版社:%s\n", (b + i)->publisher);
	}
}

int main(void)
{

	struct Book* b = NULL;
	char c;
	int num = 0;
	printf("是否要录入书籍(Y/N)?");
	scanf("%c", &c);
	while (c != 'y' && c != 'Y' && c != 'n' && c != 'N')
	{
		printf("输入出错，请重新输入:");
		scanf("%c", &c);
	}
	while (c == 'Y' || c == 'y')
	{
		num++;
		b = (struct Book*)realloc(b, sizeof(struct Book) * num);
		getInput(b, num);
		printf("是否要录入书籍(Y/N)?");
		getchar();
		scanf("%c", &c);
		while (c != 'y' && c != 'Y' && c != 'n' && c != 'N')
		{
			printf("输入出错，请重新输入:");
			scanf("%c", &c);
		}
	}
	putchar('\n');
	printBook(b, num);
	free(b);

	return 0;
}