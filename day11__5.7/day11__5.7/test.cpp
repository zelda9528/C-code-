#define _CRT_SECURE_NO_WARNINGS 1


//1.满二叉树的最近公共祖先
class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		while (a != b)
		{
			if (a > b)
				a /= 2;
			else
				b /= 2;
		}
		return a;
	}
};

//2. 二进制数字最大连续1的个数
#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{ 
		int maxcount = 0;
		int count = 0;
		while (n)
		{
			if ((n & 1) == 1)
				count++;
			else
			{
				if (count > maxcount)
					maxcount = count;
				count = 0;
			}
			n >>= 1;
		}
		if (count > maxcount)
			maxcount = count;
		cout << maxcount << endl;
	}
	return 0;
}