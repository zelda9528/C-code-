#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>

char* my_strcpy(char* dest, const char* src,int num)
{
	char *ret = dest;
	assert(dest != NULL);
	assert(src != NULL);

	/*while (*dest++ = *src++)
	{
		;
	}*/

	for (int i = 0; i < num; i++)
	{
		*dest++ = *src++;
	}
	return ret;
}
int main()
{
	int num = 0;
	scanf("%d", &num);
	char* str1 = "abcdefghijklmnopqrstuvwxyz";
	char arr[50] = "XXXXXXXXXXXXXXXXXXXXXXXXX";
	my_strcpy(arr, str1,num);
	printf("%s\n", arr);
	return 0;
}