#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>


int my_strcmp(const char*s1, const char* s2)
{
	assert(s1);
	assert(s2);

	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return 0;
		s1++;
		s2++;
	}
	return *s1 - *s2;
}
int main()
{
	char str1[]= "abcdef";
	char str2[]= "abcde";
	char str3[] = "abcdef";
	printf("%d\n", my_strcmp(str1, str2));
	printf("%d\n", my_strcmp(str1, str3));
	return 0;
}