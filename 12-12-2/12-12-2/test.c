#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main()
{
	int n, i, a, b, sum = 0;
	for (n = 10000; n < 100000; n++)
	{
		for (i = 1; i < 6; i++)
		{
			a = n / (int)pow(10, i);
			b = n % (int)pow(10, i);
			sum += a * b;
		}
		if (sum == n) printf("%d ", n);
		sum = 0;
	}
	return 0;
}