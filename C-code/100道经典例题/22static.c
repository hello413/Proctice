#include "stdio.h"
main()
{
	int i, num;
	num = 2;
	for (i = 0; i < 3; i++)
	{
		printf("The num equal %d \n", num);
		num++;
		{
			static int num = 1;
			printf("The internal block num equal %d\n", num);
			num++;
		}
		printf("\n");
	}
}
