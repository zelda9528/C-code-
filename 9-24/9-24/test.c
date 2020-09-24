#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int n = 0;
	scanf("%d", &n);//3
	int i = 0;
	int j = 0; 
	int ret = 1;
	int sum = 0;
	//n!
	//1!+2!+3!=1+2+6=9

	for (j = 1; j <= n; j++)//n=3
	{
		ret = 1;
		for (i = 1; i <= j; i++)
		{
			ret *= i;
		}
		sum = sum + ret;
	}

	printf("sum = %d\n", sum);

	return 0;
}