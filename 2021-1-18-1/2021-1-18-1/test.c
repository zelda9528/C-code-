#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//void insert(int * arr, int n)
//{
//	while (n-1)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			
//		}
//	}
//
//}


void insert(int *arr, int n)
{
	for (int i = 1; i < n; i++) 
	{
	//	int data = arr[n-1];
	//	int end = i - 1;
	//	int j = i-1;
	//	while (data > arr[j])
	//	{
	//		j++;
	//	}
	//	for (int k = j; n - 1 > k; k++)
	//	{
	//		arr[n - 1] = arr[n - 2];
	//		n--;
	//	}
	//	arr[j] = data;









		if (arr[i] < arr[i - 1]) 
		{
			int j = i - 1;
			int x = arr[i];
			while (j > -1 && x < arr[j]) 
				arr[j + 1] = arr[j];
				j--;
		}
	}
}

void print_arr(int *arr,int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void test()
{
	int arr[] = { 1,8,4,9,3,2,6 };
	int n = sizeof(arr)/sizeof(arr[0]);
	print_arr(arr, n);
	insert(arr, n);
	print_arr(arr, n);
}

int main()
{
	test();
	return 0;
}