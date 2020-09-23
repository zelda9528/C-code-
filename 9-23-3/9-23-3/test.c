#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define P 1 //汽水的单价
#define N 2 //换一瓶汽水所需的空瓶个数

//SodaConvert函数返回用空瓶换来的汽水个数
int SodaConvert(int x)
{
	int ret = x / N;//空瓶兑换的汽水个数
	int empty = x / N + x % N;//兑换的汽水和剩下的空瓶个数之和
	if (empty > 1)
		return ret + SodaConvert(empty);
	else
		return ret;
}
int main()
{
	int p = 0;
	int n = 0;
	printf("请输入金额：");
	scanf("%d", &p);
	n = p / P;
	int bottle = n + SodaConvert(n);//最终喝到的汽水个数
	printf("%d瓶\n", bottle);
	return 0;
}