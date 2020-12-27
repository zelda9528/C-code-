#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
typedef int stdatatype;

typedef struct stack {
	stdatatype* data;
	int size;
	int capacity;
}stack;

//初始化
void Initstack(stack* st)
{
	if (st == NULL)
		return;
	st->data = NULL;
	st->capacity = st->size = 0;
}

//检查容量
void Checkcapacity(stack*st)
{
	if (st->size == st->capacity)
	{
		int newcapacity=st->capacity == 0 ? 1 : 2 * st->capacity;
		st->data = (stdatatype*)realloc(st->data, sizeof(stdatatype)*newcapacity);
		st->capacity = newcapacity;
	}
}

//入栈
void Stackpush(stack* st, stdatatype val)
{
	if (st == NULL)
		return;
	Checkcapacity(st);
	st->data[st->size++] = val;
}

//出栈
void Stackpop(stack* st)
{
	if (st == NULL||st->size==0)
		return;
	st->size--;
}

//获取栈中元素个数
int Satcksize(stack* st)
{
	if (st == NULL)
		return 0;
	return st->size;
}

//判断栈空
int Emptystack(stack*st)
{
	if (st == NULL || st->size == 0)
		return 1;
	else
		return 0;
}

//获取栈顶元素
stdatatype Stacktop(stack* st)
{
	return st->data[st->size - 1];
}

//销毁栈
void Destorystack(stack*st)
{
	free(st->data);
	st->data = NULL;
	st->size = 0;
	st->capacity = 0;
}

void test()
{
	stack st;
	Initstack(&st);
	Stackpush(&st, 1);
	Stackpush(&st, 2);
	Stackpush(&st, 3);
	Stackpush(&st, 4);
	Stackpush(&st, 5);

	while (!Emptystack(&st))
	{
		printf("%d ", Stacktop(&st));
		Stackpop(&st);
	}
	printf("\n");

}


int main()
{
	test();
	return 0;
}

