#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef int Datatype;



//结点
typedef struct Listnode {
	Datatype data;
	struct Listnode*prev;
	struct Listnode*next;
}Listnode;

//双向带头循环链表
typedef struct List {
	struct Listnode*head;
 }List;


void Listinsert(struct Listnode* node, Datatype val);
void Listerase(Listnode*node);


//初始化
void Init(List* lst)
{
	//构建循环结构
	//创建头结点
	lst->head = (Listnode*)malloc(sizeof(struct Listnode));
	//循环
	lst->head->prev = lst->head->next = lst->head;
}


//创建新结点
struct Listnode*Creatnode(Datatype val)
{
	struct Listnode*node = (struct Listnode*)malloc(sizeof(struct Listnode));
	node->data = val;
	node->next = node->prev = NULL;
	return node;
}

//尾插
void Pushback(List*lst, Datatype val)
{
	////当前尾结点
	//Listnode*tail = lst->head->prev;
	//Listnode*newnode = Creatnode(val);

	////插入
	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = lst->head;
	//lst->head->prev = newnode;

	Listinsert(lst->head, val);

}

//尾删
void Popback(List*lst)
{
	if (lst->head->next == lst->head)
		return;
	////找尾结点
	//struct Listnode*tail = lst->head->prev;
	////删除
	//lst->head->prev = tail->prev;
	//lst->head->prev->next = lst->head;
	//free(tail);

	Listerase(lst->head->prev);
}

//打印链表
void Print(List*lst)
{
	struct Listnode*cur = lst->head->next;
	while (cur != lst->head)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//头插
void Pushfront(List*lst, Datatype val)
{
	//struct Listnode*newnode = Creatnode(val);
	//struct Listnode*next = lst->head->next;

	//lst->head->next = newnode;
	//newnode->prev = lst->head;
	//next->prev = newnode;
	//newnode->next = next;

	Listinsert(lst->head->next, val);
}


//头删
void Popfront(List* lst)
{
	if (lst->head->next == lst->head)
		return;
	//struct Listnode* next = lst->head->next->next;

	//lst->head->next = next;
	//next->prev = lst->head;

	Listerase(lst->head->next);
}

//查询
struct Listnode *Find(List* lst, Datatype val)
{
	if (lst->head->next == lst->head)
		return NULL;
	struct Listnode*cur = lst->head->next;
	while (cur != lst->head&&cur->data != val)
	{
		cur = cur->next;	
	}
	return cur;
}


//任意结点之前插入
void Listinsert(struct Listnode* node, Datatype val)
{
	struct Listnode*newnode = Creatnode(val);
	struct Listnode*prev = node->prev;

	newnode->next = node;
	node->prev = newnode;
	prev->next = newnode;
	newnode->prev = prev;
}

//删除任意一个结点
void Listerase( Listnode*node)
{
	struct Listnode*next = node->next;
	struct Listnode*prev = node->prev;

	prev->next = next;
	next->prev = prev;
	free(node);
}


//销毁链表
void Destory(List*lst)
{
	struct Listnode*cur = lst->head->next;
	while (cur != lst->head)
	{
		free(cur);
		cur = cur->next;
	}
	free(lst->head);
}

//
void test()
{
	struct List lst;
	Init(&lst);
	//尾插
	Pushback(&lst, 1);
	Pushback(&lst, 2);
	Pushback(&lst, 3);
	Pushback(&lst, 4);
	Pushback(&lst, 5);
	Print(&lst);

	//头插
	Pushfront(&lst, 0);
	Pushfront(&lst, 0);
	Pushfront(&lst, 0);
	Print(&lst);

	//尾删
	Popback(&lst);
	//头删
	Popfront(&lst);
	Popfront(&lst);
	Popfront(&lst);


	Print(&lst);

}

int main()
{
	test();
	return 0;
}