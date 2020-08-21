#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	printf("100~200之间的素数有：");
	int i = 0;
	int j = 0;
	for (i = 100; i <= 200; i++)
	{
		for (j = 2; j <= 200; j++)
		{
			if (i%j == 0)
				break;
			else
				printf("%d ", i);
			    break;
		}
	}
	return 0;
}