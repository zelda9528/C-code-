#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

int Add(int x, int y)
{
	return x + y;
}

int main()
{
	

	//函数指针的问题

	//是一个指向函数的指针 - 存放函数的地址

	//int (*pf)(int, int) = &Add;

	int(*pf)(int, int) = Add;

	int sum = (*pf)(2, 3);

	sum = pf(2, 3);

	printf("%d\n", sum);

	sum = Add(2, 3);

	printf("%d\n", sum);

	//int (*ps)(const char*) = &my_strlen;

	//printf("%p\n", &Add);

	//printf("%p\n", Add);

	//函数名是函数的地址

	//&函数名还是函数的地址

	return 0;
}