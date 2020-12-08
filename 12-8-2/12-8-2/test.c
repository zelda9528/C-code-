#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void reverse(int* arr, int left, int right)
{
	while (left < right)
	{
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}

void rotate(int *arr,int numsize,int k)
{
	reverse(arr, 0, k);
	reverse(arr, k + 1, numsize - 1);
	reverse(arr, 0, numsize - 1);
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	int n = sizeof(arr)/sizeof(arr[0]);
	rotate(arr, n, 3);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}