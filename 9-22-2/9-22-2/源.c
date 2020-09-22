#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int main()
{
	int i, j, k;
	int n;
	printf("请输入一个奇数:");
	scanf("%d", &n);//菱形的行数
	n = n / 2 + 1;
	//打印上半个三角形
	for (i = 1; i < n; i++)//控制行数,上半部分比下半部分少一行
	{
		for (j = i; j < n; j++)
		{
			printf(" ");
		}
		for (k = 1; k <= 2 * i - 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	//打印下半部分的倒三角形
	for (i = 1; i <= n; i++)//控制行数,下半部分比上半部分多一行
	{
		for (j = 1; j < i; j++)
		{
			printf(" ");
		}
		for (k = n * 2 - 1; k >= 2 * i - 1; k--)
		{
			printf("*");
		}
		printf("\n");
	}
	return 0;
}