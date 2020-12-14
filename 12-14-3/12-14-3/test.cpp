#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
int main()
{
	int i;
	int &j = i;
	i = 30;
	cout << "i=" << i << ' ' << "j=" << j << endl;
	j = 80;
	cout << "i=" << i << ' ' << "j=" << j << endl;
	cout << "变量i的地址是：" << &i << endl;
	cout << "引用j的地址是: " << &j << endl;
	return 0;
}
