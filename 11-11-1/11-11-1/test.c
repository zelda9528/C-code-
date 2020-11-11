#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int birthday;
	scanf("%d", &birthday);
	printf("year=%d\n", birthday / 10000);
	birthday %= 10000;
	printf("month=%02d\n", birthday / 100);
	printf("date=%02d\n", birthday % 100);
	return 0;
}