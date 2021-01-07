#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

////创建空树
//void Creat_tree(BTree* bt)
//{
//	bt->root = NULL;
//}

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
int BTreeKsize(Node* root,int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BTreeKsize(root->left,k-1)+BTreeKsize(root->right,k-1);
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
	printf("第%d层的节点个数：%d \n",4, BTreeKsize(root,4));

}

int main()
{
	test();
	return 0;
}






