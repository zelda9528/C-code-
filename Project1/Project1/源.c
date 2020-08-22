#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 0;
	int j = 1;
	int n = 0;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9; j++)
			printf("%d*%d=%d ", i, j, i*j);
	}
	return 0;
}