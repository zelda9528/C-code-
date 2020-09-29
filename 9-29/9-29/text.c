#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<math.h>


int main()
{
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		//判断i是否为自幂数
		int sum = 0;
		//1. 计算i的位数 - n
		int tmp = i;
		int count = 1;
		while (tmp /= 10)
		{
			count++;
		}
		//2. 获得i的每一位，计算机每一位的n次方和
		tmp = i;
		while (tmp)
		{
			sum += pow(tmp % 10, count);
			tmp /= 10;
		}
		//3. 比较并打印
		if (i == sum)
		{
			printf("%d ", i);
		}
	}
	return 0;
}