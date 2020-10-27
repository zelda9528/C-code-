#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

char *my_strstr(const char* str1, const char* str2)
{
	assert(str1);
	assert(str2);

	char *cp = (char*)str1;
	char *substr = (char *)str2;
	char *s1 = NULL;

	if (*str2 == '\0')
		return NULL;

	while (*cp)
	{
		s1 = cp;
		substr = str2;
		while (*s1 && *substr && (*s1 == *substr))
		{
			s1++;
			substr++;
		}
		if (*substr == '\0')
			return cp;
		cp++;
	}
}

int main()
{
	char str1[] = "abbbcdefgh";

	char str2[]= "bbcde";

	printf("%s ",my_strstr(str1, str2));


	return 0;
}




