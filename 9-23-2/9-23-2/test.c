#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
void Reverse(char* str)
{
	char* left = str;
	char* right = str + strlen(str) - 1;
	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;
		++left;
		--right;
	}
}
int main()
{
	char str[] = "hello world";
	Reverse(str);
	printf("%s", str);
	return 0;
}