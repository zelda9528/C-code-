#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<ctype.h>
#include<assert.h>
int my_atoi(const char* str)
{
	int flag = 0;//正负数的标志
	//空指针处理
	assert(str);
	
	//空白字符处理
	while (isspace(*str))
	{
		str++;
	}
	//处理+号
	if (*str == '+')
	{
		str++;
		flag = 1;
	}
	//处理-号
	else if (*str == '-')
	{
		str++;
		flag = -1;
	}
	int ret = 0;

	while (*str)
	{
		ret = ret * 10 + flag*(*str - '0');
		str++;
	}
	return ret;
}


int main()
{
	char*p = "   -123456";
	int ret = my_atoi(p);
	printf("%d\n", ret);
	return 0;
}