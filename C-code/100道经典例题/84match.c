#include <stdio.h>
#include <stdlib.h>
/*假如现手中有m(m<=24)个火柴棍，希望拼出A+B=C等式。等式中的A、B、C均为火柴棍拼出来的整数（若该数非0，则最高位不能为0）。

注意：

    1、加号与等号各自需要2根火柴棍；
    2、如果A不等于B，则A+B=C与B+A=C视为不同的等式（三者均大于0）；
    3、所有根火柴棍必须全都用上。*/
#pragma warning(disable:4996)
int Fun(int n)
{
	//用数组列出0-9没一个数所需要的火柴棍数
	int arr[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
	int ret = 0;
	//判断n是不是两位数或更高位数
	while (n / 10 != 0) {
		//将个位数所需要的火柴棍数相加
		ret += arr[n % 10];
		//更新n的个位数
		n /= 10;
	}
	//最后加上此时n需要的火柴棍数(n是一位数)
	ret += arr[n];
	return ret;
}
int main()
{
	int a, b, c, m, num = 0;
	printf("请输入火柴棍的个数\n");
	scanf("%d", &m);
	//枚举a和b
	for (a = 0; a <= 7111; a++) {					//(24-4-2)/2=18/2=9 即1个7，3个1最大
		for (b = 0; b <= 7111; b++) {
			c = a + b;
			//判读是否符合条件
			if (Fun(a) + Fun(b) + Fun(c) == m - 4) {
				printf("%d + %d = %d\n", a, b, c);
				//计算所有可能的个数
				num++;
			}
		}
	}
	printf("一共可以拼出%d个不同等式\n", num);
	return 0;
}