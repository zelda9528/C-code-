#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int main()
{
	char ch;
	while (scanf("%c", &ch) != EOF)
	{
		getchar();

		if (ch >= 'a' && ch <= 'z')
			ch -= 32;
		if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
			printf("Vowel\n");
		else
			printf("Consonant\n");
	}
	return 0;
}
