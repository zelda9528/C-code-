#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
int ans;
//原则：先跑后休息 
int main()
{
	int x = 10000;
	while (x)
	{
		//如果我还能跑全程， 那就跑 
		if (x - 600 >= 0)
		{
			ans = ans + 60 * 2;
			x = x - 600 + 300;
		}
		else
		{//如果我跑不了全程，那就跑多少算多少 。体力的损耗和增加都是均匀变化 
			ans = ans + 0.1*x;
			x = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
