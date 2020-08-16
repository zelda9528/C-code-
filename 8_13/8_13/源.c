#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 1;
	for (int a = 1; a <= 100; a++)
	{
		if (a % 2 != 0)
		{
			printf("%d ", a);
		}
		else
		continue;
	}
	return 0;
}