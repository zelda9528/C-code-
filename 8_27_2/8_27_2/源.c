#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a = 1;
	int b = 1;
	int c = 1;
	int m = 0;
	scanf("%d", &m);
	while (m > 2)
	{
		c = a + b;
		a = b;
		b = c;
		m--;
	}
	printf("%d ", c);
	return 0;
}
