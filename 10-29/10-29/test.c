#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

unsigned fun(unsigned);
int main()
{
	unsigned num = 26;
	printf("%d", fun(num));
	return 0;
}
unsigned fun(unsigned num)
{
	unsigned k = 1;
	do
	{
		k *= num % 10;
		num /= 10;
	} 
	while (num);
	return(k);
}