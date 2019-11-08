#include<stdio.h>
/*单链表的头插法*/
#pragma warning(disable:4996)
struct Book
{
	char name[100];
	struct Book* next;
};
void scan(struct Book* book)
{
	printf("enter name:");
	scanf("%s", book->name);
}
void frin(struct Book* library)
{
	struct Book* book;
	int count = 1;
	book = library;
	while (book != NULL)
	{
		printf("%d", count);
		printf("name:%s\n", book->name);
		book = book->next;
		count++;
	}
}
void free(struct Book* library)
{
	while (library!=NULL)
	{
		free(library);
		library = library->next;
	}
}
void add(struct Book** library)
{
	struct People* book;
	static struct People* temp;
	book = (struct People*)malloc(sizeof(struct People));
	if (book == NULL)
	{
		printf("分配\n");
		exit(1);
	}
	scan(book);
	if (*library != NULL)
	{
		temp->next = book;
		book->next = NULL;
	}
	else
	{
		book->next = NULL;
		*library = book;
	}
	temp = book;
}
int main()
{
	struct Book* library = NULL;
	char ch;
	while (1)
	{
		printf("输入y/n:");
		do
		{
			ch = getchar();
		} while (ch!='y'&&ch!='n');
		if (ch=='y')
		{
			add(&library);
		}
		else
		{
			break;
		}
	}
	printf("打印y/n：");
	do
	{
		ch = getchar();
	} while (ch != 'y' && ch != 'n');
	if (ch == 'y')
	{
		frin(library);
	}
	free(library);
	return 0;
}
