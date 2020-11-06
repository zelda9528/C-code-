#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

//×Ö·û´®µÄÄæÐò
void reverse(char*left, char*right)
{
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}

void reverse_string(char* str)
{
	char *st = str;
	char *ed = str+strlen(str)-1;
	while (*str)
	{
		char* start = str;
		char* end = str;
		while (*end != ' ' && *end != '\0')
		{
			end++;
		}
		//ÄæÐòµ¥´Ê
		reverse(start, end - 1);
		if (*end != '\0')
			str = end + 1;
		else
			str = end;
	}
	reverse(st, ed);
}
int main()
{
	char arr[100] = { 0 };
	gets(arr);
	//·­×ª
	//beijing. like I
	reverse_string(arr);
	printf("%s", arr);
	return 0;
}