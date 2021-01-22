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

//快速排序获取基准值--三数取中法
int  getmid(int *arr,int begin,int end)
{
	int mid = (begin + end) / 2;
	if (arr[begin] > arr[mid])
	{
		if (arr[mid] > arr[end])
			return mid;
		else if (arr[begin] > arr[end])
			return end;
		else
			return begin;
	}
	else
	{
		if (arr[end] < arr[begin])
			return begin;
		else if (arr[mid] > arr[end])
			return end;
		else
			return mid;
	}
}
//快速排序---Hoare
//快速排序--分组函数，返回基准值所在的位置
int Partion_Hoare(int *arr, int begin, int end)
{
	//获取基准值----若不进行此优化可能会导致函数栈溢出
	int mid = getmid(arr, begin, end);
	//将基准值放在begin位置
	Swap(arr, begin, mid);
	//保存基准值的位置
	int start = begin;
	while (begin < end)
	{
		//先从后向前找较小值
		while (begin<end&&arr[end] >= arr[start])
			end--;
		//再从前向后找较大值
		while (begin<end&&arr[begin] <= arr[start])
			begin++;
		//交换    大于基准值的放在后面，小的放在前面
		Swap(arr, begin, end);
	}
	//将基准值放在中间，此时左边的值小于基准值，右边大于基准值
	Swap(arr, start, begin);
	//返回交换后的基准值的位置
	return begin;
}

//快速排序--递归实现--Hoare
void Quick_sort_Hoare(int *arr, int begin, int end)
{
	if (begin >= end)
		return;

		int cur = Partion_Hoare(arr, begin, end);
		Quick_sort_Hoare(arr, begin, cur - 1);
		Quick_sort_Hoare(arr, cur + 1, end);
	
	
}

//快速排序--填坑法
//第一个位置为初始坑的位置
int  Partion_tk(int *arr, int begin, int end)
{
	//调整基准值
	int mid = getmid(arr, begin, end);
	Swap(arr, begin, mid);

	int key = arr[begin];
	while (begin < end)
	{
		//从后向前找小的
		while (begin < end&&arr[end] >= key)
			--end;
		//填坑
		arr[begin] = arr[end];
		//从前向后找大的
		while (begin < end&&arr[begin] <= key)
			++begin;
		//填坑
		arr[end] = arr[begin];
	}
	arr[begin] = key;
	return begin;
}

//快速排序--填坑法
void Quick_sort_tk(int *arr, int begin, int end)
{
	if (begin >= end)
		return;

	int cur = Partion_tk(arr, begin, end);
	Quick_sort_tk(arr, begin, cur - 1);
	Quick_sort_tk(arr, cur + 1, end);

}


//快速排序分区--前后指针法
int Partion_qh(int * arr, int begin, int end)
{
	//调整基准值
	int mid = getmid(arr, begin, end);
	Swap(arr, begin, mid);

	int prev = begin;
	int cur = begin + 1;
	int key = arr[begin];
	while (cur <= end)
	{
		if (arr[cur]<key&&++prev != cur)
			Swap(arr, prev, cur);
		else 
		++cur;

	}
	Swap(arr, begin, prev);
	return prev;
}

//快速排序--前后指针法
void Quick_sort_qh(int *arr, int begin, int end)
{
	if (begin >= end)
		return;

	int cur = Partion_qh(arr, begin, end);
	Quick_sort_qh(arr, begin, cur - 1);
	Quick_sort_qh(arr, cur + 1, end);

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
			Swap(arr, k, i);
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
	int arr[] = { 9,5,6,4,8,7,3,2,1 };   //9个数
	for (int i = 0; i < 9; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	Select_insert1(arr, 9);
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