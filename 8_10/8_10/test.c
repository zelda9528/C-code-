#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 0;
	printf("请输入一个数\n");
	scanf("%d", &a);
	if (a % 2 == 0)
	{
		printf("a为偶数\n");
	}
	else
	{
		printf("a为奇数\n");
	}
	return 0;
}