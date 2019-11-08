#include<stdio.h>

int main() {
	int arr[] = { 3, 4, 5, 3, 4 };
	int result = 0;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		result = result ^ arr[i];
	}
	printf("%d\n", result);
	return 0;
}