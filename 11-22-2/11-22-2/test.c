#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 6 };
	int ret = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	int pos = 0;
	int num1 = 0;
	int num2 = 0;

	for (i = 0; i < sz; i++)
	{
		ret ^= arr[i];
	}
	//计算ret的哪一位为1
	//000000000000000000000000000000011
	for (i = 0; i < 32; i++)
	{
		if (((ret >> i) & 1) == 1)
			break;
	}
	pos = i;
	for (i = 0; i < sz; i++)
	{
		if (((arr[i] >> pos) & 1) == 1)
		{
			num1 ^= arr[i];
		}
	}
	num2 = ret ^ num1;
	printf("%d %d\n", num1, num2);

	return 0;
}

