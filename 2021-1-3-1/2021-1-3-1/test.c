#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//向下调整算法---以最小堆为例
void Shift_down(int *arr, int n, int curpos) //n-数组大小   curpos-需要调整的位置
{
	//左孩子
	int child = 2 * curpos + 1;
	while (child < n)
	{
		if (child + 1 < n&&arr[child + 1] < arr[child])
			child++;
		//向下比较
		if (arr[child] < arr[curpos])
		{
			int tmp = arr[child];
			arr[child] = arr[curpos];
			arr[curpos] = tmp;

			//继续向下比较
			curpos = child;
			child = 2 * curpos + 1;
		}
		else
			break;
	}

}

void Creat_heap(int *arr, int n)
{
	for (int i = 0; i < (n - 2) / 2; i++)
	{
		Shift_down(arr, n, i);
	}
}

void test()
{
	int arr[] = { 100,20,3,6,89,12,15,36,25 };
	Creat_heap(arr,sizeof(arr)/sizeof(arr[0]));
}

int main()
{
	test();
	return 0;
}

