#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>

using namespace std;


//n张牌放进n个盒子，求有几种方案
void DFS(vector<int>& box,vector<int>& used,int idx)
{
	//递归的边界条件
	if (idx == box.size())
	{
		for (int i = 1; i < box.size(); i++)
		{
			cout << box[i] << " ";
		}
		cout << endl;
		return;
	}
	
	//处理当前盒子
	for (int i = 1; i < box.size(); i++)
	{
		//判断当前的牌是否用过
		if (used[i] == 0)
		{
			used[i] = 1;
			box[idx] = i;

			//处理剩余的盒子
			DFS(box, used, idx+1);

			//回收当前使用的牌
			used[i] = 0;
		}
	}
}

int main()
{
	int n = 0;
	cin >> n;
	vector<int> box(n+1, 0);
	vector<int> used(n+1, 0);

	DFS(box, used, 1);


	return 0;
}