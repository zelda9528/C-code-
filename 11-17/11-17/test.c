#define _CRT_SECURE_NO_WARNINGS 1

#define ZHANGSAN 0
#include<stdio.h>

int main()
{
	#if defined(ZHANGSAN)
		printf("张三\n");
	#endif

	#if !defined(ZHANGSAN)
		printf("张三\n");
	#endif

	#ifdef ZHANGSAN
		printf("zhangsan\n");
	#endif

	#ifndef ZHANGSAN
		printf("zhangsan\n");
	#endif

		return 0;
}
