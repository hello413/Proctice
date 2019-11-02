#include"game.h"

int main()
{
	start();
	int choose;
	int flag = 0;
	while (!flag)
	{
		printf("please choose :>");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			game();
			//printf("Are you want to play again?\n");
			break;
		case 0:
			flag = 1;
			printf("ByeBye!\n");
			break;
		default:
			printf("enter error! please enter again!\n");
			break;
		}
	}
	return 0;
}