#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>



//用 ‘* ’ 打印K形图案
int main()
{
	int  n;
	while (scanf("%d", &n) != EOF)
	{
		for (int i = 1; i <= n+1; i++)
		{

			for (int j = i; j <= n+1; j++)
			{
				printf("* ");
			}
			printf(" \n");
		}
		for (int m = 2; m <= n+1; m++)
		{
			for (int k = 1; k <= m; k++)
			{
				printf("* ");
			}
			printf(" \n");
		}

	}
	return 0;
}
