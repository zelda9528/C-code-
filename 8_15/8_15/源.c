#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int isLeapYear(int i)
{
	if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))//判断闰年的条件：能被4整除并且不能被100整除或者能被400整除
		return 1;//判断是闰年
	else
		return 0;//判断不是闰年
}

int main()
{
	int i = 0;
	printf("1999-2020年之间闰年：");
	for (i = 1999; i <= 2020; i++) //1999-2020之间的闰年
	{
		if (isLeapYear(i))
			printf("%d ", i);
	}
	printf("\n");
}