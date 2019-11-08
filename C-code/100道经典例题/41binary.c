#include<stdio.h>
#include<math.h>
/*十六进制转十进制*/
#pragma warning(disable:4996);
void toten(char arr[],int num)
{
	int ten = 0, n = 0;
	int i = 0;
	if (arr[i] == 'o')
	{
		++i;
		if (arr[i] == 'x' || arr[i] == 'X')
		{
			++i;
		}
		while (i <= num) {
			if (arr[i] >= '0' && arr[i] <= '9')
			{
				n = (int)(arr[i] - '0');
			}
			else if (arr[i] >= 'a' && arr[i] <= 'f')
			{
				n = (int)(arr[i] - 'a' + 10);
			}
			else if (arr[i] >= 'A' && arr[i] <= 'F')
			{
				n = (int)(arr[i] - 'A' + 10);
			}
			else
			{
				break;
			}
			ten += n*pow(16,num-1-i);
			i++;
		}
		printf("%d\n", ten);
	}
	else
	{
		printf("you don't add ox before the valus.\n");
	}
}
int main()
{
	char arr[10] = {"ox10"};
	int num = sizeof(arr) / sizeof(arr[0]); 
	for (int i = 0; i < num; i++)
	{
		if (arr[i]=='\0')
		{
			num = i;
			break;
		}
	}
	toten(arr, num);
	return 0;
}