#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

void fun(char*s, char c)
{
	int n = strlen(s);
	int i = 0;
	int j = 0;

	while(i<n)
	{
		while (s[i] != c)
		{
			j++;
			i++;
		}
		for (int k=n-1;k>n-j;k--)
		{
			s[k] = s[k - 1];
		}
		s[j++] = c;
		j++;
		i++;
	}
}

int main()
{
	char str[20] = {'a','b','a','b','a'};
	fun(str, 'b');
	printf("%s\n", str);
}

