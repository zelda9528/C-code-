#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <conio.h>

int main(void)
{
	char c;
	int l = 0, s = 0, n = 0, o = 0;

	printf("请输入字符串:\n");

	while ((c = getchar()) != '\n')
	{
		if (c >= 'A' && c <= 'z')
		{
			l++;
		}
		else if (c == ' ')
		{
			s++;
		}
		else if (c >= '0' && c <= '9')
		{
			n++;
		}
		else
		{
			o++;
		}
	}

	printf("输入字符串中有%d个字母,%d个空格,%d个数字,%d个其他字符\n", l, s, n, o);

	return 0;
}