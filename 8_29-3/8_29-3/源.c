#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void reverse_string(char* string) 
{
	if ('\0' != *(++string)) 
	{
		reverse_string(string);
	}
	printf("%c", *(string - 1));
}
int main() 
{
	char *a = "zxcvbnm";
	reverse_string(a);
	printf("\n");
	return 0;
}