#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include <assert.h>
void search(int a[], int num)
{
	assert(a);
	assert(num > 0);
	int *x = (int *)malloc(sizeof(int *));
	int *y = (int *)malloc(sizeof(int *));
	*x = 0;
	*y = 0;
	//全部进行按位与，根据相同数字按位与为零不同为一，因此结果一定不为零，且32个比特位上至少有一位为1。
	int sum = a[0];
	for (int i = 0; i < num; i++)
	{
		sum ^= a[i];
	}
	//找到最低位第一次出现1的位置，记为pos，因为此时的1一定是不同的两个数相应位置上的1和0亦或得到的。
	int pos = 1;
	{
		while (sum & 1)
		{
			sum = sum >> 1;
			pos = pos << 1;
		}
	}
	//根据pos位置上的01值不同，将数组划分为两个数组，并各自亦或，得出每个数组出现一次的数字
	for (int i = 0; i < num; i++)
	{
		if (a[i] & pos)
		{
			*x ^= a[i];
		}
		else
		{
			*y ^= a[i];
		}
	}
	printf("%d %d", *x, *y);
}
int main(void)

{

	int a[] = { 1, 2, 3, 7, 4, 5, 1, 2, 3, 7 };
	int num = sizeof(a) / sizeof(a[0]);
	search(a, num);

}