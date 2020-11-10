#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <limits.h>
#include <ctype.h>

enum State
{
	VALID,//合法
	INVALID//非法
}state = VALID;

int my_atoi(const char* str)
{
	int flag = 0;
	state = INVALID;//默认输入非法
	//空指针
	if (str == NULL)
		return 0;
	if (*str == '\0')
		return 0;
	//空白字符的处理
	while (isspace(*str))
	{
		str++;
	}
	//判断+-
	if (*str == '+')
	{
		flag = 1;
		str++;
	}
	else if (*str == '-')
	{
		flag = -1;
		str++;
	}
	long long ret = 0;
	//flag = -1
	while (isdigit(*str))
	{
		ret = ret * 10 + flag*(*str - '0');
		if (ret > INT_MAX || ret < INT_MIN)
		{
			ret = 0;
			return (int)ret;
		}
		str++;
	}
	if (*str == '\0')
	{
		state = VALID;
		return (int)ret;
	}
	return (int)ret;
}


int main()
{
	char*p = "  -123";
	int ret = my_atoi(p);
	if (state == VALID)
	{
		printf("%d\n", ret);
	}
	else
	{
		printf("%d\n", ret);
	}
	return 0;
}