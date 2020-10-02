/*
思路：
1. 给定两个下标left和right，left放在数组的起始位置，right放在数组中最后一个元素的位置
2. 循环进行一下操作
 a. 如果left和right表示的区间[left, right]有效，进行b，否则结束循环
 b. left从前往后找，找到一个偶数后停止
 c. right从后往前找，找到一个奇数后停止
 d. 如果left和right都找到了对应的数据，则交换，继续a，
*/
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
void swap_arr(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	int tmp = 0;
	while (left < right)
	{
		while ((left < right) && (arr[left] % 2 == 0))
		{
			left++;
		}
		while ((left < right) && (arr[right] % 2 == 1))
		{
			right--;
		}
		if (left < right)
		{
			tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
		}
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	swap_arr(arr, sz);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}