#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
void Queueinit(Queue* q)
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
void Queuepush(Queue* q, Qdatatype val)
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
	if (q == NULL || q->head == NULL)
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

//队列大小
int Queuesize(Queue* q)
{
	int n = 0;
	struct Qnode*p = q->head;
	while (p)
	{
		++n;
		p = p->next;
	}
	return n;
}



typedef char datatype;


//二叉树的结点   二叉链
typedef struct BinaryTreeNode
{
	struct Node* left;
	struct Node* right;
	datatype data;
}Node;


typedef struct BTree
{
	//二叉树根节点
	Node* root;
}BTree;


//创建二叉树，返回根节点
Node* Creattree(datatype arr[], int* idx)
{
	if (arr[*idx] == '#')
	{
		(*idx)++;
		return NULL;
	}
	//当前树的根节点
	Node* root = (Node*)malloc(sizeof(Node));
	root->data = arr[*idx];
	(*idx)++;
	//创建左右子树
	root->left = Creattree(arr, idx);
	root->right = Creattree(arr, idx);
	return root;
}


//前序遍历
void preorder(Node* root)
{
	if (root)
	{
		//前序：根->左->右
		printf("%c ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}


//中序遍历
void inorder(Node* root)
{
	if (root)
	{
		//中序：左->根->右
		inorder(root->left);
		printf("%c ", root->data);
		inorder(root->right);
	}
}

//后序遍历
void postorder(Node* root)
{
	if (root)
	{
		//后序：左->右->根
		postorder(root->left);
		postorder(root->right);
		printf("%c ", root->data);
	}
}

//二叉树结点个数
int BTreeSize(Node* root)
{
	if (root == NULL)
		return 0;
	return BTreeSize(root->left) + BTreeSize(root->right) + 1;
}


//树的高度
int BTreeHigh(Node* root)
{
	if (root == NULL)
		return 0;
	//树的高度=（左右子树中较大的度）+1
	int left = BTreeHigh(root->left);
	int right = BTreeHigh(root->right);
	return left > right ? left + 1 : right + 1;
}


//二叉树叶子节点的个数
int BTreeLeaf(Node* root)
{
	//空树
	if (root == NULL)
		return 0;
	//该树只有一个结点
	if (root->left == NULL && root->right == NULL)
		return 1;
	//一般情况
	return BTreeLeaf(root->left) + BTreeLeaf(root->right);
}

//第K层结点个数=左右子树第k-1层节点个数的和   根为第一层
int BTreeKsize(Node* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BTreeKsize(root->left, k - 1) + BTreeKsize(root->right, k - 1);
}


//二叉树查找
Node* BTreeFind(Node* root, datatype ch)
{
	if (root)
	{
		if (root->data == ch)
			return root;
		Node* node = BTreeFind(root->left, ch);
		if (node)
			return node;
		else
			return BTreeFind(root->right, ch);
	}
	else
		return NULL;
}


//销毁二叉树
void DestoryBTree(Node* root)
{
	if (root)
	{
		DestoryBTree(root->left);
		DestoryBTree(root->right);
		free(root);
		root = NULL;
	}
}

//借助队列实现二叉树的层序遍历
void LevelOrder(Node* root)
{
	//用队列实现层序遍历
	Queue q;
	//初始化队列
	Queueinit(&q);

	//根节点入队
	Queuepush(&q, root);
	
	//遍历每一个结点
	while (!Queueempty(&q))
	{
		Node* front = Queuefront(&q);
		printf("%c ", front->data);
		Queuepop(&q);
		//左右子树入队
		if (front->left)
			Queuepush(&q, front->left);
		if (front->right)
				Queuepush(&q, front->right);
	}
	printf("\n");
}

//判断是否为完全二叉树
//完全二叉树的性质：其层序遍历是连续的，不会在出现NULL之后又出现非空结点
int IscompleteBTree(Node* root)
{
	Queue q;
	Queueinit(&q);
	if (root)
		Queuepush(&q, root);
	while (!Queueempty(&q))
	{
		Node* front = Queuefront(&q);
		Queuepop(&q);
		//左右孩子入队
		if (front)
		{
			Queuepush(&q, front->left);
			Queuepush(&q, front->right);
		}
		else
			break;
	}
	while (!Queueempty(&q))
	{
		Node* front = Queuefront(&q);
		if (front)
			//入果剩余元素中存在非空结点，则证明不是完全二叉树
			return 0;
	}
	return 1;
}
//int IscompleteBTree(Node* root)
//{
//	if (root == NULL)
//		return 0;
//	Queue q;
//	Queueinit(&q);
//
//	Queuepush(&q, root);
//	while (Queuefront(&q)!=NULL)
//	{
//		Node* front = Queuefront(&q);
//		Quuepop(&q);
//		if (front->left)
//			Queuepush(&q, front->left);
//		if (front->right)
//			Queuepush(&q, front->right);
//	}
//	while (!Queueempty(&q))
//	{
//		if (Queuefront(&q) == NULL)
//		{
//			Queuepop(&q);
//		}
//		
//	}
//
//}

void test()
{
	char arr[] = "ABD##E#H##CF##G##";
	int idx = 0;
	Node* root = Creattree(arr, &idx);
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	printf("树的结点个数：%d \n", BTreeSize(root));
	printf("树的度：%d \n", BTreeHigh(root));
	printf("叶子节点的个数：%d \n", BTreeLeaf(root));
	printf("第%d层的节点个数：%d \n", 4, BTreeKsize(root, 4));


}


int main()
{
	test();
	return 0;
}

