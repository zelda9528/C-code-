#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>



int main()
{
	//int a = 10;
	//int b = a++;//后置++ -----> 先使用a，再给a 自增1
	//printf("a=%d b=%d\n", a, b);//11 10

	//int b = ++a;//前置++   -----> 先给啊自增1，再使用a 
	//printf("a=%d b=%d\n", a, b);//11 11

	//int a = 10;
	////int b = a--;
	//int b = --a;

	//printf("a=%d b=%d\n", a, b);//9 9

	int a = 10;
	printf("%d\n", ++a);//

	return 0;
}