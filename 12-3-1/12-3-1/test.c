#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n, h, m;
	while (EOF != scanf("%d %d %d", &n, &h, &m))
		printf("%d", n - (m / h) - (m%h));
}