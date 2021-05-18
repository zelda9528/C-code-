#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

void check_sys1()
{
	int a = 1;
	char* b = (char*)&a;
	if (*b == 1)
		cout << "小端" << endl;
	if (*b == 0)
		cout << "大端" << endl;
}
void check_sys2()
{
	//联合类型的所有数据共用一块内存，内存大小根据最大的数据类型决定
	union UN {
		int a;
		char b;
	}u;
	u.a = 1;
	if(u.b==1)
		cout << "小端" << endl;
	if(u.b==0)
		cout << "大端" << endl;
}
int main()
{
	check_sys1();
	check_sys2();
	return 0;
}