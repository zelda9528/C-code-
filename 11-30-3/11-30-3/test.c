#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


int main(void)
{
	char ch;
	while (scanf("%c", &ch) != EOF)
	{
		getchar();
		printf("%c\n", ch + 32);
	}
}