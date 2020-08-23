#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int x;
	char a[16];

	printf("请输入文本颜色代码(1-蓝,2-绿,4-红,6-黄,7-白):");
	scanf("%d", &x);

	sprintf(a, "color 0%d", x);
	system(a);
	printf("Hello world!\n");

	return 0;
}