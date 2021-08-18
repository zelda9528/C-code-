#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stack>
using namespace std;


// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int end = n; end > 0; end--)
	{
		//int exchange = 0;
		for (int i = 1; i < end; i++)
		{
			if (a[i - 1] > a[i])
			{
				swap(a[i - 1], a[i]);
				//exchange = 1;
			}
		}
		/*if (exchange == 0)
			break;*/
	}
}

//堆排序
void ShiftDown(int *a,int n,int root)
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child < n)
	{
		if (child + 1 < n&&a[child + 1] > a[child])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}
void HeapSort(int *a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; i--)
		ShiftDown(a, n, i);
	int end = n - 1;
	while (end > 0)
	{
		swap(a[end], a[0]);
		ShiftDown(a, end, 0);
		end--;
	}
}

//选择排序
void SelectSort(int *a, int n)
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int min = left, max = left;
		for (int i = left; i <= right; i++)
		{
			if (a[i] < a[min])
				min = i;
			if (a[i] > a[max])
				max = i;		
		}
		swap(a[left], a[min]);
		if (left == max)
		{
			max = min;
		}
		swap(a[right], a[max]);
		left++;
		right--;
	}
}


//直接插入排序
void InsertSort(int *a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
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
				break;
		}
		a[end + 1] = tmp;
	}
}

//希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end-=gap;
				}
				else
					break;
				a[end + gap] = tmp;
			}
		}
	}
}


//快速排序
//hoare法
int PartSort1(int* a, int begin, int end)
{
	int left = begin;
	int right = end;
	int key = left;
	while (left < right)
	{
		while (left < right&&a[right] >= a[key])
			--right;
		while (left < right&&a[left] <= a[key])
			++left;
		swap(a[left], a[right]);
	}
	swap(a[key],a[left]);
	return left;
}

int PartSort2(int* a, int left, int right)
{
	int key = a[left];	//挖坑
	while (left < right)
	{
		//右边找小
		while (left < right&&a[right] >= key)
			--right;
		//放到左边的坑位,右边形成新的坑
		a[left] = a[right];
		//左边找大
		while (left < right&&a[left] <= key)
			++left;
		//放到右边的坑位，左边形成新的坑
		a[right] = a[left];
	}
	a[left] = key;
	return left;
}

stack<int> st;
void QuickSortNOR(int *a,int begin,int end)
{
	st.push(begin);
	st.push(end);
	while (!st.empty())
	{
		int left, right;
		right = st.top();
		st.pop();

		left = st.top();
		st.pop();

		int keyi = PartSort1(a,	left, right);
		if (left < keyi-1)
		{
			st.push(left);
			st.push(keyi-1);
		}
		if (keyi+1 < right)
		{
			st.push(keyi + 1);
			st.push(right);
		}
	}
}

void QuickSort(int* a, int begin, int end)
{
	if (end <= begin)
		return;
	int key = PartSort1(a, begin, end);

	QuickSort(a,begin,key-1);
	QuickSort(a, key+1, end);
}

//归并排序
void _MergeSort(int *a, int left,int right,int* tmp)
{
	if (left >= right)
		return;

	int mid = (left + right) >> 1;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid+1, right, tmp);

	//两队有序子区间归并到tmp，然后拷贝回去
	int begin1 = left, end1 = mid;
	int begin2 = mid+1, end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[i++] = a[begin1++];
		else
			tmp[i++] = a[begin2++];
	}
	while (begin1 <= end1)
		tmp[i++] = a[begin1++];
	while (begin2 <= end2)
		tmp[i++] = a[begin2++];

	//归并完成后，拷贝回原数组
	for (int j = left; j < right; j++)
		a[j] = tmp[j];
}

void MergeSort(int *a, int n)
{
	int* tmp = (int*)malloc(n*(sizeof(int)));
	if (tmp == NULL)
	{
		printf("malloc error!\n");
		exit(-1);
	}
	_MergeSort(a, 0, n - 1,tmp);
	free(tmp);
}


int main()
{
	int a[] = {0,3,9,1,7,2,8,4,6,5};
	MergeSort(a,10);
	for (int i = 0; i < 10; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}