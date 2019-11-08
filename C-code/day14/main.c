#include"pushbox.h"

void start()
{
	printf("###########################\n");
	printf("### Welcome to come here###\n");
	printf("###########################\n");
	printf("#### 1.play    0.exit #####\n");
	printf("###########################\n");
}

int main()
{
	start();
	int ch = 0;
	int choose = 0;
	while (!ch)
	{
		printf("Please choose:>");
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			game();
			for (int i = 3; i > 0; i--)
			{
				Sleep(500);
				printf("%d\r", i);
			}
			system("cls");  // Çå¿ÕÆÁÄ»
			start();
			printf("Are you again?\n>");
			break;
		case 0:
			ch = 1;
			break;
		default:
			printf("enter error, please enter again!\n");
			break;
		}
	}
	printf("ByeBye!!\n");
	return 0;
}