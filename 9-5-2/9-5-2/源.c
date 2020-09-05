#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void print(int arr[])
{
	int j = 0;
	for (j = 0; j < 5; j++)
	{
		printf("%d ", arr[j]);
	}
	printf("\n");
}
int main()
{
	int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,0 };
	printf("原始数组为:\n");
	print(a);
	print(b);
	for (int i = 0; i < 5; i++)
	{
		int tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
	}
	printf("交换后的数组为：\n");
	print(a);
	print(b);
	return 0;
}