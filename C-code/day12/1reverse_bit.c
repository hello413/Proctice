#include<stdio.h>
#include<math.h>

unsigned int reverse_bit(unsigned int value);


int main()
{
	printf("%u", reverse_bit(25));
	return 0;
}

unsigned int reverse_bit(unsigned int value)
{
	int arr[32] = { 0 };
	int arr1[32] = { 0 };
	int i = 0;
	while (value)
	{
		arr[i++] = value % 2;
		value /= 2;
	}
	for (int i = 0; i < 32; i++)
	{
		arr1[i] = arr[31 - i];
	}
	unsigned int values = 0;
	for (int i = 0; i < 32; i++)
	{
		values += arr[i] * (pow(2, 31 - (double)i));
	}
	return values;
}