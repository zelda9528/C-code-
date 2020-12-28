//队列

#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>


typedef int Qdatatype;
typedef struct Qnode {
	Qdatatype data;
	struct Qnode* next;
}Qnode;

typedef struct Queue {
	
	//头尾指针
	struct Qnode*head;
	struct Qnode*tail;

}Queue;


//初始化
void Init(Queue* q)
{
	if (q == NULL)
		return;
	q->head = q->tail = NULL;

}

//创建新结点
struct Qnode* creatnode(Qdatatype val)
{
	struct Qnode* node = (struct Qnode*)malloc(sizeof(struct Qnode));
	node->data = val;
	node->next = NULL;
	return node;
}

//入队-尾插
void Queuepush(Queue* q,Qdatatype val)
{
	if (q == NULL)
		return;
	// 尾插
	struct Qnode*node = creatnode(val);
	if (q->head == NULL)
		q->head = q->tail = node;
	else
	{
		q->tail->next = node;
		q->tail = node;
	}
}

//出队-头删
void Queuepop(Queue* q)
{
	if (q == NULL||q->head==NULL)
		return;
	//头删
	struct Qnode* next = q->head->next;
	free(q->head); 
	q->head = next;
	//若该队列只有一个结点，尾指针需要置空
	if (q->head == NULL)
		q->tail = NULL;
}

//获取队首元素
Qdatatype Queuefront(Queue* q)
{
	return q->head->data;
}

//队尾元素
Qdatatype Queueback(Queue* q)
{
	return q->tail->data;
}

//判断队列是否为空
int Queueempty(Queue* q)
{
	if (q->head == NULL)
		return 1;
	else
		return 0;
}

void test()
{
	Queue q;
	Init(&q);
	Queuepush(&q, 1);
	Queuepush(&q, 2);
	Queuepush(&q, 3);
	Queuepush(&q, 4);
	Queuepush(&q, 5);
	Queuepush(&q, 6);
	Queuepush(&q, 7);
	Queuepush(&q, 8);

	while (!Queueempty(&q))
	{
		printf("%d ", Queuefront(&q));
		Queuepop(&q);
	}
	printf("\n");

}
int main()
{
	test();
	return 0;
}