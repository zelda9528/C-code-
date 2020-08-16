#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main(void)
{
	int a, b;

	printf("请输入学生成绩:");
	scanf("%d", &a);

	((a >= 90) ? printf("A\n") : ((a > 60 && a < 90) ? printf("B\n") : printf("C\n")));
	return 0;
}