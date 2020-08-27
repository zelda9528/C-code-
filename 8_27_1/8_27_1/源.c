#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Fib(int m)
{
	if (m <= 2)
		return 1;
	else
		return Fib(m - 1) + Fib(m - 2);
}
int main()
{
	int m = 0;
	int ret = 0;
	scanf("%d", &m);
	ret = Fib(m);
	printf("%d\n", ret);
	return 0;
}