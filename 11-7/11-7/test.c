#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
void reverse(char*left,char*right)
{
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void reverse_string(char*str)
{
	char*st = str;
	char*ed = str+strlen(str) - 1;
	while (*str)
	{
		char*start = str;
		char*end = str;
		while (*end != ' '&&*end != '\0')
		{
			end++;
		}
		reverse(start, end-1);
		if (*end !='\0')
			str = end + 1;
		else
			str = end;
	}
	reverse(st, ed);
}

int main()
{

	char str[100] = { 0 };
	gets(str);
	reverse_string(str);
	printf("%s\n", str);
	return 0;
}