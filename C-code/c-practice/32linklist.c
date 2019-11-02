#include<stdio.h>
/*�������ͷ�巨*/
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
		printf("����\n");
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
		printf("����y/n:");
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
	printf("��ӡy/n��");
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
