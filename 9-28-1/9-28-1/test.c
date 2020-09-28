#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
size_t my_strlen1(const char* string)
{
	//count 来记录字符串的长度
	size_t count = 0;
	//判断参数为空的话返回一个错误的值
	if (string == NULL)
	{
		return -1;
	}
	//遍历数组，指针后调并且计数
	while (*string != '\0')
	{
		count++;
		string++;
	}
	return count;
}
int main()
{
	char string[] = "hello world";
	printf("%lu\n", my_strlen1(string));
	return 0;
}