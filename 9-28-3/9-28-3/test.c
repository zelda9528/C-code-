//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#include<string.h>
//char * my_strcpy(char * dst, const char * src)
//{
//	char * cp = dst;
//	while (*cp++ = *src++);
//	return(dst);
//}
//int main()
//{
//	char arr = "1234567";
//	char*p = arr;
//	printf("%s ", my_strcpy(p, "zxcvbnm"));
//	return 0;
//}



#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
char * my_strcpy(char *dst, const char *src)
{
	char *ret = dst;
	while (*ret++ = *src++)
		;
	return dst;
}
int main()
{
	char arr[] = "123456";
	printf("%s\n", my_strcpy(arr, "abcdef"));
	return 0;
}