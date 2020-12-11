#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef int ldatatype;

//定义结点：数据+指针
typedef struct listnode
{
	ldatatype data;
	struct listnode* next;

}listnode;

//定义链表
typedef struct list
{
	//头结点的地址
	listnode* head;
}list;

//初始化链表
void initlist (list*lst)
{
	if (lst == NULL)
		return;
	lst->head = NULL;
}


//创建结点
listnode* creat_listnode(ldatatype val)
{
	listnode* node = (listnode*)malloc(sizeof(listnode));
	node->data = val;
	node->next = NULL;
	return node;
}


//尾插
void pushback(list* lst, ldatatype val)
{
	if (lst == NULL)
		return;
	if (lst->head == NULL)
	{
		lst->head = creat_listnode(val);
	}
	else
	{    
		//遍历找到最后一个结点
		listnode* tail = lst->head;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = creat_listnode(val);
	}

}

//尾删
void popback(list* lst)
{
	if (lst == NULL)
		return;
	//遍历，找最后一个结点
	listnode*pre = NULL;
	listnode*tail = lst->head;
	while (tail->next != NULL)
	{
		pre = tail;
		tail = tail->next;
	}
	//释放最后一个结点
	free(tail);
	//尾部置空

	if (pre == NULL)//如果该链表只有一个结点
		lst->head = NULL;
	else
	pre->next = NULL;
}

//头插
void pushfront(list*lst, ldatatype val)
{
	if (lst == NULL)
		return;
	//创建新节点
	listnode* node = creat_listnode(val);
	//插入
	node->next = lst->head;
	lst->head = node;
}

//头删
void popfront(list*lst)
{
	if (lst == NULL || lst->head == NULL)
		return;
	listnode*next = lst->head->next;
	//释放空间
	free(lst->head);
	//更新head指针 
	lst->head = next;
}


//在任意位置的后面插入元素
void insert_after(listnode*node, ldatatype val)
{
	if (node == NULL)
		return;
	listnode*newnode = creat_listnode(val);
	listnode*next = node->next;
	node->next = newnode;
	newnode->next = next;
}

//删除某一结点的下一个结点
void erase_after(listnode* node)
{
	if (node == NULL || node->next == NULL)
		return;
	listnode*next = node->next;
	listnode*nextnext = next->next;

	free(next);
	node->next = nextnext;
}


//查找
listnode* find(list*lst,ldatatype val)
{
	if (lst == NULL || lst->head == NULL)
		return NULL;
	listnode*pos = lst->head;
	while (pos)
	{
		if (pos->data == val)
			return pos;
		else
			pos = pos->next;
	}
	return NULL;

}

//销毁所有结点
void destory(list* lst)
{
	if (lst == NULL||lst->head==NULL)
		return;
	listnode*pos = lst->head;
	listnode*next = pos->next;

	while (pos)
	{
		free(pos);
		pos = next;
		next = next->next;
	}
}



int main()
{
	list lst;
	initlist(&lst);
	pushfront(&lst, 5);
	pushfront(&lst, 4);
	pushfront(&lst, 3);
	pushfront(&lst, 2);
	pushfront(&lst, 1);


	pushback(&lst, 0);
	pushback(&lst, 0);
	pushback(&lst, 0);
	pushback(&lst, 0);
    
	return 0;
}