#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int fun(int a, int b)
{
	if (a < b)
		return fun(a, b - a);
	else if (a > b)
		return fun(a - b, b);
	else return a;
}
int main()
{
	int a, b,ret;

	scanf("%d%d", &a, &b);
	ret = fun(a, b);
	printf("%d ",ret);
	return 0;
}
