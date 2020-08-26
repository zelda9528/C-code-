#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void Printf(int n)
{
	if (n > 9)
	{
		printf("%d", n / 10);
	}
	printf("%d ", n % 10);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	Printf(n);
	return 0;
}