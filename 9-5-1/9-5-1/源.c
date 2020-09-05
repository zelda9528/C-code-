#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void init(int arr[], int sz, int set)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		arr[i] = set;
	}
}

void print(int arr[],int sz)
{
	int j = 0;
	for (j = 0; j < sz; j++)
	{
		printf("%d ", arr[j]);
	}

}
void reverse(int arr[], int count)
{
	int i = 0, j = 0, b[10];
	for (i = 0; i < count; i++)
	{
		j = 10 - 1 - i;
		b[i] = arr[j];
		printf("%d ", b[i]);
	}

}
int main()
{
	int set = 0;
	int arr[10];
	int sz;
	sz = sizeof(arr) / sizeof(arr[0]);
	for (int j = 0; j < 10; j++)
	{
		scanf("%d", &arr[j]);
	}
	printf("打印数组:");
	print(arr, sz);
	printf("\n");
	printf("倒置数组：");
	printf("\n");
	reverse(arr, sz);
	printf("\n");
	printf("数组初始化:\n");
	init(arr, sz,set);
	print(arr, sz);	
	return 0;

}