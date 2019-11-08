#include<stdio.h>

int main()
{
	int murder;
	for (murder = 'A'; murder <= 'D'; murder++)
		if (((murder != 'A') + (murder == 'C') + (murder == 'D') + (murder != 'D')) == 3)
			printf("killer is %c\n", murder);
	return 0;
}