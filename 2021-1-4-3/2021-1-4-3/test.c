
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int datatype;
typedef struct heap
{
	datatype* data;
	int size;
	int capacity;
}heap;

//初始化堆
void Heap_init(heap*hp)
{
	if (hp == NULL)
		return;
	hp->data = NULL;
	hp->size = hp->capacity = 0;
}

//检查容量
void Check_capacity(heap* hp)
{
	if (hp->size == hp->capacity)
	{
		//更新容量
		hp->capacity = hp->capacity == 0 ? 1 : 2 * hp->capacity;
		//动态开辟新的空间 
		hp->data = (datatype *)realloc(hp->data, sizeof(datatype)*hp->capacity);
	}
}

//向下调整算法
void Shift_down(int *arr, int n, int curpos) //n-数组大小   curpos-需要调整的位置
{
	//左孩子
	int child = 2 * curpos + 1;
	while (child < n)
	{
		if (child + 1 < n&&arr[child + 1] > arr[child])
			child++;
		//向下比较
		if (arr[child] > arr[curpos])
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


//向上调整算法
void Shift_up(int* arr, int n, int curpos)
{
	//父节点的位置
	int parent = (curpos - 1) / 2;
	while (curpos > 0)
	{
		//和父节点比较
		if (arr[curpos] > arr[parent])
		{
			int tmp = arr[curpos];
			arr[curpos] = arr[parent];
			arr[parent] = tmp;

			//更新位置
			curpos = parent;
			parent = (curpos - 1) / 2;
		}
		else
			break;		//结束调整
	}
}


//堆的插入
void Heap_push(heap* hp, datatype val)
{
	//检查容量
	Check_capacity(hp);
	//尾插
	hp->data[hp->size++] = val;

	//向上调整
	Shift_up(hp->data, hp->size, hp->size - 1);
}




//交换函数
void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//堆的删除
void Heap_pop(heap*hp)
{
	if (hp == NULL || hp->size == 0)
		return;
	//交换
	Swap(&hp->data[0], &hp->data[hp->size - 1]);
	//尾删
	hp->size--;
	//向下调整
	Shift_down(hp->data, hp->size, 0);
}

//判断堆空
int Heap_empty(heap*hp)
{
	if (hp == NULL || hp->size == 0)
		return 1;
	else
		return 0;
}

//获取堆顶元素
datatype Heap_top(heap*hp)
{
	return hp->data[0];
}

//创建堆
void Creat_heap(int *arr, int n)
{
	for (int i = 0; i < (n - 2) / 2; i++)
	{
		Shift_down(arr, n, i);
	}
}

//Top-K
void printTopK(int *a,int n,int k)
{
	heap hp;
	Heap_init(&hp);
	for (int i = 0; i < n; ++i)
	{
		Heap_push(&hp, a[i]);
	}
	while (k--)
	{
		printf("%d ", Heap_top(&hp));
		Heap_pop(&hp);
	}
	printf("\n");
}

//实现数组排序
void HeapSort(int* arr, int n)
{
	//建堆
	Creat_heap(arr, n);
	int end = n - 1;
	while (end > 0)
	{
		//堆删除
		
		int tmp = arr[0];
		arr[0] = arr[end];
		arr[end] = tmp;

		Shift_down(arr, end, 0);
		end--;
	}

}
void testHeapSort()
{
	int arr[] = {20,17,4,16,5,3};
	int n = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void test()
{
	//heap hp;
	//Heap_init(&hp);
	//Heap_push(&hp, 28);
	//Heap_push(&hp, 29);
	//Heap_push(&hp, 45);
	//Heap_push(&hp, 46);
	//Heap_push(&hp, 25);
	//Heap_push(&hp, 38);
	//Heap_push(&hp, 19);
	//Heap_push(&hp, 8);

	//Heap_pop(&hp);
	//Heap_pop(&hp);
	//Heap_pop(&hp);
	//Heap_pop(&hp);

	//while (!Heap_empty(&hp))
	//{
	//	printf("%d ", Heap_top(&hp));
	//	Heap_pop(&hp);
	//}
	//printf("\n");
}

//void testTopK()
//{
//
//	int n = 10000;
//	int *a = (int *)malloc(sizeof(int)*n);
//	for (size_t i = 0; i < n; i++)
//	{
//		a[i] = rand() % 1000000;
//	}
//	a[5] = 1000000 + 1;
//	a[1231] = 1000000 + 2;
//	a[531] = 1000000 + 3;
//	a[5121] = 1000000 + 4;
//	a[115] = 1000000 + 5;
//	a[2335] = 1000000 + 6;
//	a[9999] = 1000000 + 7;
//	a[76] = 1000000 + 8;
//	a[423] = 1000000 + 9;
//	a[3144] = 1000000 + 10;
//	printTopK(a, n, 10);
//}

int main()
{
	testHeapSort();

	
	return 0;

}

