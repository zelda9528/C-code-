#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>



void Cinsert(int *arr,int n)
{
	for (int i = 0; i < n; i++)
	{
		int k = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[k])
				k = j;
		}
		if (k != i)
		{
			int tmp = arr[k];
			arr[k] = arr[i];
			arr[i] = tmp;
		}
	}
}

void test()
{
	int arr[] = { 9,5,6,4,8,7,3,2,1 };
	Cinsert(arr, 9);
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	test();
	return 0;
}