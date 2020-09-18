#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
int main()
{
	long n, p1, p2, e, i;
	scanf("%ld", &n);
	for (p1 = 3; p1 <= n / 2; p1 += 2)
	{
		e = (long)sqrt((double)p1);
		for (i = 2; i <= e; i++)
		{
			if (p1%i == 0) break;
		}
		if (i > e)
		{
			p2 = n - p1;
		}
		else
		{
			continue;
		}
		e = (long)sqrt((double)p2);
		for (i = 2; i <= e; i++)
		{
			if (p2%i == 0) break;
		}
		if (i > e)
		{
			printf("%ld=%ld+%ld\n", n, p1, p2);
			break;
		}
	}
	if (p1 > n / 2)
		printf("偶数%ld不符合哥德巴赫猜想", n);
	return 0;
}