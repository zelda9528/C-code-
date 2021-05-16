#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//
//int check_sys()
//{
//	union Un
//	{
//		int i;
//		char c;
//	}u;
//	printf("%p ", &u.c);
//	printf("%p ", &u.i);
//
//	u.i = 1;
//	//返回0，表示大端
//	//返回1，表示小端
//	return u.c;
//}


int check_sys()
{
	int a = 1;
	char b = a;

	if (b == 0)
		return 0;
	else if (b == 1)
		return 1;
	else
		return -1;
}

int main()
{
	int ret = check_sys();
	if (ret == 1)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	return 0;
}