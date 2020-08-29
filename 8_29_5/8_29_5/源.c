#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int exp(int i, int j)
{
	int count=1;
	int sub = i;
	while (count < j)
	{
		sub *= i;
		count++;
	}
	return sub;
}
int main()
{
	int n, k,  e;
	scanf("%d%d", &n,&k);
	e = exp(n, k);
	printf("%d", e);
	return 0;
}