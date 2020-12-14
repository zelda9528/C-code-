#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	char c;
	while (scanf("%c", &c) != EOF)
	{
		getchar();
		if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))
			printf("%c is an alphabet.\n", c);
		else
			printf("%c is not an alphabet.\n", c);
	}
	return 0;
}