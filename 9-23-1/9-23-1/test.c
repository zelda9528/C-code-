#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	printf("请输入一个1~9之间的整数：\n");
	int a;
	scanf("%d", &a);
	int Sn = 0;
	int i;
	int temp = 0;
	for (i = 0; i < 5; i++) {
		Sn = Sn + a * pow(10, i);    //取得每一个数
		temp = temp + Sn;        //将已经取过的数的和算出来
	}
	printf("%d\n", temp);
	return 0;
}