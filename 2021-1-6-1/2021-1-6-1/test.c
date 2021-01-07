#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char datatype;

//二叉树的结点   二叉链
typedef struct BinaryTreeNode 
{
	Node* left;
	Node* right;
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
Node* Creattree(datatype arr[],int* idx)
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
	printf("\n");
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
	printf("\n");
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
	printf("\n");
}

//二叉树结点个数
void BTreeSize(Node* root)
{
	if (root == NULL)
		return 0;
	return BTreeSize(root->left) + BTreeSize(root->right) + 1;
}

void test()
{
	char arr[] = "ABD##E#H##CF##G##";
	int idx = 0;
	Node* root = Creattree(arr, &idx);
	preorder(root);
	inorder(root);
}

int main()
{
	test();
	return 0;
}






