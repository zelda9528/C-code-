#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。
//《剑指offer》

void move_arr(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;

	while (left<right)
	{
		//从左边找一个偶数
		while ((left<right) && (arr[left] % 2 == 1))
		{
			left++;
		}
		//从右边找一个奇数
		while ((left<right) && (arr[right] % 2 == 0))
		{
			right--;
		}
		if (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}

void print_arr(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	//1 3 5 7 9 
	//2 4 6 8 10
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//10
	int sz = sizeof(arr) / sizeof(arr[0]);
	print_arr(arr, sz);
	move_arr(arr, sz);
	print_arr(arr, sz);
}