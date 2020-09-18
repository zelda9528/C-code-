#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int i, j, n, a[10][10];
	scanf("%d", &n);//n控制行数
	for (i = 0; i < n; i++)
	{
		a[i][0] = a[i][i] = 1;
	}
	for (i = 0; i < n; i++)
	{
		for (j = 1; j < i; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	printf("\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1 - i; j++)printf("   ");//控制空格
		for (j = 0; j <= i; j++)
		{
			printf("%6d", a[i][j]);//2d=一个空格
		}
		printf("\n");
	}
	return 0;
}