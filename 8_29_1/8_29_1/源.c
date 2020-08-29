#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int Strlen(char* str)
{
	 int i = 0;
	 while (*str != '\0')
		 {
		     ++str;
		     ++i;
		 }
	 return i;
}

int main()
{
	 char str[] = "abcdefgh";
	 printf("%d\n", Strlen(str));
	 return 0;
}