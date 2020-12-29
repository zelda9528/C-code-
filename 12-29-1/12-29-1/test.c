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
		int newcapacity = st->capacity == 0 ? 1 : 2 * st->capacity;
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
	if (st == NULL || st->size == 0)
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

bool isValid(char * s) {
	char map[3][2] = { {'(',')'},{'[',']'},{'{','}'} };
	struct stack st;
	Initstack(&st);
	while (*s)
	{
		int flag = 0;
		//左括号-入栈
		for (int i = 0; i < 3; i++)
		{
			if (*s == map[i][0])
			{
				Stackpush(&st, *s);
				//判断下一个字符
				++s;
				flag = 1;
				break;
			}
		}
		//右括号-匹配
		if (flag == 0)
		{
			if (Emptystack(&st))
				return false;
			//取出栈顶元素
			char topchar = Stacktop(&st);
			Stackpop(&st);
			for (int i = 0; i < 3; i++)
			{
				if (map[i][1] == *s)
				{
					if (topchar == map[i][0])
					{
						++s;
						break;
					}
					else
					{
						return false;//不匹配
					}
				}
			}
		}
	}
	//若栈为空 表示完全闭合
	return Emptystack(&st);
}