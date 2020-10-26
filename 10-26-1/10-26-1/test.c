#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

char* my_strcpy(char* dest, const char* src)
{
	char *ret = dest;
	assert(dest != NULL);
	assert(src != NULL);

	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char* str1 = "abcde";
	char arr[20] ="XXXXXXXXX";
	my_strcpy(arr, str1);
	printf("%s\n", arr);

	return 0;
}