#include<stdio.h>
#include<math.h>

int decimalist(int m);
void hexadecimal(int m);
int main()
{
	hexadecimal(decimalist(8955));
	return 0;
}

int decimalist(int m)
{
	int i=0,temp=0;
	while (m)
	{
		temp = m % 10 * pow(8, i)+temp;
		i++;
		m /= 10;
	}
	return temp;
}
void hexadecimal(int m)
{
	char arr[10] = {0};
	int ch=0;
	while (m)
	{
		if (m % 16 < 10)
		{
			arr[ch] = m % 16+ '0';
		}
		else
		{
			arr[ch] = m % 16 - 10 + 'a';
		}
		m /= 16;
		ch++;
	}
	for (int i = ch; i >= 0; i--)
	{
		printf("%c", arr[i]);
	}
}