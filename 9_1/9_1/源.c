#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a, b, c, d;
	printf("1000以内的水仙花数为:\n");
	for (a = 100; a < 1000; a++)
	{
		b = a / 100;
		c = (a / 10) % 10;
		d = a % 10;
		if (b*b*b + c * c*c + d * d*d == a)
		{
			printf("%d", a);
			printf("\n");
		}
		else
			continue;

	}
}