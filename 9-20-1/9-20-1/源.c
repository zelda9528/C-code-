#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
int main()
{
	char str[] = "hello world";
	printf("%d %d", sizeof(str), strlen(str));
	return 0;

}