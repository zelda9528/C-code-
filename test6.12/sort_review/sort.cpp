#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<cstdio>
#include<time.h>
#include<stdlib.h>
#include<climits>

using namespace std;

void Swap(int *a, int*b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

// 插入排序
void InsertSort(int* a, int n)
{	
	for (int i = 0; i < n - 1; i++)
	{
		//将tmp插入到[0,end]这个有序序列
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

// 希尔排序
void ShellSort(int* a, int n) 
{
	int gap=n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;// +1 ---- 保证最后一次gap=1

		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
				a[end + gap] = tmp;
			}
		}
	}	
}

// 选择排序
void SelectSort(int* a, int n) 
{
	int left = 0, right = n-1 ;
	while (left <= right)
	{
		int max = left, min = left;
		for (int i = left; i <= right; i++)
		{
			if (a[i] < a[min])
				min = i;
			if (a[i] > a[max])
				max = i;
		}
		swap(a[min], a[left]);
		//特殊错误处理
		if (left == max)
		{
			max = min;
		}
		swap(a[max], a[right]);
		left++;
		right--;
	}
}

// 堆排序
void AdjustDwon(int* a, int n, int root) 
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child<n)
	{
		if (child + 1 < n&&a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child]>a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}

void HeapSort(int* a, int n) 
{
	//升序 --建大堆；  降序 --键小堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDwon(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		--end;
	}
}

// 冒泡排序
void BubbleSort(int* a, int n) 
{
	for (int end = n; end > 0; end--)
	{
		int exchange = 0;
		for (int i = 1; i < end; i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange == 0)
			break;
	}
}



// 快速排序递归实现
// 快速排序hoare版本
int PartSort1(int* a, int left, int right) 
{

	return 0;
}

// 快速排序挖坑法
int PartSort2(int* a, int left, int right) 
{

	return 0;
}

// 快速排序前后指针法
int PartSort3(int* a, int left, int right) 
{
	return 0;
}

void QuickSort(int* a, int n) 
{
	int left = 0;
	int right = n - 1;
	int key = a[0];
	while (left != right)
	{
		if (a[right] >= key)
		{
			--right;
		}
		if (a[left] <= key)
		{
			++left;
		}
		Swap(&a[left], &a[right]);

	}
}

// 快速排序 非递归实现
void QuickSortNonR(int* a, int left, int right) 
{

}

// 归并排序递归实现
void MergeSort(int* a, int n) 
{}

// 归并排序非递归实现
void MergeSortNonR(int* a, int n) 
{}

// 计数排序
void CountSort(int* a, int n) 
{}

// 测试排序的性能对比
/*void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int)*N);
	int* a2 = (int*)malloc(sizeof(int)*N);
	int* a3 = (int*)malloc(sizeof(int)*N);
	int* a4 = (int*)malloc(sizeof(int)*N);
	int* a5 = (int*)malloc(sizeof(int)*N);
	int* a6 = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; ++i)
	{
		a1[i] = rand();
		a2[i] = a1[i];
		a3[i] = a1[i];
		a4[i] = a1[i];
		a5[i] = a1[i];
		a6[i] = a1[i];
	}
	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();
	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();
	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();
	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();
	int begin5 = clock();
	QuickSort(a5, 0, N - 1);
	int end5 = clock();
	int begin6 = clock();
	MergeSort(a6, N);
	int end6 = clock();
	printf("InsertSort:%d\n", end1 - begin1);
	printf("ShellSort:%d\n", end2 - begin2);
	printf("SelectSort:%d\n", end3 - begin3);
	printf("HeapSort:%d\n", end4 - begin4);
	printf("QuickSort:%d\n", end5 - begin5);
	printf("MergeSort:%d\n", end6 - begin6);
	free(a1);
	free(a2);
	free(a3);
	free(a4);
	free(a5);
	free(a6);
}*/

void test()
{
	int a[] = { 5,2,7,8,6,9,4,3,1 };
	BubbleSort(a, 9);

	for (const auto& e : a)
	{
		cout << e << endl;
	}
}
int main()
{
	test();
	return 0;
}