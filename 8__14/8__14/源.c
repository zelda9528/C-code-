#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 0;
	do
	{
		i += 3;
		printf("%d ", i);
	}
	while (i <= 96);
	printf("%d", i);
	return 0;
}