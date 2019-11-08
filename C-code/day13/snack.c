#include"snack.h"

int main()
{
	welcome();
	int ch = 0;
	int choose = 0;
	while (!ch)
	{
		printf("enter your choose:>");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			game();
			break;
		case 0:
			ch = 1;
			break;
		default:
			printf("enter error!Please enter again:>");
			break;
		}
	}
	printf("ByeBye!!\n");
	return 0;
}


void welcome()
{
	printf("##########################\n");
	printf("#### Welcome to here! ####\n");
	printf("##########################\n");
	printf("#### 1.play    0.exit ####\n");
	printf("##########################\n");
}