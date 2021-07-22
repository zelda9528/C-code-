#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

//1. 查找类杨辉三角形指定行的第一个偶数位置
int Findindex(int n)
{
	//先产生n行的类杨辉三角
	int m = 2 * n - 1;    //第n行的元素个数
	vector<vector<int>> ivv(n, vector<int>(m, 0));
	ivv[0][0] = 1;
	for (int i = 1; i < n; i++)
	{
		ivv[i][0] = ivv[i][2 * i] = 1;    //第一列和倒数第一列固定为1
		for (int j = 1; j < 2 * i; j++)
		{
			if (j == 1)    //第二列
				ivv[i][j] = ivv[i - 1][j - 1] + ivv[i - 1][j];
			else if (j == 2 * i - 1)//倒数第二列
				ivv[i][j] = ivv[i - 1][j - 2] + ivv[i - 1][j - 1];
			else
				ivv[i][j] = ivv[i - 1][j - 2] + ivv[i - 1][j - 1] + ivv[i - 1][j];
		}
	}
	//查询第n行的偶数所在的位置
	for (int k = 0; k < m; k++)
	{
		if (ivv[n - 1][k] % 2 == 0)
			return k + 1;
	}
	return -1;
}


int Findindex_1(int n)
{
	if (n <= 2)
		return -1;
	else if (n % 2 == 1)
		return 2;
	else if (n % 4 == 0)
		return 3;
	else
		return 4;
}


int main()
{
	int n, index;
	while (cin >> n)
	{
		index = Findindex(n);
		cout << index << endl;
	}
	return 0;
}


//镜像二叉树
//class Solution {
//public:
//	/**
//	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
//	 *
//	 *
//	 * @param pRoot TreeNode类
//	 * @return TreeNode类
//	 */
//	TreeNode* Mirror(TreeNode* pRoot) {
//		// write code here
//		if (pRoot == nullptr)
//			return nullptr;
//		TreeNode* tmp = pRoot->left;
//		pRoot->left = pRoot->right;
//		pRoot->right = tmp;
//		Mirror(pRoot->left);
//		Mirror(pRoot->right);
//		return pRoot;
//	}
//};