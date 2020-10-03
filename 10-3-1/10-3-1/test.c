#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	unsigned char a = 200;
	unsigned char b = 100;
	unsigned char c = 0;
	c = a + b;
	printf("%d %d ", a + b, c);
	return 0;
}