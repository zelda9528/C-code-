#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i = 0, a = 0, b = 2, c = 3, d = 4;
	i = a++ && ++b && d++;
	printf("a = %d\n b = %d\n c = %d\nd = %d\n", a, b, c, d);
	int  z = 0, x = 2, v = 3, n = 4;
	i = z++||++x||n++;
	printf("z = %d\n x = %d\n v = %d\nn = %d\n", z, x, v, n);
	return 0;
}