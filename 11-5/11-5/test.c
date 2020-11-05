#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
int partition(int a[], int low, int high)  
{
	int pivotkey;
	pivotkey = a[low];//单纯的记录值
	while (low < high)//以pivoekey为交换媒介（枢轴），将大于它的放在后边，小于它的放在前面
	{
		while (low < high && a[high] >= pivotkey)//条件判断 low < high
			high--;
		swap(a, low, high);
		while (low < high && a[low] <= pivotkey)
			low++;
		swap(a, low, high);
	}
	return low;//返回枢轴所在位置
}
void QSort(int a[], int low, int high)
{
	int pivot;
	if (low < high)//是 if 
	{
		pivot = partition(a, low, high);//将a[]一分为二

		QSort(a, low, pivot - 1);//对低子表递归排序
		QSort(a, pivot + 1, high);//对高子表递归排序
	}
}
void quickSort(int a[], int low, int high)
{
	QSort(a, low, high);
}
int main()
{
	int i;
	int a[] = { 1,2,5,7,9,6,4,2,6,1 };
	quickSort(a, 0, 9);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}
