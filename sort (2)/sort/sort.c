#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

void Swap(int *arr, int x, int y)
{
	int tmp = arr[x];
	arr[x] = arr[y];
	arr[y] = tmp;
}

//插入排序
void Insort(int* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		//最后一个有序位置
		int end = i - 1;
		int data = arr[i];
		while (end >= 0 && arr[end] > data)
		{
			arr[end + 1] = arr[end];
			--end;
		}
		arr[end + 1] = data;
	}
}

//希尔排序
void Shell_sort(int* arr, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < n; i++)
		{
			int end = i - gap;
			int data = arr[i];
			while (end >= 0 && arr[end] > data)
			{
				arr[end + gap] = arr[end];
				end-=gap;
			}
			arr[end + gap] = data;
		}
	}
}

//冒泡排序-1
void bubble_sort(int *arr, int sz)
{
	int end = sz;
	while (end > 0)
	{
		for (int i = 0; i < end - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int tmp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = tmp;
			}
		}
		end--;
	}

	//冒泡排序-2
	//int i = 0;
	//for (i = 0; i < sz - 1; i++)
	//{
	//	int j = 0;
	//	for (j = 0; j < sz - 1 - i; j++)
	//	{
	//		if (arr[j] > arr[j + 1])
	//		{
	//			int tmp = arr[j];
	//			arr[j] = arr[j + 1];
	//			arr[j + 1] = tmp;
	//		}
	//	}
	//}
}

//快速排序--分组函数，返回基准值所在的位置
int Partion(int *arr, int begin, int end)
{
	int start = begin;
	while (begin < end)
	{
		while (begin<end&&arr[end] >= arr[start])
			end--;
		while (begin<end&&arr[begin] <= arr[start])
			begin++;
		Swap(arr, begin, end);
	}
	Swap(arr, start, begin);
	return begin;
}

//快速排序--递归实现
void Quick_sort(int *arr, int begin, int end)
{
	if (begin >= end)
		return;

		int cur = Partion(arr, begin, end);
		Quick_sort(arr, begin, cur - 1);
		Quick_sort(arr, cur + 1, end);
	
	
}

//选择排序-1
void Select_insert1(int *arr, int n)
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

//选择排序-2
void Select_insert2(int *arr, int n)
{
	int start = 0;
	int end = n - 1 ;
	while (start < end)
	{ 
		int min = start;
		int max = start;
		for (int j = start + 1; j <= end; j++)
		{
			if (arr[j] < arr[min])
				min = j;
			if (arr[j] > arr[max])
				max = j;
		}
		Swap(arr, start, min);
		if (max == start)
			max = min;
		Swap(arr, end, max);
		start++;
		end--;
	}
}


void test()
{
	int arr[] = { 9,5,6,4,8,7,3,2,1 };   //8个数
	Quick_sort(arr, 0, 8);
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