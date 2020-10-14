#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int fun(int m, int n)
{
	if (n == 0) return m;
	return fun(n, m%n);
}
int main()
{
	int a, b ;
	scanf("%d%d", &a, &b);
	printf("%d ", fun(a,b));
	return 0;
}