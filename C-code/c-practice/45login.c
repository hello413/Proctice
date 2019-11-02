#include <stdio.h>
#include <windows.h>
#include <time.h>
//#pragma warning(disable:4996)

int Fact(int n) //3
{
	int sum = 1;
	printf("%d! : ", n);
	for (; n > 0; n--) {
		if (n == 1) {
			printf("%d=", n);
		}
		else {
			printf("%d*", n);
		}
		sum *= n; //1*=3;
	}
	printf("%d\n", sum);
	return sum;
}

#define M 198989

#define USER "tom"
#define PSD  "123456"

void Menu()
{
	printf("#################################\n");
	printf("## 1. Play             2. Exit ##\n");
	printf("#################################\n");
	printf("Please Select> ");
}

void Play()
{
	int n = rand() % 100 + 1;
	int x = 0;
	do {
		printf("guess# ");
		scanf_s("%d", &x);
		if (x > n) {
			printf("guess big!\n");
		}
		else if (x < n) {
			printf("guess small!\n");
		}
		else {
			printf("you are right! : %d\n", x);
			break;
		}
	} while (1);
}

int main()
{
	printf("///USER:tom    PASSWD:123456///////\n");
	char name[32] = { 0 };
	char passwd[32] = { 0 };
	int count = 3;
	while (count > 0) {
		count--;
		printf("Please Enter Your name# ");
		scanf_s("%s", name, strlen(name));
		gets(name);
		printf("Please Enter Your Passwd# ");
		gets(passwd);
		if (strcmp(USER, name) == 0 && strcmp(PSD, passwd) == 0) {
			break;
		}
		else {
			printf("name or passwd error, try agagin! you have %d times\n", count);
		}
	}
	if (count > 0) {
		printf("login success!\n");
		int i = 5;
		while (i > 0) {
			printf("loading ... %d\r", i);
			Sleep(1000);
			i--;
		}
		printf("loading ... done!\n");

		srand((unsigned long)time(NULL)); //随机数种子
		int quit = 0;
		while (!quit) {
			Menu();
			int select = 0;
			scanf_s("%d", &select);
			switch (select) {
			case 1:
				Play();
				break;
			case 2:
				printf("ByeBye!\n");
				quit = 1;
				break;
			default:
				printf("Enter Error!\n");
				break;
			}
		}

	}
	else {
		printf("login failed!\n");
	}
	return 0;
}
