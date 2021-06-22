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

// ��������
void InsertSort(int* a, int n)
{	
	for (int i = 0; i < n - 1; i++)
	{
		//��tmp���뵽[0,end]�����������
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

// ϣ������
void ShellSort(int* a, int n) 
{
	int gap=n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;// +1 ---- ��֤���һ��gap=1

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

// ѡ������
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
		//���������
		if (left == max)
		{
			max = min;
		}
		swap(a[max], a[right]);
		left++;
		right--;
	}
}

// ������
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
	//���� --����ѣ�  ���� --��С��
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

// ð������
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


//����ȡ��
int GetMidIndex(int *a, int left, int right)
{
	int mid = (left + right) >> 1;
	//left       mid       right
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if(a[right]>a[left])
		{
			return right;
		}
		else
		{
			return left;
		}
	}
	else      //a[mid] < a[left]
	{
		if (a[right] > a[left])
		{
			return left;
		}
		else if (a[right] > a[mid])
		{
			return right;
		}
		else
		{
			return mid;
		}
	}
}
// ��������ݹ�ʵ��
// ��������hoare�汾
int PartSort1(int* a, int left, int right) 
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);
	int keyi = left;
	while (left < right)
	{
		while (left < right&&a[right] >= a[keyi])
		{
			--right;
		}
		while (left < right&&a[left] <= a[keyi])
		{
			++left;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);
	return left;
}

// ���������ڿӷ�
int PartSort2(int* a, int left, int right) 
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);
	int key = a[left];	//��������ڿ�
	while (left < right)
	{
		////�ұ���С
		while (left < right&&a[right] >= key)
			--right;
		//�ŵ���ߵĿ�λ,�ұ��γ��µĿ�
		a[left] = a[right]; 
		//����Ҵ�
		while (left < right&&a[left] <= key)
			++left;
		//�ŵ��ұߵĿ�λ������γ��µĿ�
		a[right] = a[left];
	}
	a[left] = key;
	return left;
}

// ��������ǰ��ָ�뷨
int PartSort3(int* a, int left, int right) 
{
	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);
	int prev = left;
	int cur = prev + 1;
	int keyi = left;		//��׼ֵ������
	while (cur <= right)
	{
		if (a[cur] <= a[keyi] && ++prev!= cur)
		{
			Swap(&a[cur],&a[prev]);
		}
		++cur;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}




void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
		return;
	int key = PartSort1(a, begin, end);

	//[begin,key-1]  [key+1,end]
	QuickSort(a, begin, key - 1);
	QuickSort(a, key + 1, end);
}

// �������� �ǵݹ�ʵ��
void QuickSortNonR(int* a, int left, int right) 
{

}

// �鲢����ݹ�ʵ��
void MergeSort(int* a, int n) 
{

}

// �鲢����ǵݹ�ʵ��
void MergeSortNonR(int* a, int n) 
{}

// ��������
void CountSort(int* a, int n) 
{}

// ������������ܶԱ�
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
	//int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
	QuickSort(a, 0, sizeof(a)/sizeof(a[0])-1);

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