#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>



MAX(int x, int y)
{
	printf("请输入两个要比较的数\n");

	scanf("%d%d", &x, &y);

	if (x >= y)

	{

		int z = x;

		printf("较大的数为%d\n", z);

		return z;

	}

	else

	{

		int z = y;

		printf("较大的数为%d\n", z);

		return z;

	}

}

int main()

{
	int x = 0;
	int y = 0;

	MAX(x, y);

	return 0;

}