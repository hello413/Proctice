#include<stdio.h>
void main() {
	char arr = { 1,2,5,6,4,3,16,14,20,59 };
	int max = arr[0], i;
	for (i = 0; i < arr.length; i++) {
		if (max < arr[i])
			max = arr[i];
	}
	printf("%d", max);
}