#define _CRT_SECURE_NO_WARNINGS 1

#define SwapIntBit(n) (((n) & 0x55555555) << 1 | ((n) & 0xaaaaaaaa) >> 1)

#include<stdio.h>
int main()
{

	printf("%d\n",  SwapIntBit(1));
	return 0;
 }