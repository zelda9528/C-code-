#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int Strlen(const char* str)
{
	if (*str == '\0')
		return 0;
	else
		return 1 + Strlen(str + 1);
}
int main()
{
	char *str = "zxcvbnm";
	int ret = Strlen(str);
	printf("%d ", ret);
	return 0;
}
