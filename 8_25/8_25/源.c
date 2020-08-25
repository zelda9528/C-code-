#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int find(int arr[], int n, int sz)
{
	int left = 0;
	int right=sz-1;
	while (left<=right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] < n)
		{
			left = mid + 1;
		}
		else if (arr[mid] > n)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int i = 7;
	int sz=sizeof(arr);
	int ret = 0;
	ret = find(arr, i, sz);
	if (ret == -1)
	{
		printf("找不到\n");
	}
	else
	{
		printf("找到了，下标是：%d\n", ret);
	}
}
