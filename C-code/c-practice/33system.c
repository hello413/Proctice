#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)
struct People
{
	char name[10];
	char telephone[11];
	struct People* next;
};
void get(struct People* peoples);
void set(struct People* peoples);
void add(struct People** people);
void delete(struct Poleop** people);
void update(struct Poleop* people);
struct People* find(struct Poleop* people);
void see(struct People* peoples);
void frees(struct People** people);

int main()
{
	printf("##########################################\n");
	printf("##### 1.add user       2.delete user######\n");
	printf("##### 3.find user      4.update user######\n");
	printf("##### 5.all user       0.exit  ###########\n");
	printf("#######################################\n");
	int ch;
	int isgo = 1;
	struct People* people = NULL, * peoples;
	while (isgo) {
		printf("enter your action:");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			add(&people);
			break;
		case 2:
			delete(&people);
			break;
		case 3:
			peoples = find(people);
			if (peoples == NULL)
			{
				printf("no finded!");
			}
			else
			{
				printf("find it...\n");
				see(peoples);
			}
			break;
		case 4:
			update(people);
			break;
		case 5:
			set(people);
			break;
		case 0:
			isgo = 0;
			break;
		default:
			break;
		}
	}
	frees(&people);
	return 0;
}

void add(struct People** people)
{
	struct People* peoples;
	static struct People* temp;
	peoples = (struct People*)malloc(sizeof(struct People));
	if (peoples == NULL)
	{
		printf("Failed to allocate space.\n");
		exit(1);
	}
	get(peoples);
	if (*people != NULL)
	{
		temp->next = peoples;
		peoples->next = NULL;
	}
	else
	{
		peoples->next = NULL;
		*people = peoples;
	}
	temp = peoples;
}
void update(struct Poleop* people)
{
	struct People* peoples;
	peoples = find(people);
	if (peoples == NULL)
	{
		printf("no find it!\n");
	}
	else
	{
		printf("enter your telephone");
		scanf("%s", peoples->telephone);
	}
}
void get(struct People* peoples)
{
	printf("enter name:");
	scanf("%s", peoples->name);
	printf("enter telephone:");
	scanf("%s", peoples->telephone);
}
struct People* find(struct People* people)
{
	struct People* current;
	printf("enter your name:");
	char news[20];
	scanf("%s", news);
	current = people;
	while (current != NULL && strcmp(current->name, news))
	{
		current = current->next;
	}
	return current;
}
void delete(struct Poleop** people)
{
	struct People* temp, * peoples, * current, * previous;
	peoples = find(*people);
	if (peoples == NULL)
	{
		printf("no finded it!\n");
	}
	else
	{
		current = *people;
		previous = NULL;
		while (current != NULL && current != peoples)
		{
			previous = current;
			current = current->next;
		}
		if (previous == NULL)
		{
			*people = current->next;
		}
		else
		{
			previous->next = current->next;
		}
		free(peoples);
	}
}
void set(struct People* people)
{
	struct People* peoples;
	int count = 1;
	peoples = people;
	while (peoples != NULL)
	{
		printf("%d: s", count);
		printf("name:%s\n", peoples->name);
		printf("   telephone:%s\n", peoples->telephone);
		peoples = peoples->next;
		count++;
	}
}
void see(struct People* peoples)
{
	printf("name:%s\n", peoples->name);
	printf("telephone:%s\n", peoples->telephone);
}
void display(struct People* people)
{
	struct People* current;
	current = people;
	while (current != NULL)
	{
		set(current);
		current = current->next;
	}
}
void frees(struct People** people)
{
	struct	People* temp;
	while (*people != NULL)
	{
		temp = *people;
		*people = (*people)->next;
		free(temp);
	}
}