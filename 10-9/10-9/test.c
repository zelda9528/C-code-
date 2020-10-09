#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
void print(int *arr[],int x,int y)
{
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 2,3,4,5,6 };
	int arr3[] = { 3,4,5,6,7 };
	int *arr4[] = { arr1,arr2,arr3 };
	print(arr4,3,5);
	return 0;
}
