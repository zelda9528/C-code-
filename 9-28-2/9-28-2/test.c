#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

size_t my_strlen(const char * str)
{
	const char *eos = str;
	while (*eos++);
	return(eos - str - 1);
}
int main()
{
	char arr[] = "hello world";
	const char*p = arr;
	my_strlen(p);
	
	printf("%lu ", my_strlen(p));
	return 0;
}