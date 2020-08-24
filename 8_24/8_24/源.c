#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void mul(int n) 
{
	int i, j;
	for (i = 1; i <= n; ++i) 
	{
		for (j = 1; j <= i; j++) 
		{
			printf("%d*%d=%d ", j, i, i*j);
		}
		printf("\n");
	}
}

int main() 
{
	int n = 0;
	printf("请输入乘法口诀表的行数:");
	scanf("%d", &n);
	mul(n);
	return 0;
}