#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	char ch[10];
	int i;
	scanf("%s", ch);
	for (i = 0; ch[i] != '\0'; i++)
	{
		if ('a' <= ch[i] && ch[i] <= 'z')
		{
			printf("%c", ch[i] - 32);
		}
		else
		{
			printf("%c", ch[i]);
		}
	}
	return 0;
}
