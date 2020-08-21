#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main() 
{
	int left = 0; 
	int right = 9; 
	int mid;
	int n = 0;
	scanf("%d", &n);
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	while (left <= right)
	{
		mid = (left + right) / 2;
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
			printf("找到了！！下标是%d \n",left);
			break;
		}
	}

	while (left > right)
	{
		printf("找不到\n");
		break;
	}
	return 0;
}