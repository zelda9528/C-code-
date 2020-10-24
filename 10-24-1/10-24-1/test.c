#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

void left_move(char* str, int n)
{
	int i = 0;
	int len = strlen(str);
	for (i = 0; i < n; i++)
	{
		char tmp = *str;
		int j = 0;
		for (j = 0; j < len - 1; j++)
		{
			*(str + j) = *(str + j + 1);
		}
		*(str + len - 1) = tmp;
	}
}

int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "cdefab";
	int i = 0;
	int len = strlen(arr1);

	for (i = 0; i < len; i++)
	{
		left_move(arr1, 1);
		if (strcmp(arr1, arr2) == 0)
		{
			printf("YES\n");
			break;
		}
	}
	if (i == len)
	{
		printf("No\n");
	}
	return 0;
}