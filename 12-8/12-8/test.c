#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int slDatatype;//顺序表内的数据类型（便于维护）

//动态顺序表
typedef struct seqList 
{
	slDatatype *data;  //数组指针
	int size;           //有效元素个数
	int capacity;       //数组内存空间

} seqList;

//初始化顺序表
void Init(seqList* sl)//形参为结构体指针
{
	sl->data = NULL;
	sl->size = 0;
	sl->capacity = 0;
}


//检查容量及扩容
void Checkcapacity(seqList*sl)
{
	if (sl->size == sl->capacity)
	{
		//开辟新空间
		int newCapacity = sl->capacity == 0 ? 1 : 2 * sizeof(sl->capacity);
		slDatatype * tmp = (slDatatype*)malloc(newCapacity*sizeof(slDatatype));

		//拷贝数据
		memcpy(tmp, sl->data, sizeof(slDatatype)*sl->size);

		//释放原有空间
		free(sl->data);
		sl->data = tmp;

	//若使用realloc动态开辟空间————可替换35-42行
		//sl->data = (seqList*)ralloc(sl->data, newCapacity * sizeof(slDatatype));

		//更新容量
		sl->capacity = newCapacity;

	}
}

//打印顺序表
void Listprint(seqList*sl)
{
	if (sl == NULL)
		return;
	for (int i = 0; i < sl->size; i++)
	{
		printf("%d ", sl->data[i]);
	}
	printf("\n");
}

//尾插
void Pushback(seqList* sl,slDatatype val)
{
	if (sl == NULL)
		return;

	Checkcapacity(sl);

	sl->data[sl->size] = val;
	sl->size++;
}

//尾删
void Popback(seqList* sl)
{
	if (sl == NULL||sl->size==0)
		return;
	if (sl->size > 0)
		sl->size--;
}


//头插
void Pushfront(seqList*sl,slDatatype val)
{
	if (sl == NULL)
		return;

	//检查容量
	Checkcapacity(sl);
    
	//移动元素--从后向前
	int end = sl->size;
	while (end > 0)
	{
		sl->data[end] = sl->data[end - 1];
		--end;
	}

	//插入元素
	sl->data[0] = val;
	sl->size++;
}


//头删
void Popfront(seqList* sl)
{
	if (sl == NULL||sl->size==0)
		return;
	
	//从前向后移动元素
	for (int i = 0; i < sl->size; i++)
	{
		sl->data[i] = sl->data[i + 1];
	}

	//更新size
	sl->size--;
}

//任意位置插入元素
void Insert(seqList*sl, int pos, slDatatype val)
{
	if (sl == NULL)
		return;
	Checkcapacity(sl);
	if (pos >= 0 && pos <= sl->size)
	{
		//移动数据
		int end = sl->size;
		while (end > pos)
		{
			sl->data[end] = sl->data[end - 1];
			end--;
		}
		//插入数据
		sl->data[pos] = val;
		sl->size++;
	}
}

//删除任意位置数据
void Erase(seqList*sl, int pos)
{
	if (sl == NULL || sl->size == 0)
		return;
	if (pos >= 0 && pos < sl->size)
	{
		while (pos<sl->size)
		{
			sl->data[pos] = sl->data[pos+1];
			pos++;
		}
		sl->size--;
	}
}

//测试模块
void test()
{
	seqList sl;
	Init(&sl);
	Pushback(&sl, 1);
	Pushback(&sl, 2);
	Pushback(&sl, 3);
	Pushback(&sl, 4);

	Erase(&sl, 1);
	Listprint(&sl);


}

//销毁顺序表
void Destroy(seqList* sl)
{
	if (sl != NULL && sl->data != NULL)
	{
		free(sl->data);
		sl->data = NULL;
	}
}


int main()
{
	test();
	return 0;
}