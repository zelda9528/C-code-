#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>int 
int Strlen(char* str)
{
	if (*str == '\0')
	{
		 return 0;
	}
    else
	{
        return 1 + Strlen(++str);
	}
}
int main()
{
	char str[] = "abcdefg";
    printf("%d\n", Strlen(str));
    return 0;
}