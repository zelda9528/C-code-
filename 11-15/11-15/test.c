#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define PRINT_LOG printf("file:%s line:%d date:%s time:%s: %d\n", __FILE__, \
					__LINE__,\
					__DATE__,\
					__TIME__)



int main()
{
	PRINT_LOG;
	return 0;
}