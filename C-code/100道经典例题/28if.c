#include "stdio.h"
#define MAX
#define MAXIMUM(x,y) (x>y)?x:y
#define MINIMUM(x,y) (x>y)?y:x
void main()
{
	int a = 10, b = 20;
#ifdef MAX
	printf("1: The larger one is %d\n", MAXIMUM(a, b));
#else
	printf("2: The lower one is %d\n", MINIMUM(a, b));
#endif
#ifndef MIN
	printf("3: The lower one is %d\n", MINIMUM(a, b));
#else
	printf("4: The larger one is %d\n", MAXIMUM(a, b));
#endif
#undef MAX
#ifdef MAX
	printf("5: The larger one is %d\n", MAXIMUM(a, b));
#else
	printf("6: The lower one is %d\n", MINIMUM(a, b));
#endif
#define MIN
#ifndef MIN
	printf("7: The lower one is %d\n", MINIMUM(a, b));
#else
	printf("8: The larger one is %d\n", MAXIMUM(a, b));
#endif
}
